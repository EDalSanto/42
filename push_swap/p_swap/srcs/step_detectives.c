/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 12:28:48 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			check_all_num_locations(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		right_loc;

	i = 0;
	min_dif = 2147483647;
	if (((num > stack->nums[0] && num < stack->nums[stack->cur_size - 1])
		|| (num < stack->nums[0] && num > stack->nums[stack->cur_size - 1]))) 
	{
		right_loc = 0;
		min_dif = ft_abs(stack->nums[0] - stack->nums[stack->cur_size - 1]); 
	}
	while (i < (stack->cur_size - 1)) 
	{
		if ((num > stack->nums[i] && num < stack->nums[i + 1]) ||
				(num < stack->nums[i] && num > stack->nums[i + 1]))
		{
			ft_abs(stack->nums[i + 1] - stack->nums[i]);	
			if (ft_abs(stack->nums[i + 1] - stack->nums[i])	< 
					min_dif && (right_loc = i + 1))
				min_dif = ft_abs(stack->nums[i + 1] - stack->nums[i]);
		}
		i++;
	}
	return (right_loc);
}

int			find_right_location(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		right_loc;

	i = 0;
	min_dif = 2147483647;
	right_loc = -1;
	if (stack->cur_size == 0 || 
		(num < stack->min_num && stack->nums[0] == stack->min_num))
		return (0);
	else if (num < stack->min_num)
	{
		if (is_revsorted(stack->nums, stack->cur_size))
			return (1);
		return (stack->min_idx);
	}
	else if (num > stack->max_num)
	{
		if (stack->max_idx - 1 == stack->min_idx)
			return (stack->max_idx);
		return (stack->max_idx + 1);
	}
	right_loc = check_all_num_locations(stack, num);
	return (right_loc);
}

int			calculate_steps(int indexA, t_super_stack *super_stack)
{
	int		steps;
	int		midB_idx;
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
	if (B_loc <= midB_idx)
	{
		steps += B_loc;
	}
	else
	{
		steps += super_stack->stackB->cur_size - B_loc;
	}
	return (steps);
}

void		set_rotations(t_super_stack *super_stack, int min_steps,
							int min_idx, int B_loc)
{
	if (min_idx <= super_stack->stackA->cur_size / 2)
		super_stack->moves->ra = min_idx;
	else
		super_stack->moves->rra = super_stack->stackA->cur_size - min_idx;
	if (B_loc <= super_stack->stackB->cur_size / 2)
		super_stack->moves->rb = (min_steps - super_stack->moves->ra -
									super_stack->moves->rra - 1); 
	else
		super_stack->moves->rrb = (min_steps - super_stack->moves->ra -
									super_stack->moves->rra - 1); 
}

int			find_shortest_path_to_sorted_B(t_super_stack *super_stack)
{
	int		min_steps;
	int		min_idx;
	int		i;
	int		steps;
	int		B_loc;

	i = 0;
	min_steps = 2147483647;
	min_idx = 2147483647;
	while (i < super_stack->stackA->cur_size)
	{
		steps = calculate_steps(i, super_stack);
		if (steps < min_steps && (min_steps = steps))
			min_idx = i;
		i++;
	}
	B_loc = find_right_location(super_stack->stackB, super_stack->stackA->nums[min_idx]);
	set_rotations(super_stack, min_steps, min_idx, B_loc);
	return (min_idx);
}