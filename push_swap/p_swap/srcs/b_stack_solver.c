/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 10:53:17 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*move_to_B(char *solution, t_super_stack *super_stack)
{
	int	idx_to_move;
	int	num_to_move;
	int	midA;
	int	midB;
	int	right_place;

	find_min(super_stack->stackB);
	idx_to_move = find_shortest_path_to_sorted_B(super_stack);
	num_to_move = super_stack->stackA->nums[idx_to_move];
	midA = super_stack->stackA->cur_size / 2;
	midB = super_stack->stackB->nums[super_stack->stackB->cur_size / 2];		
	right_place = find_right_location(super_stack->stackB, num_to_move);
	while (((super_stack->moves->rrb)) && ((super_stack->moves->rra)))
	{
		solution = update_solution(solution, "rrr");
		perform_op("rrr", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->rra)--;
		(super_stack->moves->rrb)--;
	}
	while (((super_stack->moves->rrb)))
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->rrb)--;
	}
	while (((super_stack->moves->rra)))
	{
		solution = update_solution(solution, "rra");
		perform_op("rra", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->rra)--;
	}
	while (((super_stack->moves->rb)) && ((super_stack->moves->ra)))
	{
		solution = update_solution(solution, "rr");
		perform_op("rr", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->ra)--;
		(super_stack->moves->rb)--;
	}
	while (((super_stack->moves->rb)))
	{
		solution = update_solution(solution, "rb");
		perform_op("rb", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->rb)--;
	}
	while (((super_stack->moves->ra)))
	{
		solution = update_solution(solution, "ra");
		perform_op("ra", super_stack->stackA, super_stack->stackB, super_stack->flags);
		(super_stack->moves->ra)--;
	}
	solution = update_solution(solution, "pb");
	perform_op("pb", super_stack->stackA, super_stack->stackB, super_stack->flags);
	return (solution);
}

//int		find_max_idx(int *nums, int size)
//{
//	int	i;
//	int	max_num;
//	int	max_idx;
//
//	i = 1;
//	max_num = nums[0];
//	max_idx = 0;
//	while (i < size)
//	{
//		if (nums[i] > max_num)
//		{
//			max_num = nums[i];
//			max_idx = i;
//		}
//		i++;
//	}
//	return (max_idx);
//}

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
	//return (max_num);
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
	solution = update_solution(solution, "pa");
	perform_op("pa", super_stack->stackA, super_stack->stackB, super_stack->flags);
	return (solution);
}

char	*b_solver(char *solution, t_super_stack *super_stack)
{
	while (!empty_stack(super_stack->stackA)) 
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
