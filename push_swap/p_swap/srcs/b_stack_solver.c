/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/08 12:10:46 by edal-san         ###   ########.fr       */
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
	ft_printf("idx to move in move to B: %d\n", idx_to_move);
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
	midB = stackB->nums[stackB->cur_size / 2];		
//	ft_printf("midb: %d, num: %d\n", midB, num_to_move);
	if (midB != num_to_move)
		solution = revsort(solution, stackA, stackB, flags);
//	ft_printf("solution after moveB :%s\n", solution);
	return (solution);
}

int		find_max(int *nums, int size)
{
	int	i;
	int	max_num;
	int	max_idx;

	i = 1;
	max_num = nums[0];
	max_idx = 0;
	while (i < size)
	{
		if (nums[i] > max_num)
		{
			max_num = nums[i];
			max_idx = i;
		}
		i++;
	}
	return (i - 1);
}

char	*push_back_on_A(char *solution, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	int	max;
	int	mid;

	max = find_max(stackB->nums, stackB->cur_size);
	ft_printf("max: %d\n", max);
	mid = stackB->cur_size / 2;
	while (stackB->nums[0] != max)
	{
		if (max < mid)
		{
			solution = update_solution(solution, "rb");
			perform_op("rb", stackA, stackB, flags);
		}
		else
		{
			solution = update_solution(solution, "rrb");
			perform_op("rrb", stackA, stackB, flags);
		}
	}
	solution = update_solution(solution, "pa");
	perform_op("pa", stackA, stackB, flags);
	return (solution);
}

char	*b_solver(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	while (!empty_stack(stackA)) 
	{
		solution = move_to_B(solution, stackA, stackB, flags);
	}
	while (stackB->cur_size)	
		solution = push_back_on_A(solution, stackA, stackB, flags);
	return (solution);
}
