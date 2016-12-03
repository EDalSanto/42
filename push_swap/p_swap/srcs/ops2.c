/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:55:59 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 15:23:08 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	rotate(t_stack *stack)
{
	int	temp;

	temp = (stack->nums)[0];
	ft_memmove(&(stack->nums[0]), &(stack->nums[1]),
				sizeof(int) * (stack->cur_size));
	stack->nums[stack->cur_size - 1] = temp;
}

void	rotate_both(t_stack *stackA, t_stack *stackB)
{
	rotate(stackA);
	rotate(stackB);
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->nums[stack->cur_size - 1];
	ft_memmove(&(stack->nums[1]), &(stack->nums[0]),
				sizeof(int) * (stack->cur_size));
	stack->nums[0] = temp;
}

void	reverse_rotate_both(t_stack *stackA, t_stack *stackB)
{
	reverse_rotate(stackA);
	reverse_rotate(stackB);
}
