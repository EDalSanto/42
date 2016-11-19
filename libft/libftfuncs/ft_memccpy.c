/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:06:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 13:40:03 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	int					found;
	size_t				i;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	found = 0;
	i = 0;
	while (i++ < n)
	{
		if (*s == ((unsigned char)c))
			found = 1;
		*d++ = *s++;
		if (found)
			return ((void*)d);
	}
	return (NULL);
}
