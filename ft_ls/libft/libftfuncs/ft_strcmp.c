/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:58:29 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 15:04:20 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	x;
	unsigned char	y;
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	cpy1 = (unsigned char*)s1;
	cpy2 = (unsigned char*)s2;
	while (*cpy1 || *cpy2)
	{
		x = *cpy1;
		y = *cpy2;
		if (x != y)
			return (x - y);
		cpy1++;
		cpy2++;
	}
	return (0);
}
