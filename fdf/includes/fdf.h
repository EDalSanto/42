/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:03:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/22 20:06:47 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# define WIDTH 800 
# define LENGTH 600
# define X_CENTER 400.0
# define Y_CENTER 300.0

# define WHITE 0x00FFFFFF
# define SCALE 20
# define X_ANGLE 45 
# define Y_ANGLE 45 
# define Z_ANGLE 45


typedef struct	s_point
{
	double		x_init;
	double		y_init;
	double		z_init;
	double		x_prime;
	double		y_prime;
	double		z_prime;
	void		*mlx;
	void		*win;
	int			end;
}				t_point;

typedef struct	s_angles
{
	double		a_x;
	double		a_y;
	double		a_z;
}				t_angles;

typedef struct	s_map
{
	t_point		**points;
	void		*mlx;
	void		*win;
	t_angles	angles;
}				t_map;

typedef struct	s_cur
{
	double		x;
	double		y;
	double		res;
	double		neg;
	double		dx;
	double		dy;
	double		y_int;
	double		slope;
	double		max;
	double		i;
	void		*mlx;
	void		*win;
}				t_cur;

t_point		**create_points(char *file);
size_t		count_lines(char *file);
void		parse_line(t_point *point, char *line, int y);
void		print_inits(void *mlx, void *win, t_point **points);
void		print_primes(void *mlx, void *win, t_point **points);
void		draw_prime(void *mlx, void *win, t_point *point1, t_point *point2);
void        draw_line(void *mlx, void *win, t_point *point1, t_point *point2);
void        add_init_points(t_point *point, double x_init, double y_init, double z_init);
void		test_all_lines(void *mlx, void *win);

#endif
