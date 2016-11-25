#include "fdf.h"
#include <stdio.h>

void			init_angles(t_angles *angles)
{
	angles->a_x = 0.0;
	angles->a_y = 0.0;
	angles->a_z = 0.0;
}

void			update_angle(t_angles *angles, char plane, int sign)
{
	if (plane == 'x')
	{
		if (sign == 1)
			angles->a_x += X_ANGLE * (M_PI / 180.0); 
		else
			angles->a_x -= X_ANGLE * (M_PI / 180.0); 
	}
	else if (plane == 'y')
	{
		if (sign == 1)
			angles->a_y += Y_ANGLE * (M_PI / 180.0);
		else
			angles->a_y -= Y_ANGLE * (M_PI / 180.0);
	}
	else if (plane == 'z')
	{
		if (sign == 1)
			angles->a_z += Z_ANGLE * (M_PI / 180.0);
		else
			angles->a_z -= Z_ANGLE * (M_PI / 180.0);
	}
}

void		z_rotate(t_point **points, double a_z)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]); 
			point->z_prime = point->z_init;
			point->x_prime = (point->x_init * cos(a_z)) - (point->y_init * sin(a_z));
			point->y_prime = (point->x_init * sin(a_z)) + (point->y_init * cos(a_z));
			point_i++;  		
		}
		arr_i++;
	}
}

void		x_rotate(t_point **points, double a_x)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]);			
			point->x_prime = point->x_prime;
			point->y_prime = (point->y_prime * cos(a_x)) - (point->z_prime * sin(a_x));
			point->z_prime = (point->y_prime * sin(a_x)) + (point->z_prime * cos(a_x));
			point_i++;
		}
		arr_i++;
	}
}

void		y_rotate(t_point **points, double a_y)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]);
			point->y_prime = point->y_prime;
			point->x_prime = (point->z_prime * sin(a_y)) + (point->x_prime * cos(a_y));
			point->z_prime = (point->z_prime * cos(a_y)) - (point->x_prime * sin(a_y)); 
			point_i++;
		}
		arr_i++;
	}
}

void			reset_primes(t_point **points)
{
	int		arr_i;
	int		point_i;
	t_point	*point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			point = &(points[arr_i][point_i]);
			point->x_prime = point->x_init;
			point->y_prime = point->y_init;
			point->z_prime = point->z_init;
			point_i++;
		}
		arr_i++;
	}
}

void	translate_points(t_map *map)
{
		reset_primes(map->points);
		z_rotate(map->points, map->angles.a_z);
		x_rotate(map->points, map->angles.a_x);
		y_rotate(map->points, map->angles.a_y);
		mlx_clear_window(map->mlx, map->win);
		print_primes(map->mlx, map->win, map->points);
}

int				rot_key(int keycode)
{
	if (keycode == 12 || keycode == 0 || keycode == 13 || keycode == 1 
		|| keycode == 14 || keycode == 2)
		return (1);
	else
		return (0);
}

void			reset_map(t_map *map)
{
	init_angles(&map->angles);		
	reset_primes(map->points);
	mlx_clear_window(map->mlx, map->win);
	print_inits(map->mlx, map->win, map->points);
}

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
	t_point		**points;
	t_map		*map;
	t_angles	angles;

	map = (t_map*)malloc(sizeof(t_map));
	if (ac == 2)
	{
		init_angles(&angles);
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		points = create_points(av[1]);
		map->points = points;
		map->mlx = mlx;
		map->win = win;
		map->angles = angles;
		print_inits(mlx, win, points);
		mlx_key_hook(win, my_key_funct, (void*)map);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
