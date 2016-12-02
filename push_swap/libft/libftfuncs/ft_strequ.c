/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:11:49 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/26 22:01:51 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*cpy1;
	char	*cpy2;

	if (s1 && s2)
	{
		cpy1 = (char *)s1;
		cpy2 = (char *)s2;
		while (*cpy1 || *cpy2)
		{
			if (*cpy1 != *cpy2)
				return (0);
			cpy1++;
			cpy2++;
		}
	}
	return (1);
}
