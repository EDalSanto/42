/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 10:06:34 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/13 19:50:13 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

int				*block_indexes(char *row)
{
	int			*b_idxs;
	int			i;
	int			c;

	c = 0;
	i = 0;
	b_idxs = (int*)malloc(sizeof(int) * 4);
	while (i < 4)
	{
		if (row[c] == '#')
		{
			b_idxs[i] = c;
			i++;
		}
		c++;
	}
	return (b_idxs);
}

static int		count_empty_spaces(char *solution_arr)
{
	int			empties;

	empties = 0;
	while (*solution_arr)
	{
		if (*solution_arr == '.')
			empties++;
		solution_arr++;
	}
	return (empties);
}

static int		solve(char *solution_arr, t_offsets *input_arr, int ia_i)
{
	int			sa_i;

	if (count_empty_spaces(solution_arr) == g_spaces)
		return (1);
	sa_i = 0;
	while (solution_arr[sa_i])
	{
		if (valid_placement(solution_arr, sa_i, input_arr[ia_i]))
		{
			place_tetri(solution_arr, sa_i, input_arr[ia_i]);
			if (solve(solution_arr, input_arr, ++ia_i))
				return (1);
			remove_tetri(solution_arr, sa_i, input_arr[--ia_i]);
		}
		sa_i++;
	}
	return (0);
}

void			solver(char **tetri_arr)
{
	char		*solution_arr;
	int			solved;
	int			i;
	int			ia_i;
	t_offsets	*input_arr;

	input_arr = make_input_arr(tetri_arr);
	solved = 0;
	i = 0;
	ia_i = 0;
	while (!solved)
	{
		g_size = highest_sqrt() + i;
		g_spaces = (g_size * g_size) - (4 * g_tetriminos);
		solution_arr = make_solution_arr();
		if (solve(solution_arr, input_arr, ia_i))
		{
			solved = 1;
			print_solution(solution_arr, g_size);
		}
		free(solution_arr);
		i++;
	}
	free(input_arr);
}

int				main(int argc, char **argv)
{
	char		**tetri_arr;
	int			fd;

	if (argc == 2)
	{
		if (valid_file(fd = open(argv[1], O_RDONLY)))
		{
			tetri_arr = file_to_arr(argv[1]);
			valid_blocks(tetri_arr) ? solver(tetri_arr) :
				ft_putstr_fd("error\n", 2);
			destroy_arr(tetri_arr);
		}
		else
		{
			ft_putstr_fd("error\n", 2);
			exit(1);
		}
		close(fd);
	}
	else
	{
		display_usage(argv[0]);
		exit(1);
	}
	return (0);
}
