/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:27:09 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/22 18:17:31 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_prime_big_slope(t_cur cur, t_point *point1, t_point *point2)
{
	cur.max = fabs(cur.dy);
	cur.neg = (cur.dy < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_prime) + 100 + point1->x_prime, (cur.y - point1->y_prime) + 100 + point1->y_prime, WHITE);
		cur.y += cur.res * cur.neg;
		cur.x = (cur.x == point2->x_prime) ? (cur.x) : (cur.y - cur.y_int) / cur.slope;
		cur.i += cur.res;
	}
}

void		draw_prime_small_slope(t_cur cur, t_point *point1)
{
	cur.max = fabs(cur.dx);
	cur.neg = (cur.dx < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_prime) + 100 + point1->x_prime, (cur.y - point1->y_prime) +  point1->y_prime + 100, WHITE);
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

void		draw_prime(void *mlx, void *win, t_point *point1, t_point *point2)  
{
	t_cur	cur;
	
	cur.mlx = mlx;
	cur.win = win;
	setup_prime_line(&cur, point1, point2);
	if (fabs(cur.slope) > 1.0)
		draw_prime_big_slope(cur, point1, point2);
	else
		draw_prime_small_slope(cur, point1);
}
