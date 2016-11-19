/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 09:36:00 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/13 19:56:49 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_fillit.h"

void		insert_dots(char *row)
{
	int		i;

	i = 0;
	while (i < (g_size * g_size))
		row[i++] = '.';
	row[i] = '\0';
}

void		print_solution(char *solution_arr, int size)
{
	int		i;

	i = 0;
	while (*solution_arr)
	{
		if (i % size == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(*solution_arr);
		i++;
		solution_arr++;
	}
	ft_putchar('\n');
}

char		*make_solution_arr(void)
{
	char	*solution_arr;

	if ((solution_arr = (char*)malloc(sizeof(char) * (g_size * g_size) + 1)))
		insert_dots(solution_arr);
	else
		return (0);
	return (solution_arr);
}

int			highest_sqrt(void)
{
	int		res;
	int		i;

	res = g_tetriminos * 4;
	i = 1;
	while ((i * i) < res)
		i++;
	return (i);
}
