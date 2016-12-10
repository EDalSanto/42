/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_num_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:30:29 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/10 11:21:42 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*move_min_num(char *solution, t_super_stack *super_stack)
{
	if (super_stack->stackA->min_idx == 1)
	{
		perform_op("sa", super_stack->stackA,
					super_stack->stackB, super_stack->flags);	
		solution = update_solution(solution, "sa");
	}
	else if (super_stack->stackA->min_idx > (super_stack->stackA->cur_size / 2))	
	{	
		perform_op("rra", super_stack->stackA,
					super_stack->stackB, super_stack->flags);	
		solution = update_solution(solution, "rra");
	}
	else if (super_stack->stackA->min_idx <= (super_stack->stackA->cur_size / 2))
	{
		perform_op("ra", super_stack->stackA,
					super_stack->stackB, super_stack->flags);	
		solution = update_solution(solution, "ra");
	}
	return (solution);
}

char	*min_num_solver(char *solution, t_super_stack *super_stack)
{
	int		top;

	while(!(is_sorted(super_stack->stackA->nums, super_stack->stackA->cur_size)
				&& !super_stack->stackB->cur_size))
	{	
		if (super_stack->stackA->cur_size == 3)
			solution = handle_three(solution, super_stack);
		find_min(super_stack->stackA);
		while ((top = super_stack->stackA->nums[0]) && top !=
				super_stack->stackA->min_num)		
			solution = move_min_num(solution, super_stack);
		if ((solution = update_solution(solution, "pb")) &&
				!is_sorted(super_stack->stackA->nums, super_stack->stackA->cur_size))
			perform_op("pb", super_stack->stackA,
						super_stack->stackB, super_stack->flags);
		else
		{
			while ((solution = update_solution(solution, "pa")) &&
					super_stack->stackB->cur_size)	
				perform_op("pa", super_stack->stackA,
							super_stack->stackB, super_stack->flags);
		}
	}
	return (solution);
}

void		find_min(t_stack *stack)
{
	int		min_num;
	int		min_idx;
	int		i;

	min_num = stack->nums[0];
	min_idx = 0;;
	i = 1;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] < min_num)	
		{
			min_num = stack->nums[i];
			min_idx = i;
		}
		i++;
	}
	stack->min_num = min_num;
	stack->min_idx = min_idx;
}
