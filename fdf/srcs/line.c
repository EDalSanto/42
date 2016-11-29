/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:27:09 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/22 19:45:59 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_big_slope(t_map *map, t_cur cur, t_point *point1, t_point *point2)
{
	cur.max = fabs(cur.dy);
	cur.neg = (cur.dy < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + map->x_start +
		point1->x_init, (cur.y - point1->y_init) + map->y_start + point1->y_init, WHITE);
		cur.y += cur.res * cur.neg;
		cur.x = (cur.x == point2->x_init) ? (cur.x) : (cur.y - cur.y_int) / cur.slope;
		cur.i += cur.res;
	}
}

void		draw_small_slope(t_map *map, t_cur cur, t_point *point1)
{
	cur.max = fabs(cur.dx);
	cur.neg = (cur.dx < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + map->x_start +
		point1->x_init, (cur.y - point1->y_init) +  point1->y_init +
		map->y_start, WHITE);
		cur.x += cur.res * cur.neg; 
		cur.y = (cur.slope * cur.x) + cur.y_int;
		cur.i += cur.res;
	}
}

static void	setup_cur_line(t_cur *cur, t_point *point1, t_point *point2)
{
	cur->dx = point2->x_init - point1->x_init;
	cur->dy = point2->y_init - point1->y_init;
	cur->x = point1->x_init;
	cur->y = point1->y_init;
	cur->slope = cur->dy / cur->dx;
	cur->y_int = cur->y - (cur->slope * cur->x);
	cur->res = 0.5;
	cur->i = 0.0;
}

void		draw_line(t_map *map, t_point *point1, t_point *point2)  
{
	t_cur	cur;
	
	cur.mlx = map->mlx;
	cur.win = map->win;
	setup_cur_line(&cur, point1, point2);
	if (fabs(cur.slope) > 1.0)
		draw_big_slope(map, cur, point1, point2);
	else
		draw_small_slope(map, cur, point1);
}
