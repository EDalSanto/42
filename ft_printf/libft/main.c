/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:10:52 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/08 18:13:32 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdio.h>
#include <limits.h>

int		main(void)
{
	int ret = int_base_len(LONG_MAX, 8);
	printf("ret: %d\n", ret);
}
