/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_detectives.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:13:58 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 15:18:19 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		str_spaces_detective(t_pf_detective *pf, size_t pr, size_t fw)
{
	if (fw > pf->arg_len)
	{
		if (pr < pf->arg_len && pf->convsp != 'c')
			pf->spaces_to_print += (fw - pr);
		else
			pf->spaces_to_print += (fw - pf->arg_len);
	}
	else
	{
		if ((pr < pf->arg_len) && (fw > pr))
		{
			if (pf->convsp == 'S')
				pf->spaces_to_print += (fw - widechar_last_len_detective(pf));
			else
				pf->spaces_to_print += (fw - pr);
		}
	}
}

void		num_spaces_detective(t_pf_detective *pf, size_t pr, size_t fw)
{
	if ((fw >= pf->arg_len) && (pr <= pf->arg_len))
	{
		pf->spaces_to_print = fw - pf->arg_len - pf->zeros_to_print;
		if (pr == 0 && ((IS_BASE_10(pf->convsp) && !pf->signed_int_holder)
				|| ((IS_UNSIGNED_ALL(pf->convsp) &&
						!pf->unsigned_int_holder)) ||
				(pf->convsp == 'p' && !pf->mem_holder)))
			pf->spaces_to_print++;
	}
	else if ((fw > pf->arg_len) && (pr > pf->arg_len) && (fw > pr))
	{
		pf->spaces_to_print = fw - pr;
		if (pf->signed_int_holder < 0)
			pf->spaces_to_print--;
		else if ((pf->convsp == 'x' && pf->hash_flag) || pf->convsp == 'p')
			pf->spaces_to_print -= 2;
	}
}

void		spaces_detective(t_pf_detective *pf, size_t pr, size_t fw)
{
	if (pf->convsp == 's' || pf->convsp == 'S' || pf->convsp == 'c')
		str_spaces_detective(pf, pr, fw);
	else if (IS_NUM(pf->convsp) || pf->convsp == 'p')
		num_spaces_detective(pf, pr, fw);
	else if (pf->convsp == '%')
	{
		if (pf->zero_flag)
			pf->zeros_to_print = fw - 1;
		else
			pf->spaces_to_print = fw - 1;
	}
	if ((pf->hash_flag || pf->plus_flag || pf->space_flag)
		&& (!(pf->signed_int_holder < 0)) &&
		(!(pf->convsp == 'x')) && pf->spaces_to_print)
		pf->spaces_to_print--;
}
