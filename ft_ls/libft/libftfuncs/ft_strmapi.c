/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:54:39 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/26 22:21:07 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;
	int		len;

	if (s && f)
	{
		len = ft_strlen(s);
		new = (char *)malloc(len + 1);
		if (new == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			new[i] = (f)(i, s[i]);
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
