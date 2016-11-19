/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 09:42:02 by edal-san          #+#    #+#             */
/*   Updated: 2016/09/29 10:19:40 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long long	res;
	int					i;
	int					sign;

	res = 0;
	i = 0;
	sign = 1;
	while (WS(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[i] != '\0')
	{
		if (str[i] > 57 || str[i] < 48)
			return (res * sign);
		res = res * 10 + str[i++] - '0';
	}
	if (i > 19 || res > 9223372036854775807ULL)
		return (sign == 1 ? -1 : 0);
	return (res * sign);
}
