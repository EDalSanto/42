/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 14:09:22 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/12 15:15:14 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"
#include <stdio.h>

void		handle_int(t_pf_detective *pf)
{
	if (!(pf->pr_flag && !ft_atoi(pf->precision) && !pf->signed_int_holder))
	{
		ft_putnbr(pf->signed_int_holder);
		pf->printed += ft_int_len(pf->signed_int_holder);
		if (pf->signed_int_holder < 0)
			pf->printed++;
	}
}

void		handle_octal(t_pf_detective *pf)
{
	if (!(pf->pr_flag && !ft_atoi(pf->precision) && !pf->unsigned_int_holder) ||
			(pf->hash_flag && pf->pr_flag && pf->unsigned_int_holder != 0))
	{
		pf->printed += ft_put_base_unsigned(pf->unsigned_int_holder, 8);
	}
}

void		handle_hex(t_pf_detective *pf)
{
	if (!(pf->pr_flag && !ft_atoi(pf->precision) && !pf->unsigned_int_holder))
	{
		if (pf->convsp == 'x')
		{
			pf->printed += ft_put_base_unsigned(pf->unsigned_int_holder, 16);
		}
		else
		{
			pf->printed +=
				ft_put_base_unsigned_caps(pf->unsigned_int_holder, 16);
		}
	}
}

void		handle_unsigned(t_pf_detective *pf)
{
	if (!(pf->pr_flag && !ft_atoi(pf->precision) && !pf->unsigned_int_holder))
	{
		pf->printed += ft_put_base_unsigned(pf->unsigned_int_holder, 10);
	}
}
