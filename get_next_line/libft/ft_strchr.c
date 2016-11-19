/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:18:39 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 14:56:25 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*cpy;

	cpy = (char*)s;
	if ((char)c == '\0')
		return (cpy + ft_strlen(cpy));
	while (*cpy)
	{
		if (*cpy == (char)c)
			return (cpy);
		cpy++;
	}
	return (NULL);
}
