/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 08:05:47 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/30 08:08:21 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_points(t_map *map)
{
	int		arr_i;

	arr_i = 0;
	while (map->points[arr_i] != NULL)
	{
		free(map->points[arr_i]);
		arr_i++;
	}
	free(map->points);
}
