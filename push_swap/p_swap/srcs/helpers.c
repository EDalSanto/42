/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:13:16 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/06 12:13:21 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_right_location_desc(t_stack *stack, int num)
{
	int		i;

	i = 0;
	if (num > stack->nums[0])
		return (i);
	while ((i < (stack->cur_size)) &&
			!((num < stack->nums[i] && (num > stack->nums[i + 1]))))
		i++;
	return (i + 1);
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
