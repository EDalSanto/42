/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:50:41 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/28 09:39:33 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	check if little is empty string, aka == 0
**	iterate through big looking for a match and then check that substring
**	reset b to current position of big in each iteration
**	if we have a match at current positions, check substring
**	if l reaches end of string return current postion of big
**	else if l does not equal b break
*/

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*l;

	l = (char*)little;
	if (*l == 0)
		return ((char*)big);
	while (*big)
	{
		b = (char*)big;
		if (*b == *little)
		{
			l = (char*)little;
			while (*b == *l)
			{
				b++;
				l++;
				if (*l == 0)
					return ((char*)big);
			}
		}
		big++;
	}
	return (NULL);
}
