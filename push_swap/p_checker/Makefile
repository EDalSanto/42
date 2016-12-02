# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 13:19:43 by edal-san          #+#    #+#              #
#    Updated: 2016/12/02 08:08:34 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= main.c

NAME		= checker 
CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra
AFLAGS		+= -fsanitize=address
INC			+= -Iincludes/

SRCS		= $(addprefix srcs/, $(FILENAMES))
OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

LIBFT		= ../libft/libft.a 
LIBFTINC	= -I../libft/includes/
LIBFTLINK	= -L../libft -lft

.PHONY: all clean fclean re

all: libft $(NAME) clean

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(AFLAGS) $(CFLAGS) $(INC) $(LIBFTINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ../libft

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(AFLAGS) $(INC) $(LIBFTLINK) -o $@ $^
	mv $@ ../

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

re: fclean all
