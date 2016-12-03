/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 15:59:30 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		is_number(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int		make_stackA(char **av, t_stack *stackA)
{
	int	i;

	i = 1;
	while (i <= stackA->max_size)
	{
		if (!is_number(av[i])) 
			return (0);
		stackA->nums[i - 1] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

static void	setup(t_stack *stackA, t_stack *stackB, int size)
{
	stackA->max_size = size;
	stackA->nums = (int*)malloc(sizeof(int) * size); 
	ft_bzero(stackA->nums, size * sizeof(int));
	stackB->max_size = size;
	stackB->nums = (int*)malloc(sizeof(int) * size); 
	ft_bzero(stackB->nums, size * sizeof(int));
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;

	if ((ac - 1))
	{
		setup(&stackA, &stackB, (ac - 1));
		if (make_stackA(av, &stackA))
			print_int_arr(stackA.nums, (ac - 1));	
		else
			exit(1);
	}
//	free(stackA);
//	free(stackB);
}
