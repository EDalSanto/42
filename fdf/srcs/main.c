#include "fdf.h"
#include <stdio.h>

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
	else if (keycode == 6 || keycode == 7)
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
	//printf("keycode: %d\n", keycode);
	return (0);
}

void			center(t_map *map)
{
	if (((map->max_strlen * map->scale) / 2) > X_CENTER)
		map->x_start = (WIDTH - (map->scale * map->max_strlen)) / 2;
	else
		map->x_start = X_CENTER - ((map->max_strlen) * map->scale / 2);
	if (((map->num_lines * map->scale) / 2) > Y_CENTER)
		map->y_start = 0;
	else
		map->y_start = Y_CENTER - ((map->num_lines * map->scale) / 2);
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_map		*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (ac == 2)
	{
		map->num_lines = count_lines(av[1], map);
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		map->angles = init_angles();
		map->points = create_points(av[1], map);
		map->mlx = mlx;
		map->win = win;
		map->scale = SCALE;
		map->zoom_factor = 0;
		map->zoom_sign = 0;
		area_img = (map->num_lines * map->scale) * (map->max_strlen * map->scale); 
		area_win = (WIDTH * LENGTH);
		if ((area_img) < (.7 * (area_win)))
		{
			dif = area_win - area_img; 
			perc = dif / (area_win);
			
		}
		center(map);
		print_inits(map);
		mlx_key_hook(win, my_key_funct, (void*)map);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
