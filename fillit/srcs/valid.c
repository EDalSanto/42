/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 13:45:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/09 14:57:06 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

static int	count_blocks(char *row)
{
	int		c;
	int		n_blocks;

	c = 0;
	n_blocks = 0;
	while (row[c])
	{
		if (row[c] == '#')
			n_blocks++;
		c++;
	}
	return (n_blocks == 4) ? (1) : (0);
}

static int	touch_detective(char *row)
{
	int		j;
	int		i;
	int		touches;
	int		*b;

	i = 0;
	touches = 0;
	b = block_indexes(row);
	while (i < 4)
	{
		j = 0;
		while (j < 4 && (i != 3 || j != 3))
		{
			if (i == j)
				j++;
			if ((b[i] / 4 == b[j] / 4) && (ABS(b[i] - b[j]) == 1))
				touches++;
			if ((b[i] % 4 == b[j] % 4) && (ABS(b[i] / 4 - b[j] / 4) == 1))
				touches++;
			j++;
		}
		i++;
	}
	free(b);
	return (touches == 6 || touches == 8) ? (1) : (0);
}

int			valid_blocks(char **arr)
{
	int		r;

	r = 0;
	while (r < g_tetriminos)
	{
		if (!count_blocks(arr[r]) || !touch_detective(arr[r]))
			return (0);
		r++;
	}
	return (1);
}

static int	examine_file(int n_lines, int n_chars, int fd, char *buf)
{
	while (read(fd, buf, 1))
	{
		if (NON_VALID(*buf))
			return (0);
		else if (*buf == '\n')
		{
			n_lines++;
			read(fd, buf, 1);
			if (n_chars != 4 || ((*buf == '\n') &&
						(n_lines != 4)) || NON_VALID(*buf))
				return (0);
			n_chars = 0;
			if ((*buf == '\n') && (n_lines == 4))
			{
				n_lines = 0;
				g_tetriminos++;
			}
			else
				n_chars++;
		}
		else
			n_chars++;
	}
	return (*buf == '\n') ? (1) : (0);
}

int			valid_file(int fd)
{
	int		n_lines;
	int		n_chars;
	char	buf[1];

	if (fd == -1)
		return (0);
	n_lines = 0;
	n_chars = 0;
	return (examine_file(n_lines, n_chars, fd, buf) == 0) ? (0) : (1);
}
