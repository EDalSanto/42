/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:22:37 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/21 17:58:08 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_inits(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;
	t_point	right_point;
	t_point	below_point;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((map->points[arr_i][point_i]).end))
		{
			cur_point = map->points[arr_i][point_i];
			if (!((map->points[arr_i][point_i + 1]).end))
			{
				right_point = map->points[arr_i][point_i + 1];
				draw_line(map, &cur_point, &right_point);   		
			}
			if (map->points[arr_i + 1])
			{
				below_point = map->points[arr_i + 1][point_i];
				draw_line(map, &cur_point, &below_point); 
			}
			point_i++;  		
		}
		arr_i++;
	}
}

void		print_primes(t_map *map)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;
	t_point	right_point;
	t_point	below_point;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((map->points[arr_i][point_i]).end))
		{
			cur_point = map->points[arr_i][point_i];
			if (!((map->points[arr_i][point_i + 1]).end))
			{
				right_point = map->points[arr_i][point_i + 1];
				draw_prime(map, &cur_point, &right_point);   		
			}
			if (map->points[arr_i + 1])
			{
				below_point = map->points[arr_i + 1][point_i];
				draw_prime(map, &cur_point, &below_point); 
			}
			point_i++;  		
		}
		arr_i++;
	}
}
