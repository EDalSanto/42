#include "fdf.h"
#include <stdio.h>

void			init_angles(t_angles *angles)
{
	angles->a_x = X_ANGLE * (M_PI / 180.0);
	angles->a_y = Y_ANGLE * (M_PI / 180.0);
	angles->a_z = Z_ANGLE * (M_PI / 180.0);
}

void			update_angle(t_angles *angle, char angle)
{
	if (angle == 'x')
		angles->a_x += X_ANGLE * (M_PI / 180.0); 
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
			point->x_prime = (point->x_init * cos(a_z)) - (point->y_init * sin(a_z));
			point->y_prime = (point->x_init * sin(a_z)) + (point->y_init * cos(a_z));
			point->z_prime = point->z_init;
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
			point->x_prime = point->x_init;
			point->y_prime = (point->y_init * cos(a_x)) - (point->z_init * sin(a_x));
			point->z_prime = (point->y_init * sin(a_x)) + (point->z_init * cos(a_x));
			//printf("x_prime: %lf, y_prime: %lf, z_prime: %lf\n", point->x_prime, point->y_prime, point->z_prime);
			//printf("\n");
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
			point->x_prime = (point->z_init * sin(a_y)) + (point->x_init * cos(a_y));
			point->y_prime = point->y_init;
			point->z_prime = (point->z_init * cos(a_y)) - (point->x_init * sin(a_y)); 
			point_i++;
		}
		arr_i++;
	}
}

int				my_key_funct(int keycode, t_map *map)
{
	if (keycode == 53)
		exit(1);
	else if (keycode == 12)
	{
		x_rotate(map->points, angles.a_x);
		mlx_clear_window(map->mlx, map->win);
		print_primes(map->mlx, map->win, map->points);
	}
	//else if (keycode == 0)
	//	//x_neg_rotate(points, angles->a_x);
	//else if (keycode == 13)
	//	//y_neg_roate(points, angles->a_y);
	//else if (keycode == 1)
	//	//y_pos_rotate(points, angles->a_y);	
	else if (keycode == 14)
	{
		z_rotate(map->points, angles.a_z);
		mlx_clear_window(map->mlx, map->win);
		print_primes(map->mlx, map->win, map->points);
	}
	//else if (keycode == 2)
	//	//z_neg_rotate(points, angles->a_z);	
	printf("key event %d\n", keycode);
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
		print_inits(mlx, win, points);
		mlx_key_hook(win, my_key_funct, (void*)map);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
