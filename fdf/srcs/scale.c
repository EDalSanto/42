/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:26:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/29 17:27:29 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			center(t_map *map)
{
		map->x_start = (WIDTH - (map->scale * map->max_strlen)) / 2;
		map->y_start = (LENGTH - (map->scale * map->num_lines)) / 2;
		/*printf("xstart: %lf, width: %d, map->scale: %lf, map->max_strlen: %zu, y_start: %lf\n", map->x_start, WIDTH, map->scale, map->max_strlen, map->y_start);*/
}

void			scale_detective(t_map *map)
{
	double		scale;
	double		area_win;
	double		area_img;

	area_win = WIDTH * LENGTH;
	scale = 1;
	area_img = (map->max_strlen * scale) * (map->num_lines * scale);
	if ((area_img * 4 / area_win) < 0.5)
	{
		while ((area_img * 4 / area_win) < 0.5)
		{
			scale++;
			area_img = (map->max_strlen * scale) * (map->num_lines * scale);
		}
	}
	else if ((area_img / 2) / area_win > 0.5)
	{
		while (((area_img / 2) / area_win) > 0.5)
		{
			scale--;
			area_img /= 2;
		}
	}
	map->scale = scale;
}
