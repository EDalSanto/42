/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_primes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:38:46 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/29 19:40:05 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_prime_right(t_map *map, int arr_i, int point_i, t_point cur)
{
	t_point	right_point;

	right_point = map->points[arr_i][point_i + 1];
	draw_prime(map, &cur, &right_point);
}

void		print_prime_below(t_map *map, int arr_i, int point_i, t_point cur)
{
	t_point	below_point;

	below_point = map->points[arr_i + 1][point_i];
	draw_prime(map, &cur, &below_point);
}

void		print_primes(t_map *map)
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
				print_prime_right(map, arr_i, point_i, cur_point);
			if (map->points[arr_i + 1])
				print_prime_below(map, arr_i, point_i, cur_point);
			point_i++;
		}
		arr_i++;
	}
}
