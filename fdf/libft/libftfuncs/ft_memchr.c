/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:12:27 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 15:24:31 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (cpy[i] == (unsigned char)c)
			return ((unsigned char*)cpy + i);
		i++;
	}
	return (NULL);
}
