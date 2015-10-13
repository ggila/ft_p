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
	  listenclient.c\
	  printclient.c\
	  dropclient.c

OBJ_DIR = obj
OBJ = $(SRC:.c=.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I../\
	  -I../libft/inc

HEADER = $(addprefix $(inc), $(NAME).h)

all : $(NAME)

$(NAME) : $(OBJ_PATH)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ_PATH) ../libft/libft.a

$(OBJ_DIR)/%.o : %.c
	@echo "\t$(C_BLACK)gcc -f -c $^ -o .o$(C_DEFAULT)"
	@mkdir -p obj/lib
	@$(CC) $(FLAGS) $(INC) -c $^ -o $@

clean :
	@rm -rf $(OBJ_PATH)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

sw :
	rm -rf **/.*.sw[po]
	rm -rf **/.*.h.gch
	rm -rf ./inc/$(NAME).h.gch

test :
	gcc -o test.out test.c
