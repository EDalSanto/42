/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 11:00:15 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/13 19:58:26 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fillit.h"
#include "libft.h"

void		display_usage(char *program_name)
{
	ft_putstr("usage: ");
	ft_putstr(program_name + 2);
	ft_putstr(" source_file\n");
}

void		destroy_arr(char **arr)
{
	int		r;

	r = 0;
	while (r < g_tetriminos)
	{
		free(arr[r]);
		r++;
	}
	free(arr);
}

char		**make_arr(char **arr, int fd)
{
	int		r;
	int		c;
	int		n_newlines;
	char	buf[1];

	r = 0;
	while ((read(fd, buf, 1)))
	{
		c = 0;
		n_newlines = 0;
		while (n_newlines != 4)
		{
			if (*buf == '\n')
				n_newlines++;
			else
			{
				arr[r][c] = *buf;
				c++;
			}
			read(fd, buf, 1);
		}
		arr[r][c] = '\0';
		r++;
	}
	return (arr);
}

void		print_arr(char **arr)
{
	int		r;
	int		c;

	r = 0;
	while (r < g_tetriminos)
	{
		c = 0;
		while (arr[r][c])
		{
			ft_putchar(arr[r][c]);
			c++;
			if (c % 4 == 0)
				ft_putchar('\n');
		}
		if (r + 1 != g_tetriminos)
			ft_putchar('\n');
		r++;
	}
}

char		**file_to_arr(char *file)
{
	char	**arr;
	int		i;
	int		fd;

	arr = (char**)malloc(sizeof(char*) * g_tetriminos);
	i = 0;
	while (i < g_tetriminos)
		arr[i++] = (char*)malloc((sizeof(char) * 17));
	fd = open(file, O_RDONLY);
	arr = make_arr(arr, fd);
	close(fd);
	return (arr);
}
