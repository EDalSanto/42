/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 10:08:12 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 09:16:32 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

char		*move_to_b(char *solution, t_super_stack *super_stack)
{
	int		idx_to_move;
	int		num_to_move;
	int		mid_a;
	int		mid_b;
	int		right_place;

	idx_to_move = find_shortest_path_to_sorted_b(super_stack);
	num_to_move = super_stack->stack_a->nums[idx_to_move];
	mid_a = super_stack->stack_a->cur_size / 2;
	mid_b = super_stack->stack_b->nums[super_stack->stack_b->cur_size / 2];
	right_place = find_right_location(super_stack->stack_b, num_to_move);
	solution = reverse_rotations(solution, super_stack);
	solution = forward_rotations(solution, super_stack);
	solution = update_solution(solution, "pb");
	perform_op("pb", super_stack->stack_a,
				super_stack->stack_b, super_stack->flags);
	return (solution);
}

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
	if (flags->v)
		display_stacks(op, stack_a, stack_b);
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
	else if ((ft_strcmp(op, "rra") == 0) ||
		(ft_strcmp(op, "rrb") == 0) || (ft_strcmp(op, "rrr") == 0))
		reverse_op(op, stack_a, stack_b);
	else if ((ft_printf("Error\n")))
		exit(1);
	return (1);
}

void		solve(t_super_stack *super_stack)
{
	char	*solution;

	solution = ft_strnew(5);
	if (is_sorted(super_stack->stack_a->nums, super_stack->stack_a->cur_size))
		return ;
	if (super_stack->flags->v)
		display_stacks("Initial",
					super_stack->stack_a, super_stack->stack_b);
	if (super_stack->stack_a->cur_size <= 3)
		solution = handle_small_stack(solution, super_stack);
	else if (super_stack->stack_a->cur_size < 10)
		solution = min_num_solver(solution, super_stack);
	else
		solution = b_solver(solution, super_stack);
	if (super_stack->flags->v)
		display_stacks("Final", super_stack->stack_a, super_stack->stack_b);
	ft_printf("%s", solution);
	free(solution);
}
