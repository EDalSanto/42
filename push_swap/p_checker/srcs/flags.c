/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:11:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 10:21:52 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
