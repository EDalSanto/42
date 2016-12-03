/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/02 17:43:36 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_first_two(int *stack)
{
	int	temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
}

void	swap_both(int *stackA, int *stackB)
{
	swap_first_two(stackA);
	swap_first_two(stackB);
}

void	push_on_A(int *stackA, int *stackB)
{
	int	temp;
	int	i;

	i = 0;
	if (stackB[i])
	{
		temp = stackB[i++];
		while (stackB[i])
		{
			stackB[i - 1] = stackb[i];
			i++;
		}
		i = 0;
		while (stackA[i])
		{
			stackA[i + 1]
		}
	}
}

int		make_stack(int ac, char **av, int **stackA)
{
	int	i;
	int	*A;

	i = 1;
	A = *stackA;
	while (i <= (ac - 1))
	{
		ft_printf("arg[%d] is_digit: %d, arg: %s\n", i, ft_isdigit(ft_atoi(av[i])), av[i]);
		if (!ft_isdigit(ft_atoi(av[i]))) 
			return (0);
		A[i] = ft_atoi(av[i]);
		ft_printf("A[i]: %d\n", A[i]);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	*stackA;
	int	*stackB;

	stackA = (int*)malloc(sizeof(int) * (ac - 1));
	ft_bzero(stackA, (ac - 1));
	stackB = (int*)malloc(sizeof(int) * (ac - 1));
	ft_bzero(stackB, (ac - 1));
	if ((ac > 1) && (make_stack(ac, av, &stackA)))
	{
		print_int_arr(stackA, (ac - 1));	
	}
	free(stackA);
	free(stackB);
}