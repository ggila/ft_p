# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/27 08:45:05 by ggilaber          #+#    #+#              #
#*   Updated: 2015/04/05 08:04:28 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = serveur

SRC = main.c\
	  serverinit.c\
	  serverloop.c\
	  lib/ft_putstr.c\
	  lib/ft_putchar.c\
	  lib/ft_atoi.c

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I../

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : echo_make $(OBJ_PATH)
	@echo "gcc -f -o $(NAME) .o -L"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH)

echo_make :
	@echo "$(C_WHITE)make ./$(NAME)$(C_DEFAULT)"

$(OBJ_DIR)/%.o : %.c
	@echo "\t$(C_BLACK)gcc -f -c $^ -o .o$(C_DEFAULT)"
	@mkdir -p obj/lib
#	@echo "\t$(C_BLACK)gcc -flag -I./inc/ -c $^ -o $@$(C_DEFAULT)"
	@$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean :
	@echo "$(C_BLACK)rm -rf ./$(OBJ_DIR)/$(C_DEFAULT)"
	@rm -rf $(OBJ_PATH)

fclean : clean
	@echo "$(C_BLACK)rm -rf ./$(NAME)$(C_DEFAULT)"
	@rm -rf $(NAME)

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch

test :
	gcc -o test.out test.c
