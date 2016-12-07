/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 12:29:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/07 09:16:38 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char	*quicksort(char *solution, t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	int	top_half_len;
	int	median;
	int	i;

	median = stackA->nums[stackA->cur_size - 1];	
	top_half_len = 0;
	i = 0;

	ft_printf("begin of quicksort call, cur_size: %d, max: %d, top_half: %d, median: %d\n", stackA->cur_size, stackA->max_size, top_half_len, median);
	if (stackA->cur_size <= 1) 
		return (solution); 
	while (i < (stackA->max_size - 1))
	{	
		ft_printf("i: %d, top: %d\n", i, stackA->nums[0]);
		if (stackA->nums[0] > median)
		{
			perform_op("pb", stackA, stackB, flags);	
			solution = update_solution(solution, "pb");
			top_half_len++;
		}
		else
		{
			perform_op("ra", stackA, stackB, flags);	
			solution = update_solution(solution, "ra");
		}
		i++;
	}
	ft_printf("after first partition------------\ntop_half_len: %d\n", top_half_len);
	i = 0;
	if (top_half_len)
	{
		while (i < (stackA->cur_size - top_half_len))
		{
			perform_op("rra", stackA, stackB, flags);	
			solution = update_solution(solution, "rra");
			i++;
		}
	}
	ft_printf("after reversal------------\n");
	i = 0;
	while (i < top_half_len)
	{
		perform_op("pa", stackA, stackB, flags);	
		solution = update_solution(solution, "pa");
		i++;
	}
	stackA->max_size = top_half_len;
	stackA->cur_size = top_half_len;
	ft_printf("after 1st quicksort call, cur_size: %d, max: %d, top_half: %d\n", stackA->cur_size, stackA->max_size, top_half_len);

	solution = quicksort(solution, stackA, stackB, flags);
	stackA->cur_size = stackA->max_size;
	ft_printf("after 1st quicksort call, cur_size: %d, max: %d, top_half: %d\n", stackA->cur_size, stackA->max_size, top_half_len);
	i = 0;
	while (i < top_half_len)
	{
		perform_op("ra", stackA, stackB, flags);	
		solution = update_solution(solution, "ra");
		i++;
	}
	stackA->cur_size = stackA->cur_size - top_half_len;
	ft_printf("before 2nd quicksort call, cur_size: %d, max: %d, top_half: %d\n", stackA->cur_size, stackA->max_size, top_half_len);
	solution = quicksort(solution, stackA, stackB, flags);
	ft_printf("after last recursive call in frame, cur_size: %d, max: %d, top_half: %d\n", stackA->cur_size, stackA->max_size, top_half_len);
	stackA->cur_size = stackA->max_size;
	i = 0;
	while (i < top_half_len)
	{
		//ft_printf("-----------------------------\nlast solueiotn update, sol: \n%s\n", solution);
		perform_op("rra", stackA, stackB, flags);	
		solution = update_solution(solution, "ra");
		i++;
	}
	return (solution);
}
