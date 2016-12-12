/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stackA.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:45:23 by edal-san          #+#    #+#             */
/*   Updated: 2016/12/11 18:58:11 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int				get_nums(char *str, t_stack *stackA)
{
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			num = (num * 10) + (*str - '0');
		if (*str == ' ' || !(*(str + 1)))
		{
			num *= sign;
			if (!is_valid(num, stackA) && ft_printf("Error\n"))
				exit(1);
			stackA->nums[stackA->cur_size] = num;
			stackA->cur_size++;
			num = 0;
			sign = 1;
		}
		str++;
	}
	return (1);
}

int			make_stackA(char **av, int ac, t_stack *stackA)
{
	int		i;

	i = 0;
	while (i < ac)
	{
		get_nums(av[i], stackA);
		i++;
	}
	return (1);
}
