/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:16:55 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 15:20:58 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		handle_prec_zeros_neg(t_pf_detective *pf)
{
	ft_putchar('-');
	pf->printed++;
	pf->signed_int_holder *= -1;
}

void		print_left_just(t_pf_detective *pf)
{
	if (IS_BASE_10(pf->convsp) && pf->signed_int_holder < 0
			&& pf->zeros_to_print)
		handle_prec_zeros_neg(pf);
	if (pf->zeros_to_print && pf->plus_flag)
	{
		handle_plus_flag(pf);
		pf->plus_flag = 0;
	}
	while ((pf->zeros_to_print && !(pf->convsp == 'p')))
	{
		ft_putchar('0');
		(pf->zeros_to_print--);
	}
	if (*pf->flags)
		handle_flags(pf);
	if ((pf->pr_flag && (size_t)ft_atoi(pf->precision) < pf->arg_len)
			&& pf->convsp == 's')
		pf->str_holder[ft_atoi(pf->precision)] = '\0';
	handle_convsp(pf);
	while ((pf->spaces_to_print))
	{
		ft_putchar(' ');
		(pf->spaces_to_print)--;
	}
}

void		print_right_just(t_pf_detective *pf)
{
	while ((pf->spaces_to_print))
	{
		ft_putchar(' ');
		(pf->spaces_to_print)--;
	}
	if (*pf->flags)
		handle_flags(pf);
	if (IS_BASE_10(pf->convsp) && pf->signed_int_holder < 0
			&& pf->zeros_to_print)
		handle_prec_zeros_neg(pf);
	while ((pf->zeros_to_print) && pf->convsp != 'p')
	{
		ft_putchar('0');
		(pf->zeros_to_print)--;
	}
	if ((pf->pr_flag && (size_t)ft_atoi(pf->precision) < pf->arg_len)
			&& pf->convsp == 's')
		pf->str_holder[ft_atoi(pf->precision)] = '\0';
	handle_convsp(pf);
}

void		print(t_pf_detective *pf)
{
	while (*(pf->fmt_cpy))
	{
		if (*(pf->fmt_cpy) == '%')
		{
			(pf->fmt_cpy)++;
			if (*(pf->fmt_cpy) && handle_arg(pf))
				pf->fmt_cpy++;
		}
		else
		{
			write(1, pf->fmt_cpy, 1);
			pf->printed++;
			pf->fmt_cpy++;
		}
	}
}
