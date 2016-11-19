/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:03:48 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/26 09:01:29 by edal-san         ###   ########.fr       */
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

static char		*ft_reverse(char *s)
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
	return (s);
}

static void		zero_case(char *s)
{
	char		*cpy;

	cpy = s;
	*cpy++ = '0';
	*cpy = '\0';
	ft_putstr(s);
}

size_t			ft_put_base(long long int n, int base)
{
	char		*s;
	char		digits[16];
	char		*cpy;
	int			sign;
	size_t		len;

	len = 0;
	ft_strcpy(digits, "0123456789abcdef");
	if (!(s = (char*)malloc((sizeof(char) * int_len(n)) + 2)))
		return (0);
	sign = (n < 0) ? -1 : 1;
	cpy = s;
	while (n)
	{
		*cpy++ = digits[((n * sign) % base)];
		n /= base;
	}
	if (sign == -1)
		*cpy++ = '-';
	*cpy = '\0';
	(n == 0 || n == -0) ? zero_case(s) : ft_putstr((ft_reverse(s)));
	len = ft_strlen(s);
	free(s);
	return (len);
}
