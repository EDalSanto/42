/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/06 08:25:44 by edal-san         ###   ########.fr       */
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

static void	setup(t_stack *stackA, t_stack *stackB, int size, char **av)
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

char		*revsort(char *solution, t_stack *stack, t_flags *flags)
{
	int		min;
	int		num_to_sort;
	int		mid;

	min = find_min(stack);
	num_to_sort = stack->nums[0];
	if ((min == num_to_sort) && (solution = update_solution(solution, "rb")))
		perform_op("rb", stack, flags);	
	else if ((num_to_sort > stack->nums[2]) && (num_to_sort < stack->nums[1])
			(solution = update_solution(solution, "sb")))
		perform_op("sb", stack, flags);	
	mid = stack->nums[cur_size / 2];
	while (!is_revsorted(stack->nums, stack->cur_size))
	{
		if (num_to_sort > mid)
		{
			solution = move_down(stack, num_to_sort);
		}
		else if (num_to_sort < mid)
		{
			solution = move_up(stack, num_to_sort);
		}
	}
	return (solution);
}

char		*b_stack_solver(char *solution, t_stack *stackA,
		t_stack *stackB, t_flags *flags)
{
	while (!empty(stackA))	
	{
		perform_op("pb", stackA, stackB, flags);	
		solution = update_solution(solution, "pb");
		if (!is_revsorted(stackB->nums, stackB->cur_size))
		{
			solution = revsort(solution, stackB, flags);
		}
	}
}

void		solve(t_stack *stackA, t_stack *stackB, t_flags *flags)
{
	char	*solution;

	solution = ft_strnew(5);
	if (flags->v)	
		display_stacks(stackA, stackB);
	//	solution = min_num_solver(solution, stackA, stackB, flags);	
	solution = b_stack_solver(solution, stackA, stackB, flags);
	ft_printf("%s", solution);
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;

	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		setup(&stackA, &stackB, (ac - 1), av);
		if (make_stackA(av, (ac - 1), &stackA))
			solve(&stackA, &stackB, &flags);
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
	}
	//	free(stackA);
	//	free(stackB);
}
