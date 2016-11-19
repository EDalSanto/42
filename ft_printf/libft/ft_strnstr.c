/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:50:41 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 09:46:42 by edal-san         ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	char	*b_begin;

	l = (char*)little;
	if (*l == 0)
		return ((char*)big);
	b_begin = (char*)big;
	while ((*big) && ((size_t)(big - b_begin) < len))
	{
		b = (char*)big;
		if (*b == *little)
		{
			l = (char*)little;
			while ((*b == *l) && ((size_t)(b - b_begin) < len))
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
