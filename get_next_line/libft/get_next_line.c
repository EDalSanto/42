/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 12:05:06 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/20 17:06:59 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			get_l(char *buf, char **line, int b_index)
{
	char			*l;

	l = *line;
	while (*l)
		l++;
	while (buf[b_index] != '\n' && buf[b_index])
		*l++ = buf[b_index++];
	if (buf[b_index])
		b_index++;
	*l = '\0';
	return (b_index);
}

static void			*find_fd(t_data **fdlst, const int fd)
{
	t_data			*cur;

	cur = *fdlst;
	while (cur)
	{
		if (cur->fd == fd)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static t_data		*setup(t_data **fdlst, const int fd)
{
	t_data			*new;

	if ((new = find_fd(fdlst, fd)))
		return (new);
	if (!(new = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	new->fd = fd;
	new->b_index = 0;
	new->b[BUFF_SIZE] = '\0';
	new->prev = NULL;
	ft_bzero(new->b, BUFF_SIZE + 1);
	if (*fdlst == 0)
	{
		*fdlst = new;
		new->next = NULL;
	}
	else
	{
		(*fdlst)->prev = new;
		new->next = *fdlst;
		*fdlst = new;
	}
	return (new);
}

static int			returns(t_data **fdlst, t_data *cur, char **line)
{
	if (cur->r < 0)
		return (-1);
	if ((cur->r == 0 && !(ft_strlen(*line))))
	{
		free(*line);
		if (*fdlst == cur)
			*fdlst = cur->next;
		if (cur->next != NULL)
			cur->next->prev = cur->prev;
		if (cur->prev != NULL)
			cur->prev->next = cur->next;
		free(cur);
		return (0);
	}
	cur->b_index = get_l(cur->b, line, cur->b_index);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	t_data	*head;
	t_data			*cur;

	if (fd < 0 || line == NULL)
		return (-1);
	cur = setup(&head, fd);
	*line = (char*)malloc(BUFF_SIZE + 1);
	ft_bzero(*line, BUFF_SIZE + 1);
	if (cur->b_index < cur->r)
	{
		if (ft_strchr(&cur->b[cur->b_index], '\n'))
			return (returns(&head, cur, line));
		cur->b_index = get_l(cur->b, line, cur->b_index);
		*line = (char*)ft_realloc(*line, 2 * BUFF_SIZE + ft_strlen(*line) + 1);
	}
	cur->b_index = 0;
	ft_bzero(cur->b, BUFF_SIZE + 1);
	while ((cur->r = read(fd, cur->b, BUFF_SIZE)) && !(ft_strchr(cur->b, '\n'))
			&& cur->r > 0)
	{
		get_l(cur->b, line, cur->b_index);
		*line = (char*)ft_realloc(*line, 2 * BUFF_SIZE + ft_strlen(*line) + 1);
		ft_bzero(cur->b, BUFF_SIZE + 1);
	}
	return (returns(&head, cur, line));
}
