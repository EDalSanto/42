/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:42:44 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/29 19:44:45 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		z_rotate(t_point **points, double a_z)
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
			point->z_prime = point->z_init;
			point->x_prime = (point->x_init * cos(a_z)) -
												(point->y_init * sin(a_z));
			point->y_prime = (point->x_init * sin(a_z)) +
												(point->y_init * cos(a_z));
			point_i++;
		}
		arr_i++;
	}
}

void		x_rotate(t_point **points, double a_x)
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
			point->x_prime = point->x_prime;
			point->y_prime = (point->y_prime * cos(a_x)) -
												(point->z_prime * sin(a_x));
			point->z_prime = (point->y_prime * sin(a_x)) +
												(point->z_prime * cos(a_x));
			point_i++;
		}
		arr_i++;
	}
}

void		y_rotate(t_point **points, double a_y)
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
			point->y_prime = point->y_prime;
			point->x_prime = (point->z_prime * sin(a_y)) +
												(point->x_prime * cos(a_y));
			point->z_prime = (point->z_prime * cos(a_y)) -
												(point->x_prime * sin(a_y));
			point_i++;
		}
		arr_i++;
	}
}

int			rot_key(int keycode)
{
	if (keycode == 12 || keycode == 0 || keycode == 13 || keycode == 1
		|| keycode == 14 || keycode == 2)
		return (1);
	else
		return (0);
}
