# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 13:19:43 by edal-san          #+#    #+#              #
#    Updated: 2016/11/11 11:30:19 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= main.c

NAME		= ft_ls
CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra
INC			+= -Iincludes/

SRCS		= $(addprefix srcs/, $(FILENAMES))
OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

LIBFT		= ./libft/libft.a 
LIBINC		= -I./libft/includes/
LIBLINK		= -L./libft -lft

.PHONY: all clean fclean re

all: libft $(NAME) clean

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) $(INC) $(LIBINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(LIBLINK) -o $@ $^

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

re: fclean all
