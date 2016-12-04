/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:54:33 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 10:25:01 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_first_two(t_stack *stack)
{
	int	temp;

	if (stack->cur_size >= 2)
	{
		temp = stack->nums[0];
		stack->nums[0] = stack->nums[1];
		stack->nums[1] = temp;
	}
}

void	swap_both(t_stack *stackA, t_stack *stackB)
{
	swap_first_two(stackA);
	swap_first_two(stackB);
}

int		empty_stack(t_stack *stack)
{
	if (!stack->cur_size)	
		return (1);
	else
		return (0);
}

void	push_on_A(t_stack *stackA, t_stack *stackB)
{
	int	temp;

	if (!empty_stack(stackB))
	{
		temp = (stackB->nums)[0];
		ft_memmove(&(stackB->nums[0]), &(stackB->nums[1]),
					sizeof(int) * (stackB->cur_size));
		ft_memmove(&(stackA->nums[1]), &(stackA->nums[0]),
					sizeof(int) * (stackA->cur_size));
		(stackA->nums)[0] = temp;
		(stackA->cur_size)++;
		(stackB->cur_size)--;
	}
}

void	push_on_B(t_stack *stackA, t_stack *stackB)
{
	int	temp;

	if (!empty_stack(stackA))
	{
		temp = (stackA->nums)[0];
		ft_memmove(&(stackA->nums[0]), &(stackA->nums[1]),
					sizeof(int) * (stackA->cur_size));
		ft_memmove(&(stackB->nums[1]), &(stackB->nums[0]),
					sizeof(int) * (stackB->cur_size));
		(stackB->nums)[0] = temp;
		(stackB->cur_size)++;
		(stackA->cur_size)--;
	}
}
