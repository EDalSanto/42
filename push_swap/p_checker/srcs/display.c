/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/05 11:05:20 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_spaces(int spaces)
{
	while (spaces--)
		ft_printf(" ");
}

int			longest_int_len(t_stack *stackA)
{
	int		longest;
	size_t	len;
	int		i;

	longest = stackA->nums[0];
	len = ft_int_len(longest);
	i = 1;
	while (i < stackA->cur_size)
	{
		if (ft_int_len(stackA->nums[i]) > len)
		{
			longest = stackA->nums[i];
			len = ft_int_len(stackA->nums[i]);
		}
		i++;
	}
	if (longest < 0)
		len++;
	return (len);
}

void		display_stacks(t_stack *stackA, t_stack *stackB)
{
	int		a;
	int		b;
	int		spaces;

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
