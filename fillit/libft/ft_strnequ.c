/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:30:05 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/26 22:27:59 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char	*cpy1;
	char	*cpy2;

	if (s1 && s2)
	{
		cpy1 = (char *)s1;
		cpy2 = (char *)s2;
		while ((*cpy1 && *cpy2) && (n > 0))
		{
			if (*cpy1 != *cpy2)
				return (0);
			cpy1++;
			cpy2++;
			n--;
		}
		if ((*cpy1 != *cpy2) && (n > 0))
			return (0);
	}
	return (1);
}
