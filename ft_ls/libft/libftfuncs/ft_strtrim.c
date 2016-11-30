/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 15:54:06 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/27 09:36:57 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_strcpy2(char *new, char *start, char *end)
{
	char	*n;

	n = new;
	while (start <= end)
	{
		*n = *start;
		n++;
		start++;
	}
	*n = '\0';
	return (new);
}

static char	*find_end(char *cpy, char *end)
{
	while (*cpy)
	{
		if ((*cpy >= '!' && *cpy <= '~') &&
				(WS(*(cpy + 1)) || (*(cpy + 1) == '\0')))
			end = cpy;
		cpy++;
	}
	return (end);
}

char		*ft_strtrim(char const *s)
{
	char	*new;
	char	*cpy;
	char	*start;
	char	*end;

	if (s)
	{
		cpy = (char *)s;
		while (WS(*cpy))
			cpy++;
		start = cpy;
		end = cpy;
		end = find_end(cpy, end);
		new = (char*)malloc(end - start + 2);
		if (new == NULL)
			return (NULL);
		new = ft_strcpy2(new, start, end);
	}
	else
		return (NULL);
	return (new);
}
