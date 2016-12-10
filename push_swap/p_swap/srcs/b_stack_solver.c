/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 20:46:17 by edal-san         ###   ########.fr       */
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

char	*put_max_on_top(char *solution, t_super_stack *super_stack)
{
	int	max_idx;
	int	max_num;
	int	mid_idx;

	max_idx = super_stack->stackB->max_idx;
	max_num = super_stack->stackB->max_num;
	mid_idx = super_stack->stackB->cur_size / 2;
	while (super_stack->stackB->nums[0] != max_num)
	{
		if (max_idx < mid_idx)
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
	return (solution);
}

char	*assure_proper_orderB(char *solution, t_super_stack *super_stack)
{
	int	a_top;
	int	b_top;
	int	b_next;

	a_top = super_stack->stackA->nums[0]; 
	b_top = super_stack->stackB->nums[0]; 
	b_next = super_stack->stackB->nums[1]; 
	if (!((a_top > b_top && b_top > b_next) || (b_top > b_next && b_next > a_top)
			|| (b_top < a_top && a_top < b_next)))
	{
		solution = update_solution(solution, "sb");
		perform_op("sb", super_stack->stackA, super_stack->stackB, super_stack->flags);
	}
	solution = update_solution(solution, "pb");
	perform_op("pb", super_stack->stackA, super_stack->stackB, super_stack->flags);
	return (solution);
}

char	*b_solver(char *solution, t_super_stack *super_stack)
{
	while (super_stack->stackA->cur_size) 
	{
		find_min(super_stack->stackB);
		find_max(super_stack->stackB);
		if (super_stack->stackB->cur_size == 2)
			solution = assure_proper_orderB(solution, super_stack);
		else
			solution = move_to_B(solution, super_stack);
		zero_super_stack_moves(super_stack);
	}
	find_max(super_stack->stackB);
	solution = put_max_on_top(solution, super_stack);
	while (super_stack->stackB->cur_size)	
	{
		solution = update_solution(solution, "pa");
		perform_op("pa", super_stack->stackA, super_stack->stackB, super_stack->flags);
	}
	return (solution);
}
