/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 19:12:08 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/13 20:02:15 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"

t_offsets		struct_cpy(t_offsets struct_to_copy)
{
	t_offsets	new;

	new.offset0 = struct_to_copy.offset0;
	new.offset1 = struct_to_copy.offset1;
	new.offset2 = struct_to_copy.offset2;
	new.offset3 = struct_to_copy.offset3;
	return (new);
}

t_offsets		t_offset_creator(int offset0, int offset1,
									int offset2, int offset3)
{
	t_offsets	new;

	new.offset0 = offset0;
	new.offset1 = offset1;
	new.offset2 = offset2;
	new.offset3 = offset3;
	return (new);
}
