/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:03:48 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/27 08:49:36 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	int_len(int n)
{
	size_t		len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		ft_reverse(char *s)
{
	char		*start;
	char		*end;
	char		*cpy;
	char		tmp;

	cpy = s;
	start = cpy;
	while (*cpy)
		cpy++;
	end = cpy - 1;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

static char		*zero_case(char *s)
{
	char		*cpy;

	cpy = s;
	*cpy++ = '0';
	*cpy = '\0';
	return (s);
}

char			*ft_itoa(int n)
{
	char		*s;
	char		*cpy;
	int			sign;
	int			smallest;

	s = (char*)malloc((sizeof(char) * int_len(n)) + 2);
	if (n == 0 || n == -0)
		return (zero_case(s));
	sign = (n < 0) ? -1 : 1;
	smallest = (n == -2147483648) ? 1 : 0;
	if (s == NULL)
		return (NULL);
	cpy = s;
	while (n)
	{
		*cpy++ = ((n * sign) % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		*cpy++ = '-';
	*cpy = '\0';
	if (smallest)
		*s = '8';
	ft_reverse(s);
	return (s);
}
