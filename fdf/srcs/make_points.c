/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:23:59 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/14 16:43:04 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		parse_num(char **line, double z)
{
	while (ft_isdigit(**line))
	{
		z = (z * 10.0) + (**line - '0');
		(*line)++;
	}
	return (z);
}

void		parse_line(t_point *point, char *line, int y, t_map *map)
{
	int		sign;
	int		x;
	double	z;
	t_point	*p;

	x = 0.0;
	p = point;
	while ((sign = 1) && *line)
	{
		z = 0.0;
		if (*line == '-' && (sign = -1))
			line++;
		if (ft_isdigit(*line))
		{
			z = parse_num(&line, z);
			add_init_points(p, (x * map->scale), (y * map->scale), (z * sign * map->scale));
			p++;
			x++;
		}
		else
			line++;
	}
	p->end = 1;
}

t_point		**create_points(char *file, t_map *map)
{
	t_point **points;
	char	*line;
	int		fd;
	int		arr_i;

	points = (t_point**)malloc(sizeof(t_point*) * map->num_lines + sizeof(void*));
	fd = open(file, O_RDONLY);
	arr_i = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		points[arr_i] = (t_point*)malloc(sizeof(t_point) * ((map->max_strlen) +
		2));
		parse_line(points[arr_i], line, arr_i, map);
		arr_i++;
	}
	points[arr_i] = NULL;
	return (points);
}

size_t		count_lines(char *file, t_map *map)
{
	int		fd;
	size_t	max_strlen;
	char	*line;
	size_t	lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	max_strlen = 0;
	while ((get_next_line(fd, &line) == 1))
	{
		lines++;
		if ((ceil(ft_strlen(line) / 2)) > max_strlen)
			max_strlen = ceil((ft_strlen(line) / 2));
	}
	close(fd);
	map->max_strlen = max_strlen;
	return (lines);
}

void		add_init_points(t_point *point, double x_init, double y_init, double z_init)
{
	point->x_init = x_init;
	point->y_init = y_init;
	point->z_init = z_init;
	point->x_prime = point->x_init;
	point->y_prime = point->y_init;
	point->z_prime = point->z_init;
	point->end = 0;
}
