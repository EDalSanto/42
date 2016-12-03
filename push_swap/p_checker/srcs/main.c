/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 09:44:15 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		make_stackA(int ac, char **av, int **stackA)
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
	int	size;

	size = ac - 1;	
	stackA = (int*)malloc(sizeof(int) * size);
	ft_bzero(stackA, (size - 1) * sizeof(int));
	stackB = (int*)malloc(sizeof(int) * size);
	ft_bzero(stackB, (size - 1) * sizeof(int));
	if ((size) && (make_stackA(ac, av, &stackA)))
	{
		print_int_arr(stackA, (ac - 1));	
	}
	free(stackA);
	free(stackB);
}
