/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:18:17 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/09 11:12:27 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		handle_num_convsp(t_pf_detective *pf)
{
	if (pf->convsp == 'd' || pf->convsp == 'i' || pf->convsp == 'D')
		handle_int(pf);
	else if (pf->convsp == 'o' || pf->convsp == 'O')
		handle_octal(pf);
	else if (pf->convsp == 'u' || pf->convsp == 'U')
		handle_unsigned(pf);
	else if (pf->convsp == 'x' || pf->convsp == 'X')
		handle_hex(pf);
	else if (pf->convsp == 'p')
		handle_addr(pf);
	else if (pf->convsp == 'c')
	{
		if (*pf->len_mod == 'l')
			handle_widechar(pf);
		else
			handle_char(pf);
	}
	else if (pf->convsp == 'C')
		handle_widechar(pf);
}

void		handle_convsp(t_pf_detective *pf)
{
	if (pf->convsp == 's')
	{
		if (*pf->len_mod == 'l')
			handle_widestr(pf);
		else
			handle_str(pf);
	}
	else if (pf->convsp == 'S')
		handle_widestr(pf);
	else if (pf->convsp == '%')
		handle_quot(pf);
	else if (pf->invalid != 0)
	{
		ft_putchar(pf->invalid);
		pf->printed++;
	}
	else
		handle_num_convsp(pf);
}

int			handle_arg(t_pf_detective *pf)
{
	if (parse_convsp(pf))
	{
		get_arg(pf);
		get_arg_len(pf);
		print_detective(pf);
		pf->printed += pf->zeros_to_print;
		pf->printed += pf->spaces_to_print;
		if ((*(pf->field_width) && pf->minus_flag))
			print_left_just(pf);
		else
			print_right_just(pf);
		reset_flags(pf);
		return (1);
	}
	return (0);
}
