/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 07:50:35 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 17:08:39 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		make_stackA(char **av, t_stack *stackA)
{
	int	i;

	i = 0;
	while (i < stackA->max_size)
	{
		if (!is_number(av[i])) 
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
	while (av[s][c] == '-')
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
		ft_printf("ac before: %d\n", *ac);
		(*ac)--;
		ft_printf("ac after: %d\n", *ac);
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
	ft_bzero(stackA->nums, size * sizeof(int));
	stackB->max_size = size;
	stackB->cur_size = 0;
	stackB->nums = (int*)malloc(sizeof(int) * size); 
	ft_bzero(stackB->nums, size * sizeof(int));
}

int			main(int ac, char **av)
{
	t_stack	stackA;
	t_stack stackB;
	t_flags	flags;

	if ((ac - 1))
	{
		av = check_for_flags(av, &flags, &ac);
		ft_printf("out of checkflags av[0]: %s\n", av[0]);
		setup(&stackA, &stackB, (ac - 1));
		if (make_stackA(av, &stackA))
		{
			if (flags.v)	
				display_stacks(&stackA, &stackB);
		}
		else
			exit(1);
	}
//	free(stackA);
//	free(stackB);
}
