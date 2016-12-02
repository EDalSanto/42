/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/02 14:59:37 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//void	push(int *stack, int n)
//{
//	
//}

int		parse_nums(int ac, char **av, int **stackA)
{
	int	i;
	int	*A;

	i = 0;
	A = *stackA;
	A = (int*)malloc(sizeof(int) * (ac - 1));
	while (i < (ac - 1))
	{
		if (!ft_isdigit(ft_atoi(av[i]))) 
			return (0);
		A[i] = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int	*stackA;

	if (ac > 1 && parse_nums(ac, av, &stackA))
	{
		print_int_arr(stackA, (ac - 1));	
	}
}
