/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/08 21:44:38 by edal-san         ###   ########.fr       */
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
			(num > stack->nums[0] && num < stack->nums[stack->cur_size - 1]) || 
			(num < stack->min_num && stack->nums[0] == stack->min_num))
		return (0);
	else if (num < stack->min_num)
	{
		right_loc = stack->min_idx + 1;
		return (right_loc);
	}
	while (i < (stack->cur_size - 1)) 
	{
		if ((num > stack->nums[i] && num < stack->nums[i + 1]) ||
				(num < stack->nums[i] && num > stack->nums[i + 1]))
		{
			dif = stack->nums[i + 1] - stack->nums[i];	
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
	int		mid;
	int		flag_holder;

	steps = 0;
	mid = 0;
	ft_printf("indexA: %d\n", indexA);
	if (indexA == 0)
		steps = 0;
	else if (indexA <= super_stack->stackA->cur_size / 2)
	{
		steps += indexA;
		super_stack->moves->ra = indexA;
	}
	else
	{
		steps += super_stack->stackA->cur_size - indexA;
		super_stack->moves->rra = super_stack->stackA->cur_size - indexA;
	}
	steps++;
	mid = super_stack->stackB->nums[(super_stack->stackB->cur_size / 2)];
	flag_holder = super_stack->flags->v;
	super_stack->flags->v = 0;
	find_min(super_stack->stackB);	
	if (super_stack->stackA->nums[indexA] > mid)
	{
		steps += find_right_location(super_stack->stackB,
				super_stack->stackA->nums[indexA]);
		super_stack->moves->rb = (steps - super_stack->moves->ra); 
	}
	else
	{
		steps += super_stack->stackB->cur_size - 
			find_right_location(super_stack->stackB, super_stack->stackA->nums[indexA]);
		super_stack->moves->rrb = (steps - super_stack->moves->rra); 
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

	i = 0;
	min_steps = calculate_steps(i, super_stack);
	min_idx = i;
	i++;
	while ((!(min_steps <= 1)) && i < super_stack->stackA->cur_size)
	{
		steps = calculate_steps(i, super_stack);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

//char		*revsort(char *solution, t_super_stack *super_stack)
//{
//	int		min;
//	int		num_to_sort;
//	int		mid;
//	int		right_place;
//	int		i;
//	
//	min = super_stack->stackB->min_num; 	
//	num_to_sort = super_stack->stackA->nums[0];
//	right_place = find_right_location(stackB, num_to_sort);
//	i = right_place;
//	mid = stackB->cur_size / 2;
//	if (right_place <= mid)
//	{
//		while (i)
//		{
//			solution = update_solution(solution, "rb");
//			perform_op("rb", stackA, stackB, flags);
//			i--;
//		}
//	}
//	else
//	{
//		i = stackB->cur_size - i;
//		while (i)
//		{
//			solution = update_solution(solution, "rrb");
//			perform_op("rrb", stackA, stackB, flags);
//			i--;
//		}
//	}
//	solution = update_solution(solution, "pb");
//	perform_op("pb", stackA, stackB, flags);	
//	return (solution);
//}
