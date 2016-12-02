/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 14:28:47 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 15:07:47 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*cpy;

	cpy = (char*)s;
	while (*cpy)
		cpy++;
	while (cpy >= s)
	{
		if (*cpy == (char)c)
			return (cpy);
		cpy--;
	}
	return (NULL);
}
