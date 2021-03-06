/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:22:37 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/29 19:38:58 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_horizontal(t_map *map, int arr_i, int point_i, t_point cur)
{
	t_point	right_point;

	right_point = map->points[arr_i][point_i + 1];
	draw_line(map, &cur, &right_point);
}

void		print_vertical(t_map *map, int arr_i, int point_i, t_point cur)
{
	t_point	below_point;

	below_point = map->points[arr_i + 1][point_i];
	draw_line(map, &cur, &below_point);
}

void		print_inits(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((map->points[arr_i][point_i]).end))
		{
			cur_point = map->points[arr_i][point_i];
			if (!((map->points[arr_i][point_i + 1]).end))
				print_horizontal(map, arr_i, point_i, cur_point);
			if (map->points[arr_i + 1])
				print_vertical(map, arr_i, point_i, cur_point);
			point_i++;
		}
		arr_i++;
	}
}
