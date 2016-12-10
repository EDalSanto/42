/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 17:39:22 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void	find_max(t_stack *stack)
{
	int	i;
	int	max_num;
	int	max_idx;

	i = 1;
	max_num = stack->nums[0];
	max_idx = 0;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] > max_num)
		{
			max_num = stack->nums[i];
			max_idx = i;
		}
		i++;
	}
	stack->max_idx = max_idx;
	stack->max_num = max_num;
}

char	*push_back_on_A(char *solution, t_super_stack *super_stack)
{
	int	max;
	int	mid;

	max = super_stack->stackB->max_num;
	mid = super_stack->stackB->nums[super_stack->stackB->cur_size / 2];
	while (super_stack->stackB->nums[0] != max)
	{
		if (max < mid)
		{
			solution = update_solution(solution, "rb");
			perform_op("rb", super_stack->stackA,
					super_stack->stackB, super_stack->flags);
		}
		else
		{
			solution = update_solution(solution, "rrb");
			perform_op("rrb", super_stack->stackA,
					super_stack->stackB, super_stack->flags);
		}
	}
//	if (super_stack->stackA->nums[super_stack->stackA->cur_size - 1] >
//			super_stack->stackA->	nums[0])
//	{
//		solution = update_solution(solution, "rra");
//		perform_op("rra", super_stack->stackA, super_stack->stackB, super_stack->flags);
//	}
	solution = update_solution(solution, "pa");
	perform_op("pa", super_stack->stackA, super_stack->stackB, super_stack->flags);
	return (solution);
}

char	*b_solver(char *solution, t_super_stack *super_stack)
{
	while (super_stack->stackA->cur_size) 
	{
		find_min(super_stack->stackB);
		find_max(super_stack->stackB);
		solution = move_to_B(solution, super_stack);
		zero_super_stack_moves(super_stack);
	}
	while (super_stack->stackB->cur_size)	
	{
		find_max(super_stack->stackB);
		solution = push_back_on_A(solution, super_stack);
	}
	return (solution);
}
