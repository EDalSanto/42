/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_detective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 20:05:54 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/08 12:40:17 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

int					*block_indexs_difs(char *tetri)
{
	int				c;
	int				i;
	int				*b_idxs;
	int				first_found;
	int				first;

	c = 0;
	i = 0;
	first_found = 0;
	first = 0;
	b_idxs = (int*)malloc(sizeof(int) * 4);
	while (tetri[c])
	{
		if (tetri[c] == '#' && !first_found)
		{
			first = c;
			first_found = 1;
			b_idxs[i++] = 0;
		}
		else if (tetri[c] == '#')
			b_idxs[i++] = c - first;
		c++;
	}
	return (b_idxs);
}

t_offsets			*make_all_offsets_arr(void)
{
	t_offsets		*all_offsets_arr;

	if (!(all_offsets_arr = (t_offsets*)malloc(sizeof(t_offsets) * 19)))
		return (NULL);
	all_offsets_arr[0] = t_offset_creator(0, 4, 8, 12);
	all_offsets_arr[1] = t_offset_creator(0, 1, 2, 3);
	all_offsets_arr[2] = t_offset_creator(0, 1, 4, 5);
	all_offsets_arr[3] = t_offset_creator(0, 1, 5, 6);
	all_offsets_arr[4] = t_offset_creator(1, 2, 4, 5);
	all_offsets_arr[5] = t_offset_creator(0, 4, 8, 9);
	all_offsets_arr[6] = t_offset_creator(1, 5, 8, 9);
	all_offsets_arr[7] = t_offset_creator(1, 4, 5, 6);
	all_offsets_arr[8] = t_offset_creator(1, 4, 5, 8);
	all_offsets_arr[9] = t_offset_creator(0, 4, 5, 9);
	all_offsets_arr[10] = t_offset_creator(0, 1, 4, 8);
	all_offsets_arr[11] = t_offset_creator(0, 1, 5, 9);
	all_offsets_arr[12] = t_offset_creator(2, 4, 5, 6);
	all_offsets_arr[13] = t_offset_creator(0, 1, 2, 6);
	all_offsets_arr[14] = t_offset_creator(0, 1, 2, 4);
	all_offsets_arr[15] = t_offset_creator(0, 4, 5, 6);
	all_offsets_arr[16] = t_offset_creator(0, 1, 2, 5);
	all_offsets_arr[17] = t_offset_creator(0, 4, 5, 8);
	all_offsets_arr[18] = t_offset_creator(1, 4, 5, 9);
	return (all_offsets_arr);
}

t_offsets			tetri_detective_partner(int *b_idxs,
		t_offsets *all_off_arr, int i)
{
	t_offsets		new;

	while (i < 19)
	{
		if (b_idxs[1] == all_off_arr[i].offset1 - all_off_arr[i].offset0 &&
			b_idxs[2] == all_off_arr[i].offset2 - all_off_arr[i].offset0 &&
			b_idxs[3] == all_off_arr[i].offset3 - all_off_arr[i].offset0)
			new = struct_cpy(all_off_arr[i]);
		i++;
	}
	return (new);
}

t_offsets			tetri_detective2(char *tetri)
{
	int				c;
	int				i;
	int				*b_idxs;
	t_offsets		new;
	t_offsets		*all_offsets_arr;

	c = 0;
	i = 0;
	b_idxs = block_indexs_difs(tetri);
	all_offsets_arr = make_all_offsets_arr();
	while (tetri[c])
	{
		if (tetri[c] == '#')
			new = tetri_detective_partner(b_idxs, all_offsets_arr, i);
		c++;
	}
	free(b_idxs);
	free(all_offsets_arr);
	return (new);
}

t_offsets			*make_input_arr(char **tetri_arr)
{
	int				r;
	t_offsets		*input_arr;

	r = 0;
	input_arr = (t_offsets*)malloc(sizeof(t_offsets) * g_tetriminos);
	while (r < g_tetriminos)
	{
		input_arr[r] = tetri_detective2(tetri_arr[r]);
		input_arr[r].letter = r + 'A';
		r++;
	}
	return (input_arr);
}
