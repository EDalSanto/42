/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 09:00:41 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/07 19:57:19 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft_printf.h"

void		parse_nums(t_pf_detective *pf)
{
	char	*pr;
	char	*fw;
	int		pr_value;
	int		fw_value;

	pr = pf->precision;
	fw = pf->field_width;
	fw_value = 0;
	pr_value = 0;
	if (*(pf->fmt_cpy) == '*')
		wildcard_fw_detective(pf, fw_value);
	else if (ft_isdigit(*(pf->fmt_cpy)))
		find_fw_and_pr(pf, fw, pr, pr_value);
	else if ((pf->pr_flag = 1))
	{
		(pf->fmt_cpy)++;
		if (*pf->fmt_cpy == '*')
			wildcard_pr_detective(pf, pr_value);
		else
		{
			while (ft_isdigit(*(pf->fmt_cpy)))
				*pr++ = *(pf->fmt_cpy)++;
		}
	}
	(pf->fmt_cpy)--;
}

int			valid_char(char c)
{
	if (c == '*' || flag_detected(c) || len_mod_detected(c)
			|| c == '.' || ft_isdigit(c))
		return (1);
	else
		return (0);
}

int			pr_or_fw_found(char *c)
{
	if (*c == '.' || *c == '*' ||
		(ft_isdigit(*c) && *c != '0'))
		return (1);
	else
		return (0);
}

void		fmt_detective(t_pf_detective *pf, char **place_holder)
{
	if (pr_or_fw_found(pf->fmt_cpy))
	{
		parse_nums(pf);
		*place_holder = pf->fmt_cpy + 1;
	}
	else if (flag_detected(*(pf->fmt_cpy)))
		add_flag(pf, *(pf->fmt_cpy));
	else if (len_mod_detected(*(pf->fmt_cpy)))
		add_len_mod(pf, *(pf->fmt_cpy));
}

int			parse_convsp(t_pf_detective *pf)
{
	char	*place_holder;

	place_holder = pf->fmt_cpy;
	while (!convsp_detected(*(pf->fmt_cpy))
			&& *(pf->fmt_cpy) && valid_char(*pf->fmt_cpy))
	{
		fmt_detective(pf, &place_holder);
		pf->fmt_cpy++;
	}
	if (*(pf->fmt_cpy) == ' ' && second_quote(pf->fmt_cpy))
		pf->convsp = '%';
	else if (convsp_detected(*(pf->fmt_cpy)))
		pf->convsp = *(pf->fmt_cpy);
	else if (!(*(pf->fmt_cpy)) && (!(*pf->field_width)) &&
	!valid_char(*place_holder) && (pf->printed += ft_strlen(place_holder)))
		ft_putstr(place_holder);
	else if ((place_holder = only_valid_chars(place_holder)))
	{
		if (*place_holder == ' ')
			place_holder++;
		pf->fmt_cpy = place_holder;
		pf->invalid = *place_holder;
	}
	return (*(pf->fmt_cpy)) ? (1) : (0);
}
