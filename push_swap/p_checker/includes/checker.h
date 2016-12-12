/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:07:11 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 09:57:01 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define WHT "\x1B[37m"
# define CYN "\x1B[36m"
# define RESET "\x1B[0m"

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
void			swap_both(t_stack *stack_a, t_stack *stack_b);
int				empty_stack(t_stack *stack);
int				is_duplicate(t_stack *stack, int num);
int				is_valid(long int num, t_stack *stack_a);
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
void			display_stacks(t_flags *flags, char *op,
					t_stack *stack_a, t_stack *stack_b);
void			find_min(t_stack *stack_a);

#endif
