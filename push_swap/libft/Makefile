# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/26 08:49:34 by edal-san          #+#    #+#              #
#    Updated: 2016/12/02 16:57:44 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= gcc
CFLAGS		+= -Wall -Wextra -Werror 

INCDIR		= includes
LIBFTDIR	= libftfuncs
PFDIR		= ft_printf

LIBFT_FILES	=	ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint		\
				ft_toupper ft_tolower ft_putchar ft_putstr					\
				ft_putendl ft_putnbr ft_putchar_fd ft_putstr_fd				\
				ft_putendl_fd ft_putnbr_fd ft_itoa ft_itoa_base_unsigned	\
				ft_itoa_unsigned ft_atoi ft_putnbr_base int_base_len		\
				ft_put_base_unsigned_caps ft_strcpy ft_strncpy ft_strcmp	\
				ft_strncmp ft_strlen ft_strequ ft_strnequ ft_memmove		\
				ft_memcpy ft_memccpy ft_memcmp ft_strstr ft_memchr			\
				ft_strchr ft_strrchr ft_strnstr ft_strcat ft_strncat		\
				ft_strlcat ft_strjoin ft_strsub ft_strsplit ft_strtrim		\
				ft_memset ft_bzero ft_strnew ft_memalloc ft_strdup			\
				ft_memdel ft_strdel ft_strclr ft_striter ft_striteri		\
				ft_strmap ft_strmapi ft_lstadd  ft_lstdel ft_lstdelone		\
				ft_lstmap ft_lstiter ft_lstnew print_int_arr 			\
				ft_realloc ft_int_len ft_put_base ft_put_base_unsigned		\
				ft_itoa_capital_base ft_itoa_base_unsigned_cap				\
				get_next_line

PRINTF_FILES	=	adders detectives ft_printf ft_putwchar fw_and_pr_helpers	\
				get_arg get_arg_len handle_arg handle_flags handle_nums			\
				handle_str parser print_detective printers						\
				spaces_detectives wide_char_helpers

SRCS		=	$(addprefix $(LIBFTDIR)/,$(addsuffix .c,$(LIBFT_FILES)))		\
				$(addprefix $(PFDIR)/,$(addsuffix .c,$(PRINTF_FILES))) 

OBJS		= 	$(addsuffix .o,$(LIBFT_FILES))									\
				$(addsuffix .o,$(PRINTF_FILES)) 

.PHONY: all clean fclean re

all: $(NAME) clean

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS) 
	@ranlib $(NAME)
	@echo "Libft created!"

$(OBJS): $(SRCS)
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(INCDIR)

clean:
	@rm -rf $(OBJS) 
	@echo "LIBFT objects removed"
	
fclean: clean
	@rm -f $(NAME)
	@echo "libft archive removed"

re: fclean all 
