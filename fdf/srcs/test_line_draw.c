#include "fdf.h"

void		test_all_lines(void *mlx, void *win)
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
	add_init_points(&one, 0.0, 100.0, 0.0); 
	add_init_points(&two, 0.0, 0.0, 0.0); 
	draw_line(mlx, win, &one, &two); 

}
