/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:27:09 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/22 19:45:43 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_prime_big_slope(t_map *map, t_cur cur, t_point *point1, t_point *point2)
{
	cur.max = fabs(cur.dy);
	cur.neg = (cur.dy < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_prime) +
		map->x_start + point1->x_prime, (cur.y - point1->y_prime) + map->y_start + point1->y_prime, WHITE);
		cur.y += cur.res * cur.neg;
		cur.x = (cur.x == point2->x_prime) ? (cur.x) : (cur.y - cur.y_int) / cur.slope;
		cur.i += cur.res;
	}
}

void		draw_prime_small_slope(t_map *map, t_cur cur, t_point *point1)
{
	cur.max = fabs(cur.dx);
	cur.neg = (cur.dx < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_prime) + map->x_start
		+ point1->x_prime, (cur.y - point1->y_prime) +  point1->y_prime +
		map->y_start, WHITE);
		cur.x += cur.res * cur.neg; 
		cur.y = (cur.slope * cur.x) + cur.y_int;
		cur.i += cur.res;
	}
}

static void	setup_prime_line(t_cur *cur, t_point *point1, t_point *point2)
{
	cur->dx = point2->x_prime - point1->x_prime;
	cur->dy = point2->y_prime - point1->y_prime;
	cur->x = point1->x_prime;
	cur->y = point1->y_prime;
	cur->slope = cur->dy / cur->dx;
	cur->y_int = cur->y - (cur->slope * cur->x);
	cur->res = 0.5;
	cur->i = 0.0;
}

void		draw_prime(t_map *map, t_point *point1, t_point *point2)  
{
	t_cur	cur;
	
	cur.mlx = map->mlx;
	cur.win = map->win;
	setup_prime_line(&cur, point1, point2);
	if (fabs(cur.slope) > 1.0)
		draw_prime_big_slope(map, cur, point1, point2);
	else
		draw_prime_small_slope(map, cur, point1);
}
