/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 10:44:57 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			find_right_location(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		dif;
	int		right_loc;

	i = 0;
	dif = 0;
	min_dif = 2147483647;
	right_loc = -1;
	find_min(stack);
	if (stack->cur_size == 0 || 
			(num < stack->min_num && stack->nums[0] == stack->min_num))
		return (0);
	else if (num < stack->min_num)
	{
		right_loc = stack->min_idx;
		return (right_loc);
	}
	else if (num > find_max_num(stack->nums, stack->cur_size))
	{
		right_loc = find_max_idx(stack->nums, stack->cur_size);
		return (right_loc);
	}
	if ((num > stack->nums[0] && num < stack->nums[stack->cur_size - 1]) ||
			(num < stack->nums[0] && num > stack->nums[stack->cur_size - 1])) 
	{
		right_loc = 0;
		min_dif = ft_abs(stack->nums[0] - stack->nums[stack->cur_size - 1]); 
	}
	while (i < (stack->cur_size - 1)) 
	{
		if ((num > stack->nums[i] && num < stack->nums[i + 1]) ||
				(num < stack->nums[i] && num > stack->nums[i + 1]))
		{
			dif = ft_abs(stack->nums[i + 1] - stack->nums[i]);	
			if (dif < min_dif)
			{
				right_loc = i + 1;
				min_dif = dif;
			}
		}
		i++;
	}
	if (right_loc == -1)
		right_loc = i;
	return (right_loc);
}

int			calculate_steps(int indexA, t_super_stack *super_stack)
{
	int		steps;
	int		midB_idx;
	int		flag_holder;
	int		B_loc;

	steps = 0;
	midB_idx = 0;
	B_loc = find_right_location(super_stack->stackB, super_stack->stackA->nums[indexA]);
	if (indexA == 0)
		steps = 0;
	else if (indexA <= super_stack->stackA->cur_size / 2)
		steps += indexA;
	else
		steps += super_stack->stackA->cur_size - indexA;
	steps++;
	midB_idx = super_stack->stackB->cur_size / 2;
	flag_holder = super_stack->flags->v;
	super_stack->flags->v = 0;
	if (B_loc <= midB_idx)
	{
		steps += B_loc;
	}
	else
	{
		steps += super_stack->stackB->cur_size - B_loc;
	}
	super_stack->flags->v = flag_holder;
	return (steps);
}

int			find_shortest_path_to_sorted_B(t_super_stack *super_stack)
{
	int		min_steps;
	int		min_idx;
	int		i;
	int		steps;
	int		B_loc;

	i = 0;
	min_steps = 400000;
	min_idx = 400000;
	while (i < super_stack->stackA->cur_size)
	{
		steps = calculate_steps(i, super_stack);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	B_loc = find_right_location(super_stack->stackB, super_stack->stackA->nums[min_idx]);
	if (min_idx <= super_stack->stackA->cur_size / 2)
		super_stack->moves->ra = min_idx;
	else
		super_stack->moves->rra = super_stack->stackA->cur_size - min_idx;
	if (B_loc <= super_stack->stackB->cur_size / 2)
		super_stack->moves->rb = (min_steps - super_stack->moves->ra - super_stack->moves->rra - 1); 
	else
		super_stack->moves->rrb = (min_steps - super_stack->moves->ra - super_stack->moves->rra - 1); 
	return (min_idx);
}
