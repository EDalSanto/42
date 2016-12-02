/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:56:29 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 18:15:25 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long int n, int base)
{
	char	digits[16];

	ft_strcpy(digits, "0123456789abcdef");
	if (n >= base)
		ft_putnbr(n / base);
	n = digits[(n % base)];
	ft_putchar(n);
}
