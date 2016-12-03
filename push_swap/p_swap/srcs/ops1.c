/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:54:33 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 09:09:49 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h" 

void	swap_first_two(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	swap_both(int *stackA, int *stackB)
{
	swap_first_two(stackA);
	swap_first_two(stackB);
}

int		empty_stack(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i++])	
			return (0);
	}
	return (1);
}

void	push_on_A(int *stackA, int *stackB, int size)
{
	int	temp;

	if (!empty_stack(stackB[i], size))
	{
		temp = stackB[0];
		ft_memmove(&stackB[0], &stackB[1], sizeof(int) * (size - 1));
		ft_memmove(&stackA[1], &stackA[0], sizeof(int) * (size - 1));
		stackA[0] = temp;
	}
}

void	push_on_B(int *stackA, int *stackB, int size)
{
	int	temp;

	if (!empty_stack(stackA[i], size))
	{
		temp = stackA[0];
		ft_memmove(&stackA[0], &stackA[1], sizeof(int) * (size - 1));
		ft_memmove(&stackB[1], &stackB[0], sizeof(int) * (size - 1));
		stackB[0] = temp;
	}
}
