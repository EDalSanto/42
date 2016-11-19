/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 20:31:39 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 14:45:41 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cpy1;
	unsigned char	*cpy2;

	cpy1 = (unsigned char*)s1;
	cpy2 = (unsigned char*)s2;
	while ((*cpy1 != '\0' || *cpy2 != '\0') && (n--))
	{
		if (*cpy1 != *cpy2)
			return (*cpy1 - *cpy2);
		cpy1++;
		cpy2++;
	}
	return (0);
}
