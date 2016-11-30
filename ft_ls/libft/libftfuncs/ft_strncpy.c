/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 10:41:42 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 14:48:25 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int idx;

	idx = 0;
	while ((src[idx] != '\0') && (idx < len))
	{
		dst[idx] = src[idx];
		idx++;
	}
	while (idx < len)
	{
		dst[idx] = '\0';
		idx++;
	}
	return (dst);
}
