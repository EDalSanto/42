/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 10:49:30 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/08 21:42:48 by edal-san         ###   ########.fr       */
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

	idx_to_move = find_shortest_path_to_sorted_B(super_stack);
	num_to_move = super_stack->stackA->nums[idx_to_move];
	find_min(super_stack->stackB);
	midA = super_stack->stackA->cur_size / 2;
	midB = super_stack->stackB->nums[super_stack->stackB->cur_size / 2];		
	right_place = find_right_location(super_stack->stackB, num_to_move);
	ft_printf("idx_to_move: %d, right_place: %d, rra: %d, rrb: %d, rb: %d, ra: %d\n", idx_to_move, right_place, super_stack->moves->rra, super_stack->moves->rrb, super_stack->moves->rb, super_stack->moves->ra);
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

	//else if (idx_to_move != 0 && idx_to_move <= midA)
	//{
	//	while (super_stack->stackA->nums[0] != num_to_move)	
	//	{
	//		if ((super_stack->moves->rb)--)
	//		{
	//			perform_op("rr", super_stack->stackA,
	//						super_stack->stackB, super_stack->flags);
	//			solution = update_solution(solution, "rr");
	//		}
	//		else
	//		{
	//			perform_op("ra", super_stack->stackA,
	//					super_stack->stackB, super_stack->flags);
	//			solution = update_solution(solution, "ra");
	//		}
	//	}
	//}
//	if (midB != num_to_move)
//		solution = revsort(solution, super_stack);
	solution = update_solution(solution, "pb");
	perform_op("pb", super_stack->stackA, super_stack->stackB, super_stack->flags);
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
	return (max_num);
}

char	*push_back_on_A(char *solution, t_super_stack *super_stack)
{
	int	max;
	int	mid;

	max = find_max(super_stack->stackB->nums, super_stack->stackB->cur_size);
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
		solution = move_to_B(solution, super_stack);
		zero_super_stack_moves(super_stack);
	}
	while (super_stack->stackB->cur_size)	
		solution = push_back_on_A(solution, super_stack);
	return (solution);
}
