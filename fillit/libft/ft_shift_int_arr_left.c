/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarr_shift_left.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 18:54:41 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/07 19:04:31 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			*shift_int_arr_left(int *arr, int len, int shifts)
{
	int     *shifted;
	int     index;
	int     new_index;

	index = 0;
	shifted = malloc(sizeof(int) * len);
	while (index < len)
	{
		new_index = (index - shifts + len) % len;
		shifted[new_index] = arr[index];
		index++;
	}
	return (shifted);
}
