/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/04 20:15:16 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_spaces(int spaces)
{
	while (spaces--)
		ft_printf(" ");
}

int		longest_int_len(t_stack *stackA)
{
	int	longest;
	int	i;

	longest = stackA->nums[0];
	i = 1;
	while (i < stackA->cur_size)
	{
		if (stackA->nums[i] > longest)
			longest = stackA->nums[i];
		i++;
	}
	return (ft_int_len(longest));
}

void	display_stacks(t_stack *stackA, t_stack *stackB)
{
	int	a;
	int	b;
	int	spaces;

	a = 0;
	b = 0;
	spaces = longest_int_len(stackA) + 1;
	ft_printf("--------\n");
	while ((a < (stackA->cur_size) || (b < (stackB->cur_size))))
	{
		if (a < (stackA->cur_size))
		{
			ft_printf("%d", stackA->nums[a]);
			print_spaces(spaces - ft_int_len(stackA->nums[a]));
		}
		else
			print_spaces(spaces);
		if (b < (stackB->cur_size))
			ft_printf("%d\n", stackB->nums[b]);
		else
			ft_printf("\n");
		a++;
		b++;
	}
	ft_printf("-"); 
	print_spaces(spaces - 1);
	ft_printf("-\na");
	print_spaces(spaces - 1);
	ft_printf("b\n--------\n");
}
