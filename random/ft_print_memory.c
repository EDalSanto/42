/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 19:25:54 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/09 20:23:07 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_puthex_nbr(int octet, int rem)
{
	const char *digits = "0123456789abcdef";
	
	if (rem > 1)
		ft_puthex_nbr(octet >> 4, rem - 1);
	write(1, digits + (octet % 16), 1);	
}	

void	ft_print_numbers(unsigned char *addr, size_t size, size_t i)
{
	size_t	a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		ft_puthex_nbr(*(addr + i + a), 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
	while (a < 16)
	{
		write(1, "  ", 2);
		if (a % 2)
			write(1, " ", 1);
		a++;
	}
}

void	sp_putchar(unsigned char *ptr)
{
	char	c;

	c = *ptr;
	if (c >= ' ' && c <= '~')
		write(1, ptr, 1);
	else
		write(1, ".", 1);	
}

void	ft_print_characters(unsigned char *addr, size_t size, size_t i)
{
	size_t	a;

	a = 0;
	while (a < 16 && a + i < size)
	{
		sp_putchar(addr + a + i);
		a++;
	}
}

void	ft_print_memory(const void *addr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		ft_print_numbers((unsigned char *)addr, size, i);
		ft_print_characters((unsigned char *)addr, size, i);
		write(1, "\n", 1);
		i += 16;
	}
}

int		main(void)
{
	int		tab[10] = {0, 23, 48, 23, 42};

	ft_print_memory(tab, sizeof(tab));
	return (0);
}
