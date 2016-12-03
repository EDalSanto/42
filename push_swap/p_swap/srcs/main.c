/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 15:29:27 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

//int		make_stackA(int ac, char **av, t_stack stackA)
//{
//	int	i;
//	int	*A;
//
//	i = 1;
//	A = *stackA;
//	while (i <= (ac - 1))
//	{
//		ft_printf("arg[%d] is_digit: %d, arg: %s\n", i, ft_isdigit(ft_atoi(av[i])), av[i]);
//		if (!ft_isdigit(ft_atoi(av[i]))) 
//			return (0);
//		A[i] = ft_atoi(av[i]);
//		ft_printf("A[i]: %d\n", A[i]);
//		i++;
//	}
//	return (1);
//}

static void	setup(t_stack *stackA, t_stack *stackB, int size)
{
	stackA->nums = (int*)malloc(sizeof(int) * size); 
	ft_bzero(stackA->nums, size * sizeof(int));
	stackB->nums = (int*)malloc(sizeof(int) * size); 
	ft_bzero(stackB->nums, size * sizeof(int));
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;

	(void)av;
	if ((ac - 1))
	{
		setup(&stackA, &stackB, (ac - 1));
		//make_stackA(ac, av, &stackA);
		print_int_arr(stackA.nums, (ac - 1));	
	}
//	free(stackA);
//	free(stackB);
}
