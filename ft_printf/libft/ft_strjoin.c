/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:27:00 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/26 22:15:16 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		make_new(char *new, char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (s1 && s2)
	{
		new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
		if (new == NULL)
			return (NULL);
		make_new(new, s1, s2);
	}
	else
		return (NULL);
	return (new);
}
