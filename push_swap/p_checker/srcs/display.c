/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 09:38:08 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	display_stacks(int *stackA, int *stackB, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!empty_stack((stackA + i), (size - i)))
			ft_printf("%d ", stackA[i]);
		else
			ft_printf(" ");
		if (!empty_stack((stackB + i), (size - i)))
			ft_printf("%d\n", stackB[i]);
		else
			printf("\n");
		i++;
	}
	printf("\n- -\na b\n--------\n");
}
