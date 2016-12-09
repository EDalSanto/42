/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_num_solve.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 12:30:29 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 12:25:25 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*move_min_num(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	if (stackA->min_idx == 1)
	{
		perform_op("sa", stackA, stackB, flags);	
		solution = update_solution(solution, "sa");
	}
	else if (stackA->min_idx > (stackA->cur_size / 2))	
	{	
		perform_op("rra", stackA, stackB, flags);	
		solution = update_solution(solution, "rra");
	}
	else if (stackA->min_idx <= (stackA->cur_size / 2))
	{
		perform_op("ra", stackA, stackB, flags);	
		solution = update_solution(solution, "ra");
	}
	return (solution);
}

char	*min_num_solver(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	int		top;

	while(!(is_sorted(stackA->nums, stackA->cur_size) &&
													!stackB->cur_size))
	{	
		find_min(stackA);
		while ((top = stackA->nums[0]) && top != stackA->min_num)		
			solution = move_min_num(solution, stackA, stackB, flags);
		if ((solution = update_solution(solution, "pb")) &&
				!is_sorted(stackA->nums, stackA->cur_size))
			perform_op("pb", stackA, stackB, flags);
		else
		{
			while ((solution = update_solution(solution, "pa")) &&
					stackB->cur_size)	
				perform_op("pa", stackA, stackB, flags);
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
