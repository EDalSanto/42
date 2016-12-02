/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:46:58 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/26 10:12:54 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void		ft_put_widestr(wchar_t const *s)
{
	wchar_t	*cpy;

	if (s)
	{
		cpy = (wchar_t*)s;
		while (*cpy)
		{
			write(1, cpy, sizeof(wchar_t));
			cpy++;
		}
	}
}
