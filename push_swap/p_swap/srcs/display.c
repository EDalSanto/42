/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:35:14 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/14 11:33:27 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

void		handle_acolor(char *op, int a, t_stack *stack_a)
{
	if (((ft_strcmp(op, "pb") == 0) ||
				(ft_strcmp(op, "pa") == 0)) && a == 0)
		ft_printf("%s%d%s", CYN, stack_a->nums[a], RESET);
	else if (((ft_strcmp(op, "sa") == 0) && (a == 0 || a == 1)))
		ft_printf("%s%d%s", CYN, stack_a->nums[a], RESET);
	else if (((ft_strcmp(op, "ra") == 0) || (ft_strcmp(op, "rr") == 0)))
		ft_printf("%s%d%s", CYN, stack_a->nums[a], RESET);
	else if (((ft_strcmp(op, "rra") == 0) ||
				(ft_strcmp(op, "rrr") == 0)))
		ft_printf("%s%d%s", CYN, stack_a->nums[a], RESET);
	else
		ft_printf("%d", stack_a->nums[a]);
}

void		handle_bcolor(char *op, int b, t_stack *stack_b)
{
	if (((ft_strcmp(op, "pb") == 0) || (ft_strcmp(op, "pa") == 0)) && b == 0)
		ft_printf("%s%d%s\n", CYN, stack_b->nums[b], RESET);
	else if (((ft_strcmp(op, "sb") == 0) && (b == 0 || b == 1)))
		ft_printf("%s%d%s\n", CYN, stack_b->nums[b], RESET);
	else if (((ft_strcmp(op, "rb") == 0) || (ft_strcmp(op, "rr") == 0)))
		ft_printf("%s%d%s\n", CYN, stack_b->nums[b], RESET);
	else if (((ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0)))
		ft_printf("%s%d%s\n", CYN, stack_b->nums[b], RESET);
	else
		ft_printf("%d\n", stack_b->nums[b]);
}

void		display_a(char *op, t_flags *flags, int a, t_stack *stack_a)
{
	int		spaces;

	spaces = longest_int_len(stack_a) + 1;
	if (a < (stack_a->cur_size))
	{
		if (flags->c)
			handle_acolor(op, a, stack_a);
		else
			ft_printf("%d", stack_a->nums[a]);
	}
	else
		print_spaces(1);
	print_spaces(spaces - ft_int_len(stack_a->nums[a]));
}

void		display_b(char *op, t_flags *flags, int b, t_stack *stack_b)
{
	if (b < (stack_b->cur_size))
	{
		if (flags->c)
			handle_bcolor(op, b, stack_b);
		else
			ft_printf("%d\n", stack_b->nums[b]);
	}
	else
		ft_printf("\n");
}

void		display_stacks(t_flags *flags, char *op,
							t_stack *stack_a, t_stack *stack_b)
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
		display_a(op, flags, a, stack_a);
		display_b(op, flags, b, stack_b);
		a++;
		b++;
	}
	ft_printf("-");
	print_spaces(spaces - 1);
	ft_printf("-\na");
	print_spaces(spaces - 1);
	ft_printf("b\n--------\n");
}
