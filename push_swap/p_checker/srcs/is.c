/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:04:58 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 10:22:04 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(char *arg, t_stack *stackA)
{
	if (!is_number(arg) || (ft_atoi(arg) > 2147483647) ||
			((long)ft_atoi(arg) < -2147483648) ||
			is_duplicate(stackA, ft_atoi(arg))) 
		return (0);
	else
		return (1);
}

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

int		is_revsorted(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nums[i] < nums[i + 1])
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
