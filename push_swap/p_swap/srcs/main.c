/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/13 17:14:32 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

static void			setup_stacks(t_stack *stack_a, t_stack *stack_b,
							int size, char **av)
{
	int				nums;
	int				i;

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
	stack_a->max_size = nums;
	stack_a->cur_size = 0;
	stack_a->nums = (int*)malloc(sizeof(int) * nums);
	stack_b->max_size = nums;
	stack_b->cur_size = 0;
	stack_b->nums = (int*)malloc(sizeof(int) * nums);
}

int					main(int ac, char **av)
{
	t_stack			stack_a;
	t_stack			stack_b;
	t_flags			flags;
	t_moves			moves;
	t_super_stack	super_stack;

	flags.v = 0;
	flags.c = 0;
	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		setup_stacks(&stack_a, &stack_b, (ac - 1), av);
		if (make_stack_a(av, (ac - 1), &stack_a))
		{
			super_stack.stack_a = &stack_a;
			super_stack.stack_b = &stack_b;
			super_stack.moves = &moves;
			super_stack.flags = &flags;
			zero_super_stack_moves(&super_stack);
			solve(&super_stack);
		}
		else if ((ft_printf("Error\n")))
			exit(1);
	}
	free(stack_a.nums);
	free(stack_b.nums);
}
