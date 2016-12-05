/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/05 12:29:23 by edal-san         ###   ########.fr       */
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
}				t_stack;

char			*update_solution(char *solution, char *op);
char			**check_for_flags(char **av, t_flags *flags, int *ac);
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
void			display_stacks(t_stack *stackA, t_stack *stackB);
void			find_min(t_stack *stackA);
char			*move_min_num(char *solution, t_stack *stackA,
								t_stack *stackB, t_flags *flags);
char			*min_num_solver(char *solution, t_stack *stackA,
								t_stack *stackB, t_flags *flags);

#endif
