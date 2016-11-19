/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:08:38 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/07 10:06:48 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		get_int_arg(t_pf_detective *pf)
{
	if (*pf->len_mod == 'z' || *pf->len_mod == 'j')
		pf->signed_int_holder = va_arg(pf->ap, long long int);
	else if (*pf->len_mod == 'l')
	{
		if (*(pf->len_mod + 1) == 'l')
			pf->signed_int_holder = va_arg(pf->ap, long long int);
		else
			pf->signed_int_holder = va_arg(pf->ap, long int);
	}
	else if (*pf->len_mod == 'h')
	{
		if (*(pf->len_mod + 1) == 'h')
			pf->signed_int_holder = (char)va_arg(pf->ap, int);
		else
			pf->signed_int_holder = (short)va_arg(pf->ap, int);
	}
	else
		pf->signed_int_holder = va_arg(pf->ap, int);
}

void		get_unsigned_int_arg(t_pf_detective *pf)
{
	if (*pf->len_mod == 'z' || *pf->len_mod == 'j' || *pf->len_mod == 'l')
		pf->unsigned_int_holder = va_arg(pf->ap, unsigned long long int);
	else if (*pf->len_mod == 'h')
	{
		if (*(pf->len_mod + 1) == 'h')
			pf->unsigned_int_holder =
								(unsigned char)va_arg(pf->ap, unsigned int);
		else
			pf->unsigned_int_holder =
								(unsigned short)va_arg(pf->ap, unsigned int);
	}
	else
		pf->unsigned_int_holder = va_arg(pf->ap, unsigned int);
}

void		get_char_arg(t_pf_detective *pf)
{
	if (*pf->len_mod == 'l')
		pf->wc_holder = va_arg(pf->ap, wchar_t);
	else
		pf->char_holder = va_arg(pf->ap, int);
}

void		get_str_arg(t_pf_detective *pf)
{
	wchar_t	*str_null_tester;

	str_null_tester = NULL;
	str_null_tester = va_arg(pf->ap, wchar_t*);
	if (str_null_tester && pf->convsp == 's')
	{
		if (*pf->len_mod == 'l')
			pf->wide_str_holder = str_null_tester;
		else
			ft_strcpy(pf->str_holder, (char*)str_null_tester);
	}
	else if (str_null_tester && pf->convsp == 'S')
		pf->wide_str_holder = str_null_tester;
	else
		ft_strcpy(pf->str_holder, "(null)");
}

void		get_arg(t_pf_detective *pf)
{
	if (pf->convsp == 'd' || pf->convsp == 'i')
		get_int_arg(pf);
	else if (pf->convsp == 'c')
		get_char_arg(pf);
	else if (pf->convsp == 'o' || pf->convsp == 'u'
			|| pf->convsp == 'x' || pf->convsp == 'X')
		get_unsigned_int_arg(pf);
	else if (pf->convsp == 'U' || pf->convsp == 'O')
		pf->unsigned_int_holder = va_arg(pf->ap, unsigned long long int);
	else if (pf->convsp == 's' || pf->convsp == 'S')
		get_str_arg(pf);
	else if (pf->convsp == 'C')
		pf->wc_holder = va_arg(pf->ap, wchar_t);
	else if (pf->convsp == 'D')
		pf->signed_int_holder = va_arg(pf->ap, long int);
	else if (pf->convsp == 'p')
		pf->mem_holder = va_arg(pf->ap, void*);
}
