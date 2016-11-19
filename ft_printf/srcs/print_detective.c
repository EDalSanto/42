/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_detective.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:15:43 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 15:27:49 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		pr_detective(t_pf_detective *pf, size_t pr)
{
	if (pf->convsp == 'p' && pf->arg_len >= 2)
		pf->arg_len -= 2;
	if (pr > pf->arg_len)
	{
		if (IS_NUM(pf->convsp))
		{
			pf->zeros_to_print = pr - pf->arg_len;
			if (pf->convsp == 'o' && pf->hash_flag)
				pf->zeros_to_print--;
			else if (pf->convsp == 'x' && pf->hash_flag)
				pf->zeros_to_print += 2;
			else if (pf->signed_int_holder < 0 && pf->zeros_to_print)
			{
				ft_putchar('-');
				pf->signed_int_holder *= -1;
				pf->printed++;
			}
		}
		else if (pf->convsp == 'p')
			pf->zeros_to_print = pr - pf->arg_len;
	}
}

void		fw_detective(t_pf_detective *pf, size_t fw)
{
	if (IS_BASE_10(pf->convsp) && pf->signed_int_holder < 0)
		pf->arg_len++;
	if (fw > pf->arg_len)
	{
		if (pf->zero_flag && !pf->minus_flag)
			pf->zeros_to_print = fw - pf->arg_len;
		else
			pf->spaces_to_print = fw - pf->arg_len;
		if ((!convsp_detected(pf->convsp)) || ((pf->space_flag || pf->plus_flag)
			&& (IS_BASE_10(pf->convsp) && !(pf->signed_int_holder < 0))) ||
			(pf->hash_flag && pf->convsp == 'o'))
		{
			if (pf->spaces_to_print)
				pf->spaces_to_print--;
			else
				pf->zeros_to_print--;
		}
	}
}

void		fw_helper(t_pf_detective *pf, size_t fw)
{
	if (IS_NUM(pf->convsp) || pf->zero_flag)
		pf->zeros_to_print = fw;
	else
		pf->spaces_to_print = fw;
}

void		pr_and_fw_detective(t_pf_detective *pf, size_t pr, size_t fw)
{
	if (fw > pr)
	{
		if (pf->convsp == 'p' && (pr > pf->arg_len - 2))
			pf->zeros_to_print += (pr - (pf->arg_len - 2));
		else if ((IS_NUM(pf->convsp) && (pr > pf->arg_len)))
			pf->zeros_to_print = pr - pf->arg_len;
		if (IS_BASE_10(pf->convsp) && pf->signed_int_holder < 0)
			pf->arg_len++;
		if (!pf->zero_flag || IS_NUM(pf->convsp) || pf->convsp == '%')
			spaces_detective(pf, pr, fw);
		else if ((pf->convsp == 's' && !ft_strcmp("(null)", pf->str_holder))
				|| (pf->convsp == 'S' && pr == 0))
			pf->zeros_to_print = fw;
		else if (fw < pf->arg_len)
			fw_helper(pf, fw);
		else
			pf->zeros_to_print = fw - pf->arg_len;
	}
	else
	{
		spaces_detective(pf, pr, fw);
		pr_detective(pf, pr);
	}
}

void		print_detective(t_pf_detective *pf)
{
	size_t	pr;
	size_t	fw;

	pr = ft_atoi(pf->precision);
	fw = ft_atoi(pf->field_width);
	if ((pf->pr_flag) && (fw))
		pr_and_fw_detective(pf, pr, fw);
	else if (pf->pr_flag)
		pr_detective(pf, pr);
	else if (fw)
		fw_detective(pf, fw);
}
