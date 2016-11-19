/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 19:38:43 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 14:29:21 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	if ((dst != 0 && src == 0) && n == 0)
		return (dst);
	if ((dst == 0 && src == 0) && n == 0)
		return (0);
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	while (i++ < n)
		*d++ = *s++;
	return (dst);
}
