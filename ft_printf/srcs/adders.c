/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adders.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:55:09 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/03 14:56:13 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

int			flag_exists(char *flags, char flag)
{
	char	*s;

	s = flags;
	while (*s)
	{
		if (flag == *s)
			return (1);
		s++;
	}
	return (0);
}

void		add_flag(t_pf_detective *pf, char flag)
{
	if (!flag_exists(pf->flags, flag))
	{
		(pf->flags)[pf->flags_idx] = flag;
		(pf->flags_idx)++;
		if (flag == '#')
			pf->hash_flag = 1;
		else if (flag == '0')
			pf->zero_flag = 1;
		else if (flag == '-')
			pf->minus_flag = 1;
		else if (flag == '+')
			pf->plus_flag = 1;
		else if (flag == ' ')
			pf->space_flag = 1;
	}
}

void		add_len_mod(t_pf_detective *pf, char len_mod)
{
	if (!*pf->len_mod || *pf->len_mod == 'h')
	{
		if (len_mod == 'h' || len_mod == 'l')
		{
			if (*(pf->fmt_cpy + 1) == 'h' || *(pf->fmt_cpy + 1) == 'l')
				ft_strncpy(pf->len_mod, pf->fmt_cpy, 2);
			else
				ft_strncpy(pf->len_mod, pf->fmt_cpy, 1);
		}
		else
			ft_strncpy(pf->len_mod, pf->fmt_cpy, 1);
	}
}

char		*only_valid_chars(char *place_holder)
{
	char	*p;

	p = place_holder;
	while (*p)
	{
		if (!valid_char(*p))
			return (p);
		p++;
	}
	return (NULL);
}
