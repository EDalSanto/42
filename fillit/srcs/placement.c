/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:50:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/09 17:58:53 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"
#include <stdio.h>

static int	offset_detective(int sa_i, int offset, int zero_offset)
{
	offset = offset / 4 * g_size + offset % 4 + sa_i - zero_offset;
	return (offset);
}

int			valid_placement(char *solution_arr, int sa_i, t_offsets tetri)
{
	int		o_i;
	int		offsets[8];

	o_i = 0;
	offsets[0] = offset_detective(sa_i, tetri.offset1, tetri.offset0);
	offsets[1] = offset_detective(sa_i, tetri.offset2, tetri.offset0);
	offsets[2] = offset_detective(sa_i, tetri.offset3, tetri.offset0);
	offsets[3] = 0;
	offsets[4] = tetri.offset1;
	offsets[5] = tetri.offset2;
	offsets[6] = tetri.offset3;
	offsets[7] = 0;
	while (offsets[o_i] != 0)
	{
		if (((offsets[o_i] / g_size - sa_i / g_size) != (offsets[o_i + 4] / 4))
				|| ((offsets[o_i]) >= (g_size * g_size))
				|| solution_arr[sa_i] != '.'
				|| solution_arr[offsets[o_i]] != '.')
			return (0);
		o_i++;
	}
	return (1);
}

void		place_tetri(char *sol_arr, int sa_i, t_offsets t)
{
	sol_arr[sa_i] = t.letter;
	sol_arr[offset_detective(sa_i, t.offset1, t.offset0)] = t.letter;
	sol_arr[offset_detective(sa_i, t.offset2, t.offset0)] = t.letter;
	sol_arr[offset_detective(sa_i, t.offset3, t.offset0)] = t.letter;
}

void		remove_tetri(char *solution_arr, int sa_i, t_offsets tetri)
{
	solution_arr[sa_i] = '.';
	solution_arr[offset_detective(sa_i, tetri.offset1, tetri.offset0)] = '.';
	solution_arr[offset_detective(sa_i, tetri.offset2, tetri.offset0)] = '.';
	solution_arr[offset_detective(sa_i, tetri.offset3, tetri.offset0)] = '.';
}
