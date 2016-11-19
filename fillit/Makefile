# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 08:49:34 by edal-san          #+#    #+#              #
#    Updated: 2016/10/20 18:05:23 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= main.c solve_arr.c placement.c tetri_arr.c tetri_detective.c tetri_struct.c valid.c 

TARGET		= fillit 
CC			= gcc
CFLAGS		+= -Wall -Wextra -Werror 
CFLAGS		+= -I includes/

SRCS	= $(addprefix srcs/, $(FILENAMES))
OBJS	= $(addprefix build/, $(FILENAMES:.c=.o))

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK = -L./libft -lft

.PHONY: all clean fclean re

all: libft $(TARGET) clean  

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) $(LIBINC) -o $@ -c $< 

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LIBLINK) -o $@ $^

clean:
	rm -rf build/

fclean: clean
	rm -f $(TARGET)

re: fclean all
