#include "fdf.h"

void		reset_primes(t_point **points)
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

void		translate_points(t_map *map)
{
		reset_primes(map->points);
		z_rotate(map->points, map->angles.a_z);
		x_rotate(map->points, map->angles.a_x);
		y_rotate(map->points, map->angles.a_y);
		mlx_clear_window(map->mlx, map->win);
		print_primes(map->mlx, map->win, map->points);
}

void		reset_map(t_map *map)
{
	map->angles = init_angles();		
	reset_primes(map->points);
	mlx_clear_window(map->mlx, map->win);
	print_inits(map->mlx, map->win, map->points);
}
