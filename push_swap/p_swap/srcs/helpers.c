/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/08 12:23:08 by edal-san         ###   ########.fr       */
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
	find_min(stack);
	if (stack->cur_size == 0 ||
			(num > stack->nums[0] && num < stack->nums[stack->cur_size - 1]) || 
			(num < stack->min_num && stack->nums[0] == stack->min_num))
		return (0);
	else if (num < stack->min_num)
	{
		return (stack->cur_size - min_idx);
	}
	while (i < (stack->cur_size - 1)) 
	{
		if (num > stack->nums[i] && (num < stack->nums[i + 1]))
		{
			dif = stack->nums[i + 1] - stack->nums[i];	
			if (dif < min_dif)
				right_loc = i + 1;
		}
		i++;
	}
	ft_printf("frl: num: %d, stack->cur_size: %d, loc: %d\n", num, stack->cur_size, right_loc);
	return (right_loc);
}

t_stack		copy_stack(t_stack *stack_to_copy)
{
	t_stack	new_stack;
	int		i;

	i = 0;
	new_stack.cur_size = stack_to_copy->cur_size;
	new_stack.max_size = stack_to_copy->max_size;
	new_stack.min_idx = stack_to_copy->min_num;
	new_stack.nums = (int*)malloc(sizeof(int) * new_stack.max_size);
	while (i < new_stack.cur_size)
	{
		new_stack.nums[i] = stack_to_copy->nums[i]; 
		i++;
	}
	return (new_stack);
}

void		sim_move_B(int indexA, t_stack *stackAcpy, t_stack *stackBcpy, t_flags *flags)
{
	int		num_to_move;
	int		midA;

	num_to_move = stackAcpy->nums[indexA];
	midA = stackAcpy->cur_size / 2;
	if (indexA != 0)
	{
		if (indexA > midA)
		{
			while (stackAcpy->nums[0] != num_to_move)
				perform_op("rra", stackAcpy, stackBcpy, flags);
		}
		else
		{
			while (stackAcpy->nums[0] != num_to_move)
				perform_op("ra", stackAcpy, stackBcpy, flags);
		}
	}
	perform_op("pb", stackAcpy, stackBcpy, flags);
}

int			calculate_steps(int indexA, t_stack *stackA,
							t_stack *stackB, t_flags *flags)
{
	int		steps;
	int		mid;
	int		flag_holder;

	steps = 0;
	mid = 0;
	//Stack A move to top for push
	if (indexA == 0)
		steps = 0;
	else if (indexA <= stackA->cur_size / 2)
		steps += indexA;
	else
		steps += stackA->cur_size - indexA;
	//Push B
	steps++;
	// Calculate B steps
	mid = stackB->nums[(stackB->cur_size / 2)];
	//ft_printf("indexA: %d\n", indexA);
	flag_holder = flags->v;
	flags->v = 0;
	find_min(stackB);	
	if ((stackA->nums[indexA] <= stackB->min_num))
		steps++;
	else if ((stackA->nums[indexA] > stackB->nums[1]) &&
				(stackA->nums[indexA] < stackB->nums[0])) 
		steps++;
	else if (stackA->nums[indexA] > mid)
	{
		steps += find_right_location(stackB, stackA->nums[indexA]);
	}
	else
	{
		steps += stackB->cur_size - find_right_location(stackB, stackA->nums[indexA]);
	}
	flags->v = flag_holder;
	return (steps);
}

int			find_shortest_path_to_sorted_B(t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	int		min_steps;
	int		min_idx;
	int		i;
	int		steps;

	i = 0;
	min_steps = calculate_steps(i, stackA, stackB, flags);
	//ft_printf("steps: %d, i: %d, num: %d\n", min_steps, i, stackA->nums[i]);
	min_idx = i;
	i++;
	while ((!(min_steps <= 1)) && i < stackA->cur_size)
	{
		steps = calculate_steps(i, stackA, stackB, flags);
	//	ft_printf("steps: %d, i: %d\n", steps, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

char		*revsort(char *solution, t_stack *stackA,
					t_stack *stackB, t_flags *flags)
{
	int		min;
	int		num_to_sort;
	int		mid;
	int		right_place;
	int		i;
	
	find_min(stackB);
	min = stackB->min_num; 	
	num_to_sort = stackA->nums[0];
	right_place = find_right_location(stackB, num_to_sort);
	i = right_place;
	mid = stackB->cur_size / 2;
	ft_printf("revsort mid: %d\n", mid);
	ft_printf("revsort right_place: %d, num: %d\n", right_place, num_to_sort);
	if (right_place <= mid)
	{
		while (i--)
		{
			solution = update_solution(solution, "rb");
			perform_op("rb", stackA, stackB, flags);
		}
	}
	else
	{
		ft_printf("mid: %d, size: %d\n", mid, stackB->cur_size);
		i = stackB->cur_size - i;
		while (i--)
		{
		solution = update_solution(solution, "rrb");
			perform_op("rrb", stackA, stackB, flags);
		}
	}
	solution = update_solution(solution, "pb");
	perform_op("pb", stackA, stackB, flags);	
	return (solution);
}
