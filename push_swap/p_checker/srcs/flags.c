/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:11:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 10:23:00 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		**check_for_flags(char **av, t_flags *flags, int *ac)
{
	int		s;
	int		c;
	int		args;

	s = 1;
	c = 0;
	args = *ac;
	while ((s < args) && (av[s][c] == '-' || av[s][c] == 'c' ||
			av[s][c] == 'v') && !ft_isdigit(av[s][c + 1]))
	{
		if (av[s][c] == 'v')
			flags->v = 1;
		else if (av[s][c] == 'c')
			flags->c = 1;
		if ((av[s][c] == 'c' || av[s][c] == 'v') && !av[s][c + 1])
		{
			s++;
			c = 0;
			(*ac)--;
		}
		else
			c++;
	}
	return (&(av[s]));
}
