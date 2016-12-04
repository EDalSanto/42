/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:04:58 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 16:06:35 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		is_sorted(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nums[i] > nums[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_number(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
