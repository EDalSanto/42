/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:23:59 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/21 18:02:17 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		parse_line(t_point *point, char *line, int y)
{
	int		x;
	int		i;
	double	z;
	t_point	*p;

	x = 0.0;
	i = 0;
	p = point;
	while (line[i])
	{
		z = 0.0;
		if(ft_isdigit(line[i]))
		{	
			while(ft_isdigit(line[i])) 
			{
				z = (z * 10.0) + (line[i] - '0');		
				i++;
			}
			add_init_points(p, x, y, z);
			//printf("z: %lf, p before increment: %p, point + x: %p, point + x->y: %lf, point + x->x: %lf, x: %d\n", z, p, point + x, (point + x)->y_init, (point + x)->x_init, x);
			p++;
			x++;
		}
		else
			i++;
	}
//	printf("x: %lf\n", x);
	p->end = 1;
	//printf("p end: %p, point + x->end: %d\n", p, (point + x)->end);
}

t_point		**create_points(char *file)
{
	t_point **points;
	char	*line;
	int		fd;
	int		arr_i;

	points = (t_point**)malloc(sizeof(t_point*) * count_lines(file) + sizeof(void*));
	fd = open(file, O_RDONLY);
	arr_i = 0;
	while ((get_next_line(fd, &line)) == 1)		
	{
		points[arr_i] = (t_point*)malloc(sizeof(t_point) * ((ft_strlen(line) / 2) + 2));
		parse_line(points[arr_i], line, arr_i);
		arr_i++;	
	}
	points[arr_i] = NULL;
	return (points);
}

size_t		count_lines(char *file)
{
	int		fd;
	char	*line;
	size_t	lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
		lines++;
	close(fd);
	return (lines);
}

void		add_init_points(t_point *point, double x_init, double y_init, double z_init)
{
	point->x_init = x_init * SCALE;
	point->y_init = y_init * SCALE;
	point->z_init = z_init * SCALE;
	point->x_prime = 0.0;
	point->y_prime = 0.0;
	point->z_prime = 0.0;
//	printf("x_prime: %lf, y_prime: %lf\n", point->x_prime, point->y_prime);
	point->end = 0;
}


