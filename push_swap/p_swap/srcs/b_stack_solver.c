/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/07 12:47:52 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*move_to_B(char *solution, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	int	idx_to_move;
	int	num_to_move;
	int	midA;
	int	midB;

	idx_to_move = find_shortest_path_to_sorted_B(stackA, stackB, flags);
//	ft_printf("idx to move: %d\n", idx_to_move);
	num_to_move = stackA->nums[idx_to_move];
	//move to top of A
	midA = stackA->cur_size / 2;
	if (idx_to_move != 0)
	{
		if (idx_to_move > midA)
		{
			while ((solution = update_solution(solution, "rra")) &&
					stackA->nums[0] != num_to_move)	
			perform_op("rra", stackA, stackB, flags);
		}
		else
		{
			while ((solution = update_solution(solution, "ra")) &&
					stackA->nums[0] != num_to_move)	
			perform_op("ra", stackA, stackB, flags);
		}
	}
	// push on B
	solution = update_solution(solution, "pb");
	perform_op("pb", stackA, stackB, flags);
	//move to B loc
	midB = stackB->nums[stackB->cur_size / 2];		
	//ft_printf("midb: %d, num: %d\n", midB, num_to_move);
	if (midB != num_to_move)
		solution = revsort(solution, stackA, stackB, flags);
//	ft_printf("solution after moveB :%s\n", solution);
	return (solution);
}

char	*b_solver(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	while ((!(is_sorted(stackA->nums, stackA->cur_size) &&
					is_revsorted(stackB->nums, stackB->cur_size) &&
					stackA->nums[0] > stackB->nums[0])) && !empty_stack(stackA))
	{
		solution = move_to_B(solution, stackA, stackB, flags);
	}
	while ((solution = update_solution(solution, "pa")) &&
				stackB->cur_size)	
		perform_op("pa", stackA, stackB, flags);
	return (solution);
}
