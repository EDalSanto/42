/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 21:55:05 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/03 09:00:17 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h> 

static size_t	word_count(char *s, char c)
{
	size_t		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		count++;
	}
	return (count);
}

static void		ft_cpy(char *dest, char *start, char *end)
{
	char		*d;

	d = dest;
	while (start <= end)
	{
		*d = *start;
		d++;
		start++;
	}
	*d = '\0';
}

static int		make_elm(char **arr, int arr_i, char *start, int len)
{
	arr[arr_i] = (char*)malloc(len + 1);
	if (arr[arr_i] == NULL)
		return (0);
	ft_cpy(arr[arr_i], start, start + len - 1);
	arr_i++;
	return (arr_i);
}

static char		**make_array(char **arr, char const *s, char c)
{
	char		*cpy;
	char		*start;
	int			arr_i;
	int			len;

	cpy = (char *)s;
	arr_i = 0;
	while (*cpy)
	{
		len = 0;
		while (*cpy == c)
			cpy++;
		start = cpy;
		while (*cpy != c && *cpy)
		{
			len++;
			cpy++;
		}
		if (len)
			arr_i = make_elm(arr, arr_i, start, len);
	}
	arr[arr_i] = 0;
	return (arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**arr;

	if (s)
	{
		arr = (char**)malloc(sizeof(char*) * (word_count((char*)s, c) + 1));
		if (arr == NULL)
			return (NULL);
		arr = make_array(arr, s, c);
	}
	else
		return (NULL);
	return (arr);
}
