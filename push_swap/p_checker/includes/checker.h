/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:47:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 09:38:33 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

void	swap_first_two(int *stack);
void	swap_both(int *stackA, int *stackB);
int		empty_stack(int *arr, int size);
void	push_on_A(int *stackA, int *stackB, int size);
void	push_on_B(int *stackA, int *stackB, int size);
void	rotate(int *stack, int size);
void	rotate_both(int *stackA, int *stackB, int size);
void	reverse_rotate(int *stack, int size);
void	reverse_rotate_both(int *stackA, int *stackB, int size);
void	display_stacks(int *stackA, int *stackB, int size);

#endif
