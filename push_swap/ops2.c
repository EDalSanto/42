/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:55:59 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/03 08:56:03 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rotate(int *stack, int size)
{
	int	temp;

	temp = stack[0];
	ft_memmove(&stack[0], &stack[1], (size - 1));
	stack[size - 1] = temp;
}

void	rotate_both(int *stackA, int *stackB, int size)
{
	rotate(stackA, size);
	rotate(stackB, size);
}

void	reverse_rotate(int *stack, int size)
{
	int	temp;

	temp = stack[size - 1];
	ft_memmove(&stack[1], &stack[0], (size - 1));
	stack[0] = temp;
}

void	reverse_rotate_both(int *stackA, int *stackB, int size)
{
	reverse_rotate(stackA, size);
	reverse_rotate(stackB, size);
}
