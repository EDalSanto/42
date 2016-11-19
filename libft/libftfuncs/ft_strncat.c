/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:03:56 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 14:39:26 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*src;
	char	*dst;

	dst = s1;
	src = (char*)s2;
	while (*dst)
		dst++;
	while ((*src) && (n--))
		*dst++ = *src++;
	*dst = '\0';
	return (s1);
}
