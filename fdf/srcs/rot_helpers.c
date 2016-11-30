/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:40:44 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/30 08:24:11 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		reset_primes(t_point **points)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]);
			point->x_prime = point->x_init;
			point->y_prime = point->y_init;
			point->z_prime = point->z_init;
			point_i++;
		}
		arr_i++;
	}
}

void		translate_points(t_map *map)
{
	int		zf;

	zf = map->zoom_factor;
	reset_primes(map->points);
	z_rotate(map->points, map->angles.a_z);
	x_rotate(map->points, map->angles.a_x);
	y_rotate(map->points, map->angles.a_y);
	map->translate_adj = 1;
	if (zf > 0)
	{
		while (zf--)
			zoom(map);
	}
	else if (zf < 0)
	{
		while (zf++)
			unzoom(map);
	}
	map->translate_adj = 0;
	mlx_clear_window(map->mlx, map->win);
	print_primes(map);
}

void		reset_map(t_map *map)
{
	map->angles = init_angles();
	map->zoom_factor = 0;
	map->zoom_sign = 0;
	scale_detective(map);
	reset_primes(map->points);
	center(map);
	mlx_clear_window(map->mlx, map->win);
	print_inits(map);
}

void		update_angles(int keycode, t_map *map)
{
	if (keycode == 12)
		update_angle(&map->angles, 'x', 1);
	else if (keycode == 0)
		update_angle(&map->angles, 'x', -1);
	else if (keycode == 13)
		update_angle(&map->angles, 'y', -1);
	else if (keycode == 1)
		update_angle(&map->angles, 'y', 1);
	else if (keycode == 14)
		update_angle(&map->angles, 'z', 1);
	else if (keycode == 2)
		update_angle(&map->angles, 'z', -1);
}
