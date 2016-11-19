/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freopentst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:05:49 by edal-san          #+#    #+#             */
/*   Updated: 2016/10/23 17:12:44 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		main(void)
{
	int		newfd;
	int		stdout_cpy;

	printf("This goes to stdout\n");
	stdout_cpy = dup(STDOUT_FILENO);
	newfd = open("redir", O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
	fflush(stdout);
	dup2(newfd, STDOUT_FILENO);	
	printf("this goess?\n");
	dup2(stdout_cpy, STDOUT_FILENO);
	close(stdout_cpy);
	printf("and this goes?\n");
}
