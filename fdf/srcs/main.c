#include "fdf.h"

int				my_key_funct(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(1);
	else if (rot_key(keycode))
	{
		if (keycode == 12)
			update_angle(&map->angles, 'x', 1);
		else if (keycode == 0)
			update_angle(&map->angles, 'x', -1);
		else if (keycode == 13)
			update_angle(&map->angles, 'y', -1);
		else if (keycode == 1)
			update_angle(&map->angles, 'y', 1);
		else if (keycode == 14)
			update_angle(&map->angles, 'z', 1);
		else if (keycode == 2)
			update_angle(&map->angles, 'z', -1);
		translate_points(map);
	}
	else if (keycode == 15)
		reset_map(map);
	return (0);
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_map		*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (ac == 2)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		map->angles = init_angles();
		map->points = create_points(av[1]);
		map->mlx = mlx;
		map->win = win;
		print_inits(mlx, win, map->points);
		mlx_key_hook(win, my_key_funct, (void*)map);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
