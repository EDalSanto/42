/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:56:11 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/27 09:18:00 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*cpy;
	char	*d;

	dup = (char*)malloc(ft_strlen(s1) + 1);
	if (dup == NULL)
		return (NULL);
	cpy = (char*)s1;
	d = dup;
	while (*cpy)
		*d++ = *cpy++;
	*d = '\0';
	return (dup);
}
