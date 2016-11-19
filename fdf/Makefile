# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 13:19:43 by edal-san          #+#    #+#              #
#    Updated: 2016/11/18 21:23:54 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	= main.c test_line_draw.c

NAME		= fdf
CC			= gcc
CFLAGS		+= -Wall -Werror -Wextra
AFLAGS		+= -fsanitize=address
INC			+= -Iincludes/

SRCS		= $(addprefix srcs/, $(FILENAMES))
OBJS		= $(addprefix build/, $(FILENAMES:.c=.o))

LIBFT		= ./libft/libft.a 
LIBFTINC	= -I./libft/includes/
LIBFTLINK	= -L./libft -lft

LIBMLX		= ./minilibx_macos/libmlx.a 
LIBMLXINC	= -I./minilibx_macos/
LIBMLXLINK	= -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -Iminilibx_macos

.PHONY: all clean fclean re

all: libft $(NAME) clean

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) $(INC) $(LIBFTINC) $(LIBMLXINC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./libft

libmlx: $(LIBMLX)

$(LIBMLX):
	make -C ./minilibx_macos

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC) $(LIBFTLINK) $(LIBMLXLINK) -o $@ $^

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

re: fclean all
