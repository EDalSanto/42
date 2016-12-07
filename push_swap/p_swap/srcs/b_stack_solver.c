/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:12:43 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/06 12:12:47 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*b_stack_solver(char *solution, t_stack *stackA,
		t_stack *stackB, t_flags *flags)
{
	while (!empty_stack(stackA) && !((stackB->nums[0]) < stackA->nums[0]
				&& !empty_stack(stackB) && is_sorted(stackA->nums, stackA->cur_size)))	
	{
		perform_op("pb", stackA, stackB, flags);	
		solution = update_solution(solution, "pb");
		if (!is_revsorted(stackB->nums, stackB->cur_size))
		{
			solution = revsort(solution, stackA, stackB, flags);
		}
	}
	while (!empty_stack(stackB))
	{
		perform_op("pa", stackA, stackB, flags);	
		solution = update_solution(solution, "pa");
	}
	return (solution);
}
