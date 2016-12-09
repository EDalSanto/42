/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/08 21:30:10 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int			get_nums(char *str, t_stack *stackA)
{
	int		sign;
	int		num;
	int		i;

	num = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			num = (num * 10) + (*str - '0');
		if (*str == ' ' || !(*(str + 1)))
		{
			num *= sign;
			if (!is_valid(num, stackA))
			{
				ft_printf("Error\n");
				exit(1);
			}
			i = stackA->cur_size;
			stackA->nums[i] = num;
			stackA->cur_size++;
			num = 0;
			sign = 1;
			i++;
		}
		str++;
	}
	return (1);
}

int			make_stackA(char **av, int ac, t_stack *stackA)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		get_nums(av[i], stackA);
		i++;
	}
	return (1);
}

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

void		solve(t_super_stack *super_stack)
{
	char	*solution;

	solution = ft_strnew(5);
	if (super_stack->flags->v)	
		display_stacks(super_stack->stackA, super_stack->stackB);
	solution = b_solver(solution, super_stack);	
	ft_printf("%s", solution);
}

void		zero_super_stack_moves(t_super_stack *super_stack)
{
	super_stack->moves->rb = 0;
	super_stack->moves->ra = 0;
	super_stack->moves->rr = 0;
	super_stack->moves->rrb = 0;
	super_stack->moves->rra = 0;
	super_stack->moves->rrr = 0;
	super_stack->moves->sb = 0;
	super_stack->moves->sa = 0;
	super_stack->moves->ss = 0;
	super_stack->moves->pb = 0;
	super_stack->moves->pa = 0;
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
