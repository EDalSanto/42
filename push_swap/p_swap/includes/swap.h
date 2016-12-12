/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 09:14:47 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# define ANSI_COLOR_BLUE "\x1b[34m"
# define ANSI_COLOR_MAGENTA "\x1b[35m"
# include "libft.h"

typedef struct	s_flags
{
	int			v;
	int			c;
}				t_flags;

typedef struct	s_stack
{
	int			*nums;
	int			cur_size;
	int			max_size;
	int			min_idx;
	int			min_num;
	int			max_idx;
	int			max_num;
}				t_stack;

typedef struct	s_moves
{
	int			rb;
	int			ra;
	int			rr;
	int			rrb;
	int			rra;
	int			rrr;
	int			sb;
	int			sa;
	int			ss;
	int			pa;
	int			pb;
}				t_moves;

typedef struct	s_super_stack
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_moves		*moves;
	t_flags		*flags;
}				t_super_stack;

int				make_stack_a(char **av, int ac, t_stack *stack_a);
int				get_nums(char *str, t_stack *stack_a);
void			solve(t_super_stack *super_stack);
char			*reverse_rotations(char *solution, t_super_stack *super_stack);
char			*forward_rotations(char *solution, t_super_stack *super_stack);
char			*move_to_b(char *solution, t_super_stack *super_stack);
char			*handle_three_a(char *solution, t_super_stack *super_stack);
char			*handle_three_b(char *solution, t_super_stack *super_stack);
char			*handle_three_c(char *solution, t_super_stack *super_stack);
char			*handle_three(char *solution, t_super_stack *super_stack);
char			*handle_small_stack(char *solution, t_super_stack *super_stack);
void			find_max(t_stack *stack);
void			zero_super_stack_moves(t_super_stack *super_stack);
char			*update_solution(char *solution, char *op);
char			**check_for_flags(char **av, t_flags *flags, int *ac);
char			*b_solver(char *solution, t_super_stack *super_stack);
void			swap_first_two(t_stack *stack);
void			swap_both(t_stack *stack_a, t_stack *stack_b);
int				empty_stack(t_stack *stack);
int				is_duplicate(t_stack *stack, int num);
int				is_valid(int num, t_stack *stack_a);
int				is_sorted(int *nums, int size);
int				is_revsorted(int *nums, int size);
int				are_numbers(char *str);
int				perform_op(char *op, t_stack *stack_a,
							t_stack *stack_b, t_flags *flags);
void			push_on_a(t_stack *stack_a, t_stack *stack_b);
void			push_on_b(t_stack *stack_a, t_stack *stack_b);
void			rotate(t_stack *stack);
void			rotate_both(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate(t_stack *stack);
void			reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void			display_stacks(char *op, t_stack *stack_a, t_stack *stack_b);
void			find_min(t_stack *stack);
char			*move_min_num(char *solution, t_super_stack *super_stack);
char			*handle_three(char *solution, t_super_stack *super_stack);
char			*min_num_solver(char *solution, t_super_stack *super_stack);
int				find_right_location(t_stack *stack, int num);
char			*revsort(char *solution, t_stack *stack_a,
						t_stack *stack_b, t_flags *flags);
int				calculate_steps(int index_a, t_super_stack *super_stack);
int				find_shortest_path_to_sorted_b(t_super_stack *super_stack);

#endif
