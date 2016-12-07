/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/07 13:06:44 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			find_right_location_desc(t_stack *stack, int num)
{
	int		i;

	i = 0;
	//ft_printf("num: %d, stack->cur_size: %d\n", num, stack->cur_size);
	if (num > stack->nums[0] || stack->cur_size == 0)
		return (i);
	while ((i < (stack->cur_size)) &&
			!((num < stack->nums[i] && (num > stack->nums[i + 1]))))
		i++;
	return (i + 1);
}

t_stack		copy_stack(t_stack *stack_to_copy)
{
	t_stack	new_stack;
	int		i;

	i = 0;
	new_stack.cur_size = stack_to_copy->cur_size;
	new_stack.max_size = stack_to_copy->max_size;
	new_stack.min_idx = stack_to_copy->min_num;
	new_stack.nums = (int*)malloc(sizeof(int) * new_stack.cur_size);
	while (i < new_stack.cur_size)
	{
		new_stack.nums[i] = stack_to_copy->nums[i]; 
		i++;
	}
	return (new_stack);
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
	if (stackA->nums[indexA] > mid)
	{
		steps +=  move_down_counter(indexA, stackA, stackB, flags);
	}
	else 
	{
		steps +=  move_up_counter(indexA, stackA, stackB, flags);
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
	ft_printf("steps: %d, i: %d\n", min_steps, i);
	min_idx = i;
	i++;
	while ((!(min_steps <= 1)) && i < stackA->cur_size)
	{
		steps = calculate_steps(i, stackA, stackB, flags);
		ft_printf("steps: %d, i: %d\n", steps, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int			move_down_counter(int indexA, t_stack *stackA,
							t_stack *stackB, t_flags *flags)
{
	t_stack	stackAcpy;
	t_stack	stackBcpy;
	int		ops;
	int		rrbs;
	int		swaps;	

	ops = 0; 
	swaps = 0;
	rrbs = find_right_location_desc(stackB, stackA->nums[indexA]);
	ft_printf("rrbs: %d, indexA: %d\n", rrbs, indexA);
	if (rrbs)
		swaps = rrbs - 1;	
	stackAcpy = copy_stack(stackA);
	stackBcpy = copy_stack(stackB);
	while (swaps--)
	{	
		perform_op("sb", &stackAcpy, &stackBcpy, flags);	
		perform_op("rb", &stackAcpy, &stackBcpy, flags);	
		ops += 2;
	}
	while (!is_revsorted(stackB->nums, stackB->cur_size))
	{
		perform_op("rrb", &stackAcpy, &stackBcpy, flags);	
		ops++;
	}
	free(stackAcpy.nums);
	free(stackBcpy.nums);
	return (ops);
}

int			move_up_counter(int indexA, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	t_stack	stackAcpy;
	t_stack	stackBcpy;
	int		ops;
	int		rbs;
	int		swaps;	

	ops = 0;
	swaps = 0;
	rbs = (stackB->cur_size - (find_right_location_desc(stackB, stackA->nums[indexA]))) + 1;
	if (rbs)
		swaps = (rbs - 1);	
	stackAcpy = copy_stack(stackA);
	stackBcpy = copy_stack(stackB);
	while (swaps--)
	{
		perform_op("rrb", &stackAcpy, &stackBcpy, flags);	
		perform_op("sb", &stackAcpy, &stackBcpy, flags);	
		ops += 2;
	}
	while (rbs--)
	{
		perform_op("rb", &stackAcpy, &stackBcpy, flags);	
		ops++;
	}
	free(stackAcpy.nums);
	free(stackBcpy.nums);
	return (ops);
}

char		*move_down(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	int		top;
	int		rrbs;
	int		swaps;	

	top = stackB->nums[0];
	rrbs = find_right_location_desc(stackB, top);
	swaps = rrbs - 1;	
	while (swaps--)
	{	
		solution = update_solution(solution, "sb");
		perform_op("sb", stackA, stackB, flags);	
		solution = update_solution(solution, "rb");
		perform_op("rb", stackA, stackB, flags);	
	}
	while (!is_revsorted(stackB->nums, stackB->cur_size))
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", stackA, stackB, flags);	
	}
	return (solution);
}

char		*move_up(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags)
{
	int		top;
	int		rbs;
	int		swaps;	

	top = stackB->nums[0];
	rbs = (stackB->cur_size - (find_right_location_desc(stackB, top))) + 1;
	swaps = (rbs - 1);	
	while (swaps--)
	{
		solution = update_solution(solution, "rrb");
		perform_op("rrb", stackA, stackB, flags);	
		solution = update_solution(solution, "sb");
		perform_op("sb", stackA, stackB, flags);	
	}
	while (rbs--)
	{
		solution = update_solution(solution, "rb");
		perform_op("rb", stackA, stackB, flags);	
	}
	return (solution);
}

char		*revsort(char *solution, t_stack *stackA,
					t_stack *stackB, t_flags *flags)
{
	int		min;
	int		num_to_sort;
	int		mid;
	
	find_min(stackB);
	min = stackB->min_num; 	
	num_to_sort = stackB->nums[0];
	if ((min == num_to_sort) && (solution = update_solution(solution, "rb")))
		perform_op("rb", stackA, stackB, flags);	
	else if ((num_to_sort > stackB->nums[2]) && (num_to_sort < stackB->nums[1]) && 
			(solution = update_solution(solution, "sb")))
		perform_op("sb", stackA, stackB, flags);	
	mid = stackB->nums[(stackB->cur_size / 2)];
	while (!is_revsorted(stackB->nums, stackB->cur_size))
	{
		if (num_to_sort > mid)
		{
			solution = move_down(solution, stackA, stackB, flags);
		}
		else if (num_to_sort < mid)
		{
			solution = move_up(solution, stackA, stackB, flags);
		}
	}
	return (solution);
}
