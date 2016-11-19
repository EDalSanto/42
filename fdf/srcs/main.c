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

void		draw_big_slope(t_cur cur, t_point *point1, t_point *point2)
{
	cur.max = fabs(cur.dy);
	cur.neg = (cur.dy < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + X_CENTER, (cur.y - point1->y_init) + Y_CENTER, WHITE);
		cur.y += cur.res * cur.neg; 
		cur.x = (cur.x == point2->x_init) ? (cur.x) : (cur.y - cur.y_int) / cur.slope;
		cur.i += cur.res;
	}
}

void		draw_small_slope(t_cur cur, t_point *point1)
{
	cur.max = fabs(cur.dx);
	cur.neg = (cur.dx < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + X_CENTER, (cur.y - point1->y_init) + Y_CENTER, WHITE);
		cur.x += cur.res * cur.neg; 
		cur.y = (cur.slope * cur.x) + cur.y_int;
		cur.i += cur.res;
	}
}

static void	setup_cur_line(t_cur *cur, t_point *point1, t_point *point2)
{
	cur->dx = point2->x_init - point1->x_init;
	cur->dy = point2->y_init - point1->y_init;
	cur->slope = cur->dy / cur->dx;
	cur->x = point1->x_init;
	cur->y = point1->y_init;
	cur->y_int = cur->y - (cur->slope * cur->x);
	cur->res = 0.5;
	cur->i = 0.0;
}

void		draw_line(void *mlx, void *win, t_point *point1, t_point *point2)  
{
	t_cur	cur;
	
	cur.mlx = mlx;
	cur.win = win;
	setup_cur_line(&cur, point1, point2);
	if (fabs(cur.slope) > 1.0)
		draw_big_slope(cur, point1, point2);
	else
		draw_small_slope(cur, point1);
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
		test_all_lines(mlx, win);
	//	points = create_points(av[1]);
	//	draw_line(mlx, win, &one, &two);
		mlx_key_hook(win, my_key_funct, mlx);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
