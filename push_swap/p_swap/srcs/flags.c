/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:11:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/09 11:44:34 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

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
