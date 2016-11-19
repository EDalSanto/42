/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:50:41 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/26 10:05:11 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wide_strlen(const wchar_t *s)
{
	size_t		len;
	wchar_t		*cpy;

	len = 0;
	cpy = (wchar_t *)s;
	while (*cpy)
	{
		len += 3;
		cpy++;
	}
	return (len);
}
