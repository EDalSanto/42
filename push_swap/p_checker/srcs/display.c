/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/11 19:32:31 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_spaces(int spaces)
{
	while (spaces--)
		ft_printf(" ");
}

int			longest_int_len(t_stack *stack_a)
{
	int		longest;
	size_t	len;
	int		i;

	longest = stack_a->nums[0];
	len = ft_int_len(longest);
	i = 1;
	while (i < stack_a->cur_size)
	{
		if (ft_int_len(stack_a->nums[i]) > len)
		{
			longest = stack_a->nums[i];
			len = ft_int_len(stack_a->nums[i]);
		}
		i++;
	}
	if (longest < 0)
		len++;
	return (len);
}

void		display_row(int a, int b, t_stack *stack_a, t_stack *stack_b)
{
	int		spaces;

	spaces = longest_int_len(stack_a) + 1;
	if (a < (stack_a->cur_size))
	{
		ft_printf("%d", stack_a->nums[a]);
		print_spaces(spaces - ft_int_len(stack_a->nums[a]));
	}
	else
		print_spaces(spaces);
	if (b < (stack_b->cur_size))
		ft_printf("%d\n", stack_b->nums[b]);
	else
		ft_printf("\n");
}

void		display_stacks(char *op, t_stack *stack_a, t_stack *stack_b)
{
	int		a;
	int		b;
	int		spaces;

	a = 0;
	b = 0;
	spaces = longest_int_len(stack_a) + 1;
	ft_printf("%s\n", op);
	ft_printf("--------\n");
	while ((a < (stack_a->cur_size) || (b < (stack_b->cur_size))))
	{
		display_row(a, b, stack_a, stack_b);
		a++;
		b++;
	}
	ft_printf("-");
	print_spaces(spaces - 1);
	ft_printf("-\na");
	print_spaces(spaces - 1);
	ft_printf("b\n--------\n");
}
