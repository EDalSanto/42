/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:08:12 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 10:21:13 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		*update_solution(char *solution, char *op)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(solution);
	dst = solution + len;
	ft_strcpy(dst, op);
	ft_strcat(dst, "\n");
	solution = ft_realloc(solution, len + 5);
	return (solution);
}

void		reverse_op(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(stack_a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(stack_b);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(stack_a, stack_b);
}

int			perform_op(char *op, t_stack *stack_a,
					t_stack *stack_b, t_flags *flags)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_first_two(stack_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_first_two(stack_b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(stack_a, stack_b);
	else if (ft_strcmp(op, "pa") == 0)
		push_on_a(stack_a, stack_b);
	else if (ft_strcmp(op, "pb") == 0)
		push_on_b(stack_a, stack_b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(stack_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(stack_b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(stack_a, stack_b);
	else if (ft_strcmp(op, "rra") == 0 || ft_strcmp(op, "rrb") == 0
			|| ft_strcmp(op, "rrr") == 0)
		reverse_op(op, stack_a, stack_b);
	else if (ft_printf("Error\n"))
		exit(1);
	if (flags->v)
		display_stacks(flags, op, stack_a, stack_b);
	return (1);
}

void		find_min(t_stack *stack_a)
{
	int		min;
	int		i;

	min = stack_a->nums[0];
	stack_a->min_num = min;
	i = 1;
	while (i < stack_a->cur_size)
	{
		if (stack_a->nums[i] < min)
		{
			min = stack_a->nums[i];
			stack_a->min_num = min;
			stack_a->min_idx = i;
		}
		i++;
	}
}
