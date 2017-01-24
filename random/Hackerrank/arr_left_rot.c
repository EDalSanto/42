#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int			*shift_left(int *arr, int len, int shifts)
{
	int     *new;
	int     index;
	int     new_index;

	index = 0;
	new = malloc(sizeof(int) * len);
	while (index < len)
	{
		new_index = (index - shifts + len) % len;
		new[new_index] = arr[index];
		index++;
	}
	return (new);
}

void		print_int_arr(int *arr, int len)
{
	int     i;

	i = 0;
	while (i < len)
	{
		ft_putnbr(arr[i]);
		if (i < (len - 1))
			ft_putstr(", ");
		i++;
	}
	ft_putchar('\n');
}

int		main(void)
{
	int		arr[5] = {0,1,2,3,4};
	
	print_int_arr(shift_left(arr, 5, 2), 5);
	return (0);
}
