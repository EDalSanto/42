#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libftprintf.h"

void	simple_printf(char	*fmt, ...)
{
	va_list ap;
	int		i;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*fmt == 'i')
			{
				i = va_arg(ap, int);
				write(1, ft_itoa(i), 1);
			}
		}
		else
			write(1, fmt, 1);
		fmt++;
	}	
	va_end(ap);
	putchar('\n');
}

int		main(void)
{
	simple_printf("5 is: %i", 5);
	return (0);
}
