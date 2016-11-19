/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 14:39:32 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/09 21:43:16 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		handle_str(t_pf_detective *pf)
{
	ft_putstr(pf->str_holder);
	pf->printed += ft_strlen(pf->str_holder);
	ft_bzero(pf->str_holder, ft_strlen(pf->str_holder));
}

void		handle_char(t_pf_detective *pf)
{
	ft_putchar(pf->char_holder);
	pf->printed++;
}

void		handle_widestr(t_pf_detective *pf)
{
	int		len;
	int		i;

	i = 0;
	if (pf->wide_str_holder)
	{
		len = ft_wcharlen(pf->wide_str_holder[i]);
		if (pf->pr_flag)
		{
			while (len <= (int)ft_atoi(pf->precision))
			{
				ft_putwchar(pf->wide_str_holder[i], pf->str_holder);
				ft_putstr(pf->str_holder);
				ft_bzero(pf->str_holder, ft_strlen(pf->str_holder));
				pf->printed += ft_wcharlen(pf->wide_str_holder[i]);
				i++;
				len += ft_wcharlen(pf->wide_str_holder[i]);
			}
		}
		else if (pf->printed += ft_wstrlen(pf->wide_str_holder))
			ft_putwstr(pf->wide_str_holder, pf->str_holder);
	}
	else if (pf->printed += ft_strlen(pf->str_holder))
		ft_putstr(pf->str_holder);
}

void		handle_addr(t_pf_detective *pf)
{
	ft_putstr("0x");
	while (pf->zeros_to_print)
	{
		ft_putchar('0');
		pf->zeros_to_print--;
	}
	if (!(pf->pr_flag && !ft_atoi(pf->precision) && !pf->mem_holder))
		ft_put_base_unsigned((unsigned long)pf->mem_holder, 16);
	if (pf->pr_flag && !ft_atoi(pf->precision) && !pf->mem_holder)
		pf->printed += 2;
	else
		pf->printed += (int_base_len((unsigned long)pf->mem_holder, 16) + 2);
}

void		handle_quot(t_pf_detective *pf)
{
	ft_putstr("%");
	pf->printed += 1;
}
