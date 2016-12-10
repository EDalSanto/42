/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/10 10:54:39 by edal-san         ###   ########.fr       */
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
	t_stack		*stackA;
	t_stack		*stackB;
	t_moves		*moves;	
	t_flags		*flags;
}				t_super_stack;

int				make_stackA(char **av, int ac, t_stack *stackA);
int				get_nums(char *str, t_stack *stackA);
void			solve(t_super_stack *super_stack);
char			*reverse_rotations(char *solution, t_super_stack *super_stack);
char			*forward_rotations(char *solution, t_super_stack *super_stack);
char			*move_to_B(char *solution, t_super_stack *super_stack);
void			find_max(t_stack *stack);
void			zero_super_stack_moves(t_super_stack *super_stack);
char			*update_solution(char *solution, char *op);
char			**check_for_flags(char **av, t_flags *flags, int *ac);
char			*move_to_B(char *solution, t_super_stack *super_stack);
char			*b_solver(char *solution, t_super_stack *super_stack);
void			swap_first_two(t_stack *stack);
void			swap_both(t_stack *stackA, t_stack *stackB);
int				empty_stack(t_stack *stack);
int				is_duplicate(t_stack *stack, int num);
int				is_valid(int num, t_stack *stackA);
int				is_sorted(int *nums, int size);
int				is_revsorted(int *nums, int size);
int				are_numbers(char *str);
int				perform_op(char *op, t_stack *stackA,
							t_stack *stackB, t_flags *flags);
void			push_on_A(t_stack *stackA, t_stack *stackB);
void			push_on_B(t_stack *stackA, t_stack *stackB);
void			rotate(t_stack *stack);
void			rotate_both(t_stack *stackA, t_stack *stackB);
void			reverse_rotate(t_stack *stack);
void			reverse_rotate_both(t_stack *stackA, t_stack *stackB);
void			display_stacks(char *op, t_stack *stackA, t_stack *stackB);
void			find_min(t_stack *stack);
char			*move_min_num(char *solution, t_super_stack *super_stack);
char			*handle_three(char *solution, t_super_stack *super_stack);
char			*min_num_solver(char *solution, t_super_stack *super_stack);
int				find_right_location(t_stack *stack, int num);
char			*revsort(char *solution, t_stack *stackA,
						t_stack *stackB, t_flags *flags);
t_stack			copy_stack(t_stack *stack_to_copy);
int				move_down_counter(int indexA, t_stack *stackA, t_stack *stackB, t_flags *flags);
int				move_up_counter(int indexA, t_stack *stackA, t_stack *stackB, t_flags *flags);
int				calculate_steps(int indexA, t_super_stack *super_stack);
int				find_shortest_path_to_sorted_B(t_super_stack *super_stack);


#endif
