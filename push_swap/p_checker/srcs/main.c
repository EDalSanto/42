/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 20:40:17 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_duplicate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->cur_size)
	{
		if (stack->nums[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int		is_valid(char *arg, t_stack *stackA)
{
	if (!is_number(arg) || (ft_atoi(arg) > 2147483647) ||
			((long)ft_atoi(arg) < -2147483648) || is_duplicate(stackA, ft_atoi(arg))) 
		return (0);
	else
		return (1);
}

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

char		**check_for_flags(char **av, t_flags *flags, int *ac)
{
	int		s;
	int		c;
	
	s = 1;
	c = 0;
	while (av[s][c] == '-' && !ft_isdigit(av[s][c + 1]))
	{
		c++;
		if (av[s][c] == 'v')
		{
			flags->v = 1;
			c++;
		}
		if (av[s][c] == 'c')
		{
			flags->c = 1;
			c++;
		}
		(*ac)--;
		s++;
		c = 0;
	}
	return (&(av[s]));
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

int		perform_op(char *op, t_stack *stackA, t_stack *stackB)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_first_two(stackA);
	else if (ft_strcmp(op, "sb") == 0)
		swap_first_two(stackB);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stackA, stackB);
	else if (ft_strcmp(op, "pa") == 0)
		push_on_A(stackA, stackB);
	else if (ft_strcmp(op, "pb") == 0)
		push_on_B(stackA, stackB);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stackA);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stackB);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stackA, stackB);
	else if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(stackA);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(stackB);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(stackA, stackB);
	else
		return (0);
	return (1);
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;
	char	*line;

	if (ac > 1)
	{
		av = check_for_flags(av, &flags, &ac);
		setup(&stackA, &stackB, (ac - 1));
		print_int_arr(stackB.nums, stackB.max_size);
		if (make_stackA(av, &stackA))
		{
			if (flags.v)
				display_stacks(&stackA, &stackB);
			while((get_next_line(0, &line) == 1))
			{	
				if (!perform_op(line, &stackA, &stackB))
				{
					ft_printf("Error\n");
					exit(1);
				}
				if (flags.v)	
					display_stacks(&stackA, &stackB);
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
