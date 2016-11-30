/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:28:13 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/29 17:28:42 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_angles		init_angles(void)
{
	t_angles	angles;

	angles.a_x = 0.0;
	angles.a_y = 0.0;
	angles.a_z = 0.0;
	return (angles);
}

void			update_angle(t_angles *angles, char plane, int sign)
{
	if (plane == 'x')
	{
		if (sign == 1)
			angles->a_x += X_ANGLE * (M_PI / 180.0);
		else
			angles->a_x -= X_ANGLE * (M_PI / 180.0);
	}
	else if (plane == 'y')
	{
		if (sign == 1)
			angles->a_y += Y_ANGLE * (M_PI / 180.0);
		else
			angles->a_y -= Y_ANGLE * (M_PI / 180.0);
	}
	else if (plane == 'z')
	{
		if (sign == 1)
			angles->a_z += Z_ANGLE * (M_PI / 180.0);
		else
			angles->a_z -= Z_ANGLE * (M_PI / 180.0);
	}
}
