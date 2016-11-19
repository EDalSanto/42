# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/20 17:37:09 by edal-san          #+#    #+#              #
#    Updated: 2016/11/09 21:36:49 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= 	ft_printf.c detectives.c adders.c handle_nums.c handle_str.c wide_char_helpers.c
FILENAMES	+= 	ft_putwchar.c fw_and_pr_helpers.c get_arg.c get_arg_len.c handle_arg.c	
FILENAMES	+=	handle_flags.c parser.c print_detective.c printers.c spaces_detectives.c	

NAME	 	=	libftprintf.a

LIBFT		=	libft/libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	$(addprefix srcs/, $(FILENAMES))
OBJS		=	$(addprefix build/, $(FILENAMES:.c=.o))

.PHONY:		all clean fclean re

all: $(NAME) 

build:
	mkdir $@

build/%.o: srcs/%.c | build
	$(CC) $(CFLAGS) -I includes/ -c $< -o $@

$(NAME): $(OBJS) 
	ar -x libft/libft.a
	ar rcs $@ $(OBJS) *.o
	ranlib $@
	rm *.o

clean:
	rm -rf build/
	rm -rf __.SYMDEF\ SORTED
	rm -rf __.SYMDEF

fclean: clean
	rm -f $(NAME)

re: fclean all
