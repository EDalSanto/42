# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edal-san <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 13:19:43 by edal-san          #+#    #+#              #
#    Updated: 2016/12/03 16:05:31 by edal-san         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PSW_TARGET		= push_swap
CH_TARGET		= checker

CC				= gcc 
CFLAGS			= -Wall -Wextra -Werror -fsanitize=address

LIBFT			= ./libft/libft.a
LIBFTINC		= -I./libft/includes/
LIBFTLINK		= -L./libft -lft

PSW_SRC_PATH	= ./p_swap/srcs/
PSW_FILES		= main.c ops1.c ops2.c display.c is.c
PSW_OBJ_PATH	= ./ps_objs/
PSW_SRC			= $(addprefix $(PSW_SRC_PATH), $(PSW_FILES))
PSW_OBJ			= $(addprefix $(PSW_OBJ_PATH), $(PSW_FILES:.c=.o))
PSW_INC			= -I./p_swap/includes/ $(LIBFTINC)

CH_SRC_PATH		= ./p_checker/srcs/
CH_FILES		= main.c ops1.c ops2.c display.c is.c
CH_OBJ_PATH		= ./pc_objs/
CH_SRC			= $(addprefix $(CH_SRC_PATH), $(CH_FILES))
CH_OBJ			= $(addprefix $(CH_OBJ_PATH), $(CH_FILES:.c=.o))
CH_INC			= -I./p_checker/includes/ $(LIBFTINC)

all: $(PSW_TARGET) $(CH_TARGET) 

$(PSW_TARGET): $(PSW_OBJ)
	@echo "push_swap : Sources compiling..."
	@make -C ./libft/
	@$(CC) $(CFLAGS) $(PSW_INC) -o $@ $(PSW_OBJ) $(LIBFTLINK)	
	@echo "push_swap : compiled with success!"

$(CH_TARGET): $(CH_OBJ)
	@echo "checker : Sources compiling..."
	@$(CC) $(CFLAGS) $(CH_INC) -o $@ $(CH_OBJ) $(LIBFTLINK)
	@echo "checker: compiled with success!"

$(PSW_OBJ_PATH)%.o: $(PSW_SRC_PATH)%.c
	@mkdir $(PSW_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(PSW_INC) $(LIBFTINC) -o $@ -c $<

$(CH_OBJ_PATH)%.o: $(CH_SRC_PATH)%.c
	@mkdir $(CH_OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(CH_INC) $(LIBFTINC) -o $@ -c $<

clean:
	@make -C libft/ clean
	@rm -f $(PSW_OBJ)
	@rmdir $(PSW_OBJ_PATH) 2> /dev/null || true
	@rm -f $(CH_OBJ)
	@rmdir $(CH_OBJ_PATH) 2> /dev/null || true
	@echo "Objects removed"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(PSW_TARGET) $(CH_TARGET)
	@echo "./checker and ./push_swap removed"

re: fclean all
	@make -C libft/ re

.PHONY: all, clean, fclean, re
