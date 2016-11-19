/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:03:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/18 17:10:06 by edal-san         ###   ########.fr       */
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

typedef struct	s_point
{
	double		x_init;
	double		y_init;
	double		z_init;
	double		x_prime;
	double		y_prime;
}				t_point;

typedef struct	s_cur
{
	double		x;
	double		y;
}				t_cur;

#endif
