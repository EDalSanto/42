/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 08:16:52 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/02 20:50:28 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		ft_putwchar(wchar_t w, char *buffer)
{
	int		i;

	i = 0;
	if (w <= 0x7f)
		buffer[i++] = (w & 0x7f) | 0;
	else if (w <= 0x7FF)
	{
		buffer[i++] = (w >> 6) + 0xC0;
		buffer[i++] = (w & 0x3f) + 0x80;
	}
	else if (w <= 0xFFFF)
	{
		buffer[i++] = (w >> 12) + 0xE0;
		buffer[i++] = ((w >> 6) & 0x3F) + 0x80;
		buffer[i++] = (w & 0x3F) + 0x80;
	}
	else if (w <= 0x10FFFF)
	{
		buffer[i++] = (w >> 18) + 0xF0;
		buffer[i++] = ((w >> 12) & 0x3F) + 0x80;
		buffer[i++] = ((w >> 6) & 0x3F) + 0x80;
		buffer[i++] = (w & 0x3F) + 0x80;
	}
	buffer[i] = '\0';
}

size_t		ft_wcharlen(wchar_t w)
{
	if (w <= 0x7F)
		return (1);
	else if (w <= 0x7FF)
		return (2);
	else if (w <= 0xFFFF)
		return (3);
	else if (w <= 0x10FFFF)
		return (4);
	return (-1);
}

size_t		ft_wstrlen(wchar_t *wstr)
{
	int		i;
	size_t	len;

	if (wstr)
	{
		i = 0;
		len = 0;
		while (wstr[i])
		{
			len += ft_wcharlen(wstr[i]);
			i++;
		}
		return (len);
	}
	return (0);
}

void		ft_putwstr(wchar_t *wstr, char *buffer)
{
	int		i;

	i = 0;
	while (wstr[i])
	{
		ft_putwchar(wstr[i], buffer);
		ft_putstr(buffer);
		ft_bzero(buffer, ft_strlen(buffer));
		i++;
	}
}

void		handle_widechar(t_pf_detective *pf)
{
	char	c;

	c = 0;
	ft_putwchar(pf->wc_holder, pf->str_holder);
	if (!(*pf->str_holder))
		write(1, &c, 1);
	else
		ft_putstr(pf->str_holder);
	pf->printed += ft_wcharlen(pf->wc_holder);
}
