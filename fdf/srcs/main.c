#include "fdf.h"
#include <stdio.h>

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

int			my_key_funct(int keycode, void *mlx, t_point **points, t_point *angles)
{
	(void)mlx;
	if (keycode == 53)
		exit(1);
	else if (keycode == 12)
		x_rotate(points, (angles->a_x));
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

void		draw_big_slope(t_cur cur, t_point *point1, t_point *point2)
{
	cur.max = fabs(cur.dy);
	cur.neg = (cur.dy < 0) ? -1 : 1;
	while (cur.i <= cur.max)
	{
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + 100 + point1->x_init, (cur.y - point1->y_init) + 100 + point1->y_init, WHITE);
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
//		printf("cur.x: %lf, point1.x_init: %lf, cur.y: %lf, point1.y_init: %lf\n", cur.x, point1->x_init, cur.y, point1->y_init);
//		printf("where I'm printing, x: %lf, y: %lf\n", (cur.x - point1->x_init) + X_CENTER - point1->x_init, (cur.y - point1->y_init) + Y_CENTER - point1->y_init);
		mlx_pixel_put(cur.mlx, cur.win, (cur.x - point1->x_init) + 100 + point1->x_init, (cur.y - point1->y_init) +  point1->y_init + 100, WHITE);
		cur.x += cur.res * cur.neg; 
		cur.y = (cur.slope * cur.x) + cur.y_int;
		cur.i += cur.res;
	}
}

static void	setup_cur_line(t_cur *cur, t_point *point1, t_point *point2)
{
	//if (point1->z_init == 0.0 && point2->z_init == 0.0)
//	{
		cur->dx = point2->x_init - point1->x_init;
		cur->dy = point2->y_init - point1->y_init;
		cur->x = point1->x_init;
		cur->y = point1->y_init;
//	}
//	else
//	{
//	//	printf("p2->x_prime: %lf, p1->x_prime: %lf, p2->x_init: %lf, p1->x_init: %lf, point1->z_init: %lf, point2->z_init: %lf\n", point2->x_prime, point1->x_prime, point2->x_init, point1->x_init, point1->z_init, point2->z_init);
//		cur->dx = point2->x_prime - point1->x_prime;
//		cur->dy = point2->y_prime - point1->y_prime;
//		cur->x = point1->x_prime;
//		cur->y = point1->y_prime;
//	}
	cur->slope = cur->dy / cur->dx;
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
	point->x_init = x_init * SCALE;
	point->y_init = y_init * SCALE;
	point->z_init = z_init * SCALE;
	point->x_prime = 0.0;
	point->y_prime = 0.0;
	point->z_prime = 0.0;
//	printf("x_prime: %lf, y_prime: %lf\n", point->x_prime, point->y_prime);
	point->end = 0;
}

size_t		count_lines(char *file)
{
	int		fd;
	char	*line;
	size_t	lines;

	lines = 0;
	fd = open(file, O_RDONLY);
	while ((get_next_line(fd, &line) == 1))
		lines++;
	close(fd);
	return (lines);
}

void		add_prime_points(t_point *point, double x_init, double y_init, double z_init)
{
	point->x_prime = x_init / z_init;
	point->y_prime = y_init / z_init;
}

void		parse_line(t_point *point, char *line, int y)
{
	int		x;
	int		i;
	double	z;
	t_point	*p;

	x = 0.0;
	i = 0;
	p = point;
	while (line[i])
	{
		z = 0.0;
		if(ft_isdigit(line[i]))
		{	
			while(ft_isdigit(line[i])) 
			{
				z = (z * 10.0) + (line[i] - '0');		
				i++;
			}
			add_init_points(p, x, y, z);
			//printf("z: %lf, p before increment: %p, point + x: %p, point + x->y: %lf, point + x->x: %lf, x: %d\n", z, p, point + x, (point + x)->y_init, (point + x)->x_init, x);
			p++;
			x++;
		}
		else
			i++;
	}
//	printf("x: %lf\n", x);
	p->end = 1;
	//printf("p end: %p, point + x->end: %d\n", p, (point + x)->end);
}

t_point		**create_points(char *file)
{
	t_point **points;
	char	*line;
	int		fd;
	int		arr_i;

	points = (t_point**)malloc(sizeof(t_point*) * count_lines(file) + sizeof(void*));
	fd = open(file, O_RDONLY);
	arr_i = 0;
	while ((get_next_line(fd, &line)) == 1)		
	{
		points[arr_i] = (t_point*)malloc(sizeof(t_point) * ((ft_strlen(line) / 2) + 2));
		parse_line(points[arr_i], line, arr_i);
		arr_i++;	
	}
	points[arr_i] = NULL;
	return (points);
}

void		print_points(void *mlx, void *win, t_point **points)
{
	int		arr_i;
	int		point_i;
	t_point	cur_point;
	t_point	right_point;
	t_point	below_point;

	arr_i = 0;
	while (points[arr_i] != NULL)
	{
		point_i = 0;
		while (!((points[arr_i][point_i]).end))
		{
			cur_point = points[arr_i][point_i];
		//	printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init); 
			if (!((points[arr_i][point_i + 1]).end))
			{
				right_point = points[arr_i][point_i + 1];
				draw_line(mlx, win, &cur_point, &right_point);   		
			}
			if (points[arr_i + 1])
			{
				below_point = points[arr_i + 1][point_i];
				//printf("cur_point->x_init: %lf, cur_point->y_init: %lf, cur_point->z_init: %lf\n below->x: %lf, below->y: %lf, below->z: %lf\n", cur_point.x_init, cur_point.y_init, cur_point.z_init, below_point.x_init, below_point.y_init, below_point.z_init); 
				draw_line(mlx, win, &cur_point, &below_point); 
			}
			point_i++;  		
		}
		arr_i++;
	}
}

void			init_angles(t_angles *angles)
{
	angles->a_x = ANGLE_X;
	angles->a_y = ANGLE_Y;
	angles->a_z = ANGLE_Z;
}

int				main(int ac, char **av)
{
	void		*mlx;
	void		*win;
	t_point		**points;
	t_angles	angles;

	(void)av;
	if (ac == 2)
	{
		mlx = mlx_init();
		win = mlx_new_window(mlx, WIDTH, LENGTH, "mlx 42");
//		test_all_lines(mlx, win);
		points = create_points(av[1]);
		init_angles(&angles);
		print_points(mlx, win, points);
		mlx_key_hook(win, my_key_funct, mlx);
		mlx_loop(mlx);	
	}
	else
		ft_putstr("Invalid Argument\n");
}
