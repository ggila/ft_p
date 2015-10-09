# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:17:44 by ggilaber          #+#    #+#              #
#    Updated: 2015/10/09 18:33:41 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

ITER = 0

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = lib.a

SRC = ft_atoi.c\
	  ft_putstr.c\
	  ft_putchar.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=%.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))


all : $(NAME)

$(NAME) : $(OBJ_PATH)
	@ar rc  $(NAME) $(OBJ_PATH)
	@ranlib $(NAME)
	@rm -rf $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c
	@printf "$(C_BLACK).$(C_DEFAULT)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $^ -o $@

fclean :
	@rm -rf $(NAME)

re : fclean all
