/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 10:09:51 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/09 11:38:33 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		reset_flags(t_pf_detective *pf)
{
	ft_bzero(pf->flags, 10000);
	ft_bzero(pf->precision, 10000);
	ft_bzero(pf->str_holder, 10000);
	pf->pr_flag = 0;
	ft_bzero(pf->field_width, 10000);
	ft_bzero(pf->len_mod, 10000);
	pf->invalid = 0;
	pf->hash_flag = 0;
	pf->zero_flag = 0;
	pf->minus_flag = 0;
	pf->space_flag = 0;
	pf->plus_flag = 0;
	pf->wide_str_holder = NULL;
	pf->arg_len = 0;
	pf->spaces_to_print = 0;
	pf->zeros_to_print = 0;
	pf->flags_idx = 0;
	pf->temp = NULL;
}

static void	setup(t_pf_detective *pf, char *fmt)
{
	pf->fmt_cpy = fmt;
	pf->printed = 0;
	pf->convsp = 0;
	pf->invalid = 0;
	pf->percentage = 0;
	pf->char_holder = 0;
	pf->wide_str_holder = NULL;
	pf->signed_int_holder = 0;
	pf->unsigned_int_holder = 0;
	pf->mem_holder = NULL;
	ft_bzero(pf->flags, 10000);
	ft_bzero(pf->precision, 10000);
	pf->pr_flag = 0;
	ft_bzero(pf->field_width, 10000);
	ft_bzero(pf->len_mod, 10000);
	pf->hash_flag = 0;
	pf->zero_flag = 0;
	pf->minus_flag = 0;
	pf->space_flag = 0;
	pf->plus_flag = 0;
	pf->arg_len = 0;
	pf->spaces_to_print = 0;
	pf->zeros_to_print = 0;
	pf->flags_idx = 0;
	pf->temp = NULL;
}

int			ft_printf(const char *fmt, ...)
{
	t_pf_detective pf;

	va_start(pf.ap, (char*)fmt);
	setup(&pf, (char*)fmt);
	print(&pf);
	return (pf.printed);
}
