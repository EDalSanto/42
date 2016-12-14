/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/14 12:31:10 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			new_number_inbetween_ends(t_stack *stack, int num)
{
	int		top;
	int		bottom;

	top = stack->nums[0];
	bottom = stack->nums[stack->cur_size - 1];
	if ((num > top && num < bottom) || (num < top && num > bottom))
		return (1);
	else
		return (0);
}

int			check_all_num_locations(t_stack *stack, int num)
{
	int		i;
	int		min_dif;
	int		right_loc;

	i = 0;
	min_dif = 2147483647;
	if (new_number_inbetween_ends(stack, num))
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
			if (ft_abs(stack->nums[i + 1] - stack->nums[i]) <
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
	if (stack->cur_size == 0)
		return (0);
	else if (num < stack->min_num)
		return (stack->max_idx);
	else if (num > stack->max_num)
		return (stack->max_idx);
	right_loc = check_all_num_locations(stack, num);
	return (right_loc);
}

int			calculate_steps(int index_a, t_super_stack *super_stack)
{
	int		steps;
	int		mid_b_idx;
	int		b_loc;

	steps = 0;
	mid_b_idx = 0;
	b_loc = find_right_location(super_stack->stack_b,
							super_stack->stack_a->nums[index_a]);
	//simulate A rotations
	if (index_a == 0)
		steps = 0;
	else if (index_a <= super_stack->stack_a->cur_size / 2)
		steps += index_a;
	else
		steps += super_stack->stack_a->cur_size - index_a;
	//push to B
	steps++;
	//simulate B rotations
	mid_b_idx = super_stack->stack_b->cur_size / 2;
	if (b_loc <= mid_b_idx)
	{
		steps += b_loc;
	}
	else
	{
		steps += super_stack->stack_b->cur_size - b_loc;
	}
	return (steps);
}

void		set_rotations(t_super_stack *super_stack, int min_steps,
							int min_idx, int b_loc)
{
	if (min_idx <= super_stack->stack_a->cur_size / 2)
		super_stack->moves->ra = min_idx;
	else
		super_stack->moves->rra = super_stack->stack_a->cur_size - min_idx;
	if (b_loc <= super_stack->stack_b->cur_size / 2)
		super_stack->moves->rb = (min_steps - super_stack->moves->ra -
									super_stack->moves->rra - 1);
	else
		super_stack->moves->rrb = (min_steps - super_stack->moves->ra -
									super_stack->moves->rra - 1);
}

int			find_shortest_path_to_sorted_b(t_super_stack *super_stack)
{
	int		min_steps;
	int		min_idx;
	int		i;
	int		steps;
	int		b_loc;

	i = 0;
	min_steps = 2147483647;
	min_idx = 2147483647;
	while (i < super_stack->stack_a->cur_size)
	{
		steps = calculate_steps(i, super_stack);
		if (steps < min_steps) 
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	b_loc = find_right_location(super_stack->stack_b,
							super_stack->stack_a->nums[min_idx]);
	set_rotations(super_stack, min_steps, min_idx, b_loc);
	return (min_idx);
}
