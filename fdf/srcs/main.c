/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:35:57 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/30 08:21:03 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			zoom_key(t_map *map, int keycode)
{
	if (keycode == 6)
	{
		map->zoom_factor += 1;
		map->zoom_sign = 1;
	}
	else
	{
		map->zoom_factor -= 1;
		map->zoom_sign = -1;
	}
	zoom_detective(map);
}

int				my_key_funct(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		free_points(map);
		free(map);
		exit(1);
	}
	else if (rot_key(keycode))
	{
		update_angles(keycode, map);
		translate_points(map);
	}
	else if (keycode == 15)
		reset_map(map);
	else if (keycode == 6 || keycode == 7)
		zoom_key(map, keycode);
	return (0);
}

static void		setup_map(t_map *map, char *file, void *mlx, void *win)
{
	map->mlx = mlx;
	map->win = win;
	map->num_lines = count_lines(file, map);
	map->angles = init_angles();
	scale_detective(map);
	map->points = create_points(file, map);
	map->zoom_factor = 0;
	map->zoom_sign = 0;
	map->translate_adj = 0;
	center(map);
}

int				valid_file(char *file)
{
	int			valid;
	int			fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		valid = 0;
	else
		valid = 1;
	close(fd);
	return (valid);
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_map		*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (ac == 2 && valid_file(av[1]))
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		setup_map(map, av[1], mlx, win);
		print_inits(map);
		mlx_key_hook(win, my_key_funct, (void*)map);
		mlx_loop(mlx);
	}
	else
		ft_putstr("Invalid Argument\n");
}
