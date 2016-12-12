/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:54:33 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 08:52:11 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
}

int		empty_stack(t_stack *stack)
{
	if (!stack->cur_size)
		return (1);
	else
		return (0);
}

void	push_on_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!empty_stack(stack_b))
	{
		temp = (stack_b->nums)[0];
		ft_memmove(&(stack_b->nums[0]), &(stack_b->nums[1]),
					sizeof(int) * (stack_b->cur_size));
		ft_memmove(&(stack_a->nums[1]), &(stack_a->nums[0]),
					sizeof(int) * (stack_a->cur_size));
		(stack_a->nums)[0] = temp;
		(stack_a->cur_size)++;
		(stack_b->cur_size)--;
	}
}

void	push_on_b(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!empty_stack(stack_a))
	{
		temp = (stack_a->nums)[0];
		ft_memmove(&(stack_a->nums[0]), &(stack_a->nums[1]),
					sizeof(int) * (stack_a->cur_size));
		ft_memmove(&(stack_b->nums[1]), &(stack_b->nums[0]),
					sizeof(int) * (stack_b->cur_size));
		(stack_b->nums)[0] = temp;
		(stack_b->cur_size)++;
		(stack_a->cur_size)--;
	}
}
