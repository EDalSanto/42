/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 11:45:55 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void	setup_stacks(t_stack *stackA, t_stack *stackB, int size, char **av)
{
	int		nums;
	int		i;

	i = 0;
	nums = 0;
	while (i < size)
	{
		if (!are_numbers(av[i]))
		{
			ft_printf("Error\n");
			exit(1);
		}
		nums += are_numbers(av[i]);
		i++;
	}
	stackA->max_size = nums;
	stackA->cur_size = 0;
	stackA->nums = (int*)malloc(sizeof(int) * nums); 
	stackB->max_size = nums;
	stackB->cur_size = 0;
	stackB->nums = (int*)malloc(sizeof(int) * nums); 
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;
	t_moves	moves;
	t_super_stack	super_stack;

	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		setup_stacks(&stackA, &stackB, (ac - 1), av);
		if (make_stackA(av, (ac - 1), &stackA))
		{
			super_stack.stackA = &stackA;	
			super_stack.stackB = &stackB;
			super_stack.moves = &moves;
			super_stack.flags = &flags;
			zero_super_stack_moves(&super_stack);
			solve(&super_stack);
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	//	free(stackA);
	//	free(stackB);
}
