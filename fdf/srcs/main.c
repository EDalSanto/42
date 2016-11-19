#include "fdf.h"
#include <stdio.h>

int			my_key_funct(int keycode, void *mlx)
{
	if (keycode == 53)
		exit(1); 
	(void)mlx;
	ft_printf("key event %d\n", keycode);
	return (0);
}

void		draw_line(void *mlx, void *win, t_point *point1, t_point *point2)  
{
	t_cur	cur;
	double	i;
	double	max;
	double	slope;
	double	y_int;
	double	res;
	double	neg;
	double	dx;
	double	dy;

	dx = point2->x_init - point1->x_init;
	dy = point2->y_init - point1->y_init;
	slope = dy / dx;
	cur.x = point1->x_init;
	cur.y = point1->y_init;
	y_int = cur.y - (slope * cur.x);
	res = 0.5;
	i = 0.0;
	if (fabs(slope) > 1.0)
	{
		max = fabs(dy);
		neg = (dy < 0) ? -1 : 1;
		while (i <= max)
		{
			mlx_pixel_put(mlx, win, (cur.x - point1->x_init) + X_CENTER, (cur.y - point1->y_init) + Y_CENTER, WHITE);
			cur.y += res * neg; 
			cur.x = (cur.x == point2->x_init) ? (cur.x) : (cur.y - y_int) / slope;
			i += res;
		}
	}
	else
	{
		max = fabs(dx);
		neg = (dx < 0) ? -1 : 1;
		while (i <= max)
		{
			printf("cur.y: %lf, cur.x: %lf, slope: %lf, y_int: %lf\n", cur.y, cur.x, slope, y_int);
			mlx_pixel_put(mlx, win, (cur.x - point1->x_init) + X_CENTER, (cur.y - point1->y_init) + Y_CENTER, WHITE);
			cur.x += res * neg; 
			cur.y = (slope * cur.x) + y_int;
			i += res;
		}
	}
}

void		add_init_points(t_point *point, double x_init, double y_init, double z_init)
{
	point->x_init = x_init;
	point->y_init = y_init;
	point->z_init = z_init;
}

//size_t		count_lines(char *file)
//{
//	int		fd;
//	char	*line;
//	size_t	lines;
//
//	lines = 0;
//	fd = open(file);
//	while ((get_next_line(&line, fd) == 1))
//		lines++;
//	close(fd);
//	return (lines);
//}

//t_point		**create_points(char *file)
//{
//	t_point **points;
//	char	*line;
//	int		fd;
//	int		i;
//
//	fd = open(file);
//	i = 0;
//	points = (t_points**)malloc(sizeof(t_points*) * count_lines(file));
//	fd = open(file);
//	while ((get_next_line(&line, fd)) == 1)		
//	{
//		while (*line)
//		{
//			while (ft_isdigit(*line))
//			{
//				z = (temp * 10) + (*line - '0')		
//			}
//			if (!temp)
//				line++;
//		}
//		(*points)[i] = new_point 
//	}
//	return (points);
//}

void		test_eight(void *mlx, void *win)
{
	t_point	one;
	t_point	two;

	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, 200.0, 200.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, 100.0, 200.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, 0.0, 200.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 200.0, 0.0); 
	add_init_points(&two, 0.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 200.0, 0.0); 
	add_init_points(&two, 200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 200.0, 0.0); 
	add_init_points(&two, 100.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, 200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, -200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, -200.0, -200.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 0.0, 0.0); 
	add_init_points(&two, -100.0, -200.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, -200.0, 0.0); 
	add_init_points(&two, -200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, -200.0, 0.0); 
	add_init_points(&two, -100.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, -100.0, 0.0); 
	add_init_points(&two, -200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 100.0, 0.0); 
	add_init_points(&two, 200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, -100.0, 0.0); 
	add_init_points(&two, 200.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 200.0, 100.0, 0.0); 
	add_init_points(&two, 0.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 
	add_init_points(&one, 0.0, 100.0, 0.0); 
	add_init_points(&two, 0.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 

}

int			main(int ac, char **av)
{
	void	*mlx;
	void	*win;
//	t_point	**points;
//	t_point	one;
//	t_point	two;

	(void)av;
	if (ac == 2)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
		test_eight(mlx, win);
	//	points = create_points(av[1]);
	//	draw_line(mlx, win, &one, &two);
		mlx_key_hook(win, my_key_funct, mlx);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
