#include "fdf.h"
#include <stdio.h>

void			init_angles(t_angles *angles)
{
	angles->a_x = 45.0 * (M_PI / 180.0);
	angles->a_y = 45.0 * (M_PI / 180.0);
	angles->a_z = 45.0 * (M_PI / 180.0);
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

int				my_key_funct(int keycode, t_point **points)
{
	t_angles	angles;

	init_angles(&angles);
	if (keycode == 53)
		exit(1);
	else if (keycode == 12)
	{
		x_rotate(points, angles.a_x);
		//print_primes(points);
	}
	//else if (keycode == 0)
	//	//x_neg_rotate(points, angles->a_x);
	//else if (keycode == 13)
	//	//y_neg_roate(points, angles->a_y);
	//else if (keycode == 1)
	//	//y_pos_rotate(points, angles->a_y);	
	//else if (keycode == 14)
	//	//z_pos_rotate(points, angles->a_z);
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

	if (ac == 2)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		points = create_points(av[1]);
		print_inits(mlx, win, points);
		mlx_key_hook(win, my_key_funct, (void*)points);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
