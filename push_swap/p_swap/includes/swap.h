/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 15:31:39 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SWAP_H
# define SWAP_H
# include "libft.h"

typedef struct	s_stack
{
	int	*nums;
	int	cur_size;
	int	max_size;
}				t_stack;

void	swap_first_two(t_stack *stack);
void	swap_both(t_stack *stackA, t_stack *stackB);
int		empty_stack(t_stack *stack);
void	push_on_A(t_stack *stackA, t_stack *stackB);
void	push_on_B(t_stack *stackA, t_stack *stackB);
void	rotate(t_stack *stack);
void	rotate_both(t_stack *stackA, t_stack *stackB);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_both(t_stack *stackA, t_stack *stackB);
void	display_stacks(t_stack *stackA, t_stack *stackB);

#endif
