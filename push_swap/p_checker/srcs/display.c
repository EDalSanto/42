/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 15:39:55 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_stacks(t_stack *stackA, t_stack *stackB)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while ((a < (stackA->cur_size) || (b < (stackB->cur_size))))
	{
		if (a < (stackA->cur_size))
			ft_printf("%d ", stackA[a]);
		else
			ft_printf(" ");
		if (b < (stackB->cur_size))
			ft_printf("%d\n", stackB[b]);
		else
			ft_printf("\n");
		a++;
		b++;
	}
	ft_printf("\n- -\na b\n--------\n");
}
