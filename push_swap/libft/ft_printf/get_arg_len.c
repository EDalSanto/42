/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:09:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/09 21:39:59 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		get_base10_len(t_pf_detective *pf)
{
	if (IS_BASE_10(pf->convsp))
	{
		pf->arg_len = ft_int_len(pf->signed_int_holder);
	}
	else if (IS_UNSIGNED(pf->convsp))
	{
		pf->arg_len = int_base_len(pf->unsigned_int_holder, 10);
	}
}

void		get_intarg_len(t_pf_detective *pf)
{
	if (IS_BASE_10(pf->convsp) || IS_UNSIGNED(pf->convsp))
		get_base10_len(pf);
	else if (IS_BASE_8(pf->convsp))
	{
		pf->arg_len = int_base_len(pf->unsigned_int_holder, 8);
	}
	else if (IS_BASE_16(pf->convsp))
	{
		pf->arg_len = int_base_len(pf->unsigned_int_holder, 16);
	}
	else if (pf->convsp == 'p')
	{
		pf->arg_len = int_base_len((unsigned long)pf->mem_holder, 16) + 2;
	}
	if (pf->convsp == 'x' && pf->hash_flag)
		pf->arg_len += 2;
}

void		get_arg_len(t_pf_detective *pf)
{
	if (pf->convsp == 's')
	{
		if (*pf->len_mod == 'l')
			pf->arg_len = ft_wstrlen(pf->wide_str_holder);
		else
			pf->arg_len = ft_strlen(pf->str_holder);
	}
	else if (pf->convsp == 'c')
	{
		if (*pf->len_mod == 'l')
			pf->arg_len = ft_wcharlen(pf->wc_holder);
		else
			pf->arg_len = 1;
	}
	else if (pf->convsp == 'S')
		pf->arg_len = ft_wstrlen(pf->wide_str_holder);
	else if (pf->convsp == 'C')
		pf->arg_len = ft_wcharlen(pf->wc_holder);
	else if (pf->convsp == '%' || ((pf->invalid && pf->zero_flag)))
		pf->arg_len = 1;
	else
		get_intarg_len(pf);
}
