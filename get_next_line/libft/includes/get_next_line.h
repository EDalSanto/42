/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 09:53:52 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/20 17:07:12 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 32

typedef struct				s_data
{
	int						r;
	char					b[BUFF_SIZE + 1];
	int						b_index;
	int						fd;
	struct s_data			*next;
	struct s_data			*prev;
}							t_data;

int							get_next_line(const int fd, char **line);

#endif
