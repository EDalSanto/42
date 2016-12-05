/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/05 11:17:19 by edal-san         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;
	int		top;
	char	*solution;

	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		setup(&stackA, &stackB, (ac - 1), av);
		if (make_stackA(av, (ac - 1), &stackA))
		{
			solution = ft_strnew(5);
			if (flags.v)	
				display_stacks(&stackA, &stackB);
			while(!(is_sorted(stackA.nums, stackA.cur_size) &&
													!stackB.cur_size))
			{	
				find_min(&stackA);
				top = stackA.nums[0];
				while (top != stackA.min_num)		
				{
					if (stackA.min_idx == 1)
					{
						perform_op("sa", &stackA, &stackB, &flags);	
						solution = update_solution(solution, "sa");
					}
					else if (stackA.min_idx > (stackA.cur_size / 2))	
					{
						perform_op("rra", &stackA, &stackB, &flags);	
						solution = update_solution(solution, "rra");
					}
					else if (stackA.min_idx <= (stackA.cur_size / 2))
					{
						perform_op("ra", &stackA, &stackB, &flags);	
						solution = update_solution(solution, "ra");
					}	
					top = stackA.nums[0];
				}
				if (!is_sorted(stackA.nums, stackA.cur_size))
				{
					perform_op("pb", &stackA, &stackB, &flags);
					solution = update_solution(solution, "pb");
				}
				else
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
		if (is_sorted(stackA.nums, stackA.cur_size) && (stackB.cur_size == 0))
			ft_printf("%s", solution);
		else
			ft_printf("KO\n");
	}
//	free(stackA);
//	free(stackB);
}
