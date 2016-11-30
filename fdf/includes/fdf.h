/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:03:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/30 08:22:21 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <math.h>
# include <stdlib.h>
# include "mlx.h"
# include <fcntl.h>
# define WIDTH 1200
# define LENGTH 900
# define X_CENTER 600
# define Y_CENTER 450

# define WHITE 0x00FFFFFF
# define X_ANGLE 15
# define Y_ANGLE 15
# define Z_ANGLE 15

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
	int			zoom_factor;
	int			zoom_sign;
	size_t		num_lines;
	size_t		max_strlen;
	double		x_start;
	double		y_start;
	double		scale;
	int			translate_adj;
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

t_point			**create_points(char *file, t_map *map);
t_angles		init_angles(void);
size_t			count_lines(char *file, t_map *map);
void			parse_line(t_point *point, char *line, int y, t_map *map);
void			print_inits(t_map *map);
void			print_primes(t_map *map);
void			draw_prime(t_map *map, t_point *point1, t_point *point2);
void			draw_line(t_map *map, t_point *point1, t_point *point2);
void			add_init_points(t_point *point, double x_init,
									double y_init, double z_init);
void			test_all_lines(void *mlx, void *win);
void			update_angle(t_angles *angles, char plane, int sign);
void			z_rotate(t_point **points, double a_z);
void			x_rotate(t_point **points, double a_x);
void			y_rotate(t_point **points, double a_y);
void			reset_primes(t_point **points);
void			translate_points(t_map *map);
void			reset_map(t_map *map);
void			unzoom(t_map *map);
void			zoom(t_map *map);
void			zoom_detective(t_map *map);
void			center(t_map *map);
void			scale_detective(t_map *map);
void			free_points(t_map *map);
void			update_angles(int keycode, t_map *map);
int				rot_key(int keycode);

#endif
