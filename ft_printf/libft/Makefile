# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 08:49:34 by edal-san          #+#    #+#              #
#    Updated: 2016/11/09 17:42:07 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILENAMES	+= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
FILENAMES	+= ft_toupper.c ft_tolower.c int_base_len.c

FILENAMES	+= ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c
FILENAMES	+= ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
FILENAMES	+= ft_itoa.c ft_itoa_base_unsigned.c ft_itoa_unsigned.c

FILENAMES	+= ft_atoi.c ft_putnbr_base.c int_base_len.c ft_put_base_unsigned_caps.c

FILENAMES	+= ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strlen.c

FILENAMES	+= ft_strequ.c ft_strnequ.c

FILENAMES	+= ft_memmove.c ft_memcpy.c ft_memccpy.c ft_memcmp.c

FILENAMES	+= ft_strstr.c ft_memchr.c ft_strchr.c ft_strrchr.c
FILENAMES	+= ft_strnstr.c

FILENAMES	+= ft_strcat.c ft_strncat.c ft_strlcat.c

FILENAMES	+= ft_strjoin.c

FILENAMES	+= ft_strsub.c

FILENAMES	+= ft_strsplit.c ft_strtrim.c

FILENAMES	+= ft_memset.c ft_bzero.c ft_strnew.c ft_memalloc.c ft_strdup.c ft_memdel.c
FILENAMES	+= ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c

FILENAMES	+= ft_lstadd.c  ft_lstdel.c ft_lstdelone.c ft_lstmap.c ft_lstiter.c ft_lstnew.c

FILENAMES	+= ft_print_int_arr.c ft_realloc.c ft_int_len.c ft_put_base.c ft_put_base_unsigned.c

FILENAMES	+= ft_put_widestr.c ft_wide_strcpy.c ft_wide_strlen.c ft_itoa_capital_base.c 

FILENAMES	+= ft_itoa_base_unsigned_cap.c

NAME		= libft.a
CC			= gcc
CFLAGS		+= -Wall -Wextra -Werror -I includes

OBJS		= 	$(addprefix build/, $(FILENAMES:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

re: fclean all

clean:
	rm -rf build/

fclean: clean
	rm -f $(NAME)

build:
	mkdir build/

$(NAME): $(OBJS)
	ar rcs $@ $^
	ranlib $@

build/%.o: %.c | build
	$(CC) $(CFLAGS) -c $< -o $@
