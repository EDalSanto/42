/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fw_and_pr_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 20:06:20 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 15:17:10 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		wildcard_fw_detective(t_pf_detective *pf, int fw_value)
{
	fw_value = va_arg(pf->ap, int);
	if (fw_value < 0)
	{
		ft_strcpy(pf->field_width, ft_itoa(-fw_value));
		pf->minus_flag = 1;
	}
	else
		ft_strcpy(pf->field_width, ft_itoa(fw_value));
	pf->fmt_cpy++;
}

void		wildcard_pr_detective(t_pf_detective *pf, int pr_value)
{
	pr_value = va_arg(pf->ap, int);
	if (pr_value < 0 && (*(pf->fmt_cpy + 1) != 's'))
		pf->pr_flag = 0;
	else
		ft_strcpy(pf->precision, ft_itoa(pr_value));
	pf->fmt_cpy++;
}

void		find_fw_and_pr(t_pf_detective *pf, char *fw, char *pr, int pr_value)
{
	while (ft_isdigit(*(pf->fmt_cpy)))
		*fw++ = *(pf->fmt_cpy)++;
	if (*(pf->fmt_cpy) == '.')
	{
		pf->pr_flag = 1;
		(pf->fmt_cpy)++;
		if (*pf->fmt_cpy == '*')
			wildcard_pr_detective(pf, pr_value);
		else
		{
			while (ft_isdigit(*(pf->fmt_cpy)))
				*pr++ = *(pf->fmt_cpy)++;
		}
	}
}
