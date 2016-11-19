#include "mlx.h"
#include <stdio.h>
#include <math.h>

int			my_key_funct(int keycode, void *mlx)
{
	printf("key event %d\n", keycode);
	return (0);
}

void		draw_horizontal_line(void *mlx, void* win, int start, int width, int height)
{
	int		x;

	x = 0;
  	while (x < width)
  	{
  		mlx_pixel_put(mlx, win, start + x, height, 0x00FFFFFF);
		x++;
  	}
}

void		draw_vertical_line(void *mlx, void* win, int start_x, int start_y, int height)
{
  	while (height)
  	{
  		mlx_pixel_put(mlx, win, start, height, 0x00FFFFFF);
		height--;
  	}
}

int			main(void)
{
	void	*mlx;
	void	*win;
	int		cols;
	int		rows;
	int		alt;
	int		start;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "mlx 42");
	rows = 11;
	//draw_vertical_line(mlx, win, 0, i);
	while (rows)
	{
		cols = 19;
		while (cols - 1)
		{
			start = (19 - cols) * 19; 
			draw_horizontal_line(mlx, win, start, 19, 19 * rows);
			draw_vertical_line(mlx, win, start_x, start_y, 19);
			cols--;
		}
		start = (19 - cols) * 19; 
		draw_vertical_line(mlx, win, start, 19);
		rows--;
	}
	//mlx_key_hook(win, my_key_funct, mlx);
	mlx_loop(mlx);	
}
