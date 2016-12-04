/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 10:15:37 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int		make_stackA(char **av, t_stack *stackA)
{
	int	i;

	i = 0;
	while (i < stackA->max_size)
	{
		if (!is_valid(av[i], stackA)) 
			return (0);
		stackA->nums[i] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

static void	setup(t_stack *stackA, t_stack *stackB, int size)
{
	stackA->max_size = size;
	stackA->cur_size = size;
	stackA->nums = (int*)malloc(sizeof(int) * size); 
//	ft_bzero(stackA->nums, size * sizeof(int));
	stackB->max_size = size;
	stackB->cur_size = 0;
	stackB->nums = (int*)malloc(sizeof(int) * size); 
//	ft_bzero(stackB->nums, size * sizeof(int));
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;
	char	*solution;

	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		solution = ft_strnew(5);
		setup(&stackA, &stackB, (ac - 1));
		if (make_stackA(av, &stackA))
		{
			if (flags.v)	
				display_stacks(&stackA, &stackB);
			while(!(is_sorted(stackA.nums, stackA.cur_size) &&
													!stackB.cur_size))
			{	
				if (is_sorted(stackA.nums, stackA.cur_size) &&
					is_revsorted(stackB.nums, stackB.cur_size))
				{
					while (stackB.cur_size)
					{
						perform_op("pa", &stackA, &stackB, &flags);
						solution = update_solution(solution, "pa");
					}
				}
			}
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		if (is_sorted(stackA.nums, stackA.cur_size) &&
												stackB.cur_size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
//	free(stackA);
//	free(stackB);
}
