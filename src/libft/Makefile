# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 13:17:44 by ggilaber          #+#    #+#              #
#    Updated: 2015/01/16 02:02:14 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

C_DEFAULT =		\033[0m
C_BLACK = 		\033[1;30m
C_GREY =		\033[1;37m

ITER = 0

CC = gcc

FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putnbr_fd.c ft_putnbr.c ft_strcmp.c ft_strncmp.c ft_strrep.c \
	ft_strcpy.c ft_strdup.c ft_isspace.c ft_strncpy.c ft_strcat.c \
	ft_strncat.c ft_strlcat.c ft_strstr.c ft_striter.c ft_striteri.c \
	ft_strequ.c ft_strnequ.c ft_memset.c ft_strnew.c ft_strdel.c ft_strmap.c \
	ft_strmapi.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_bzero.c \
	ft_memcpy.c ft_strchr.c ft_putmemchar.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_strclr.c ft_memalloc.c ft_memdel.c ft_memcmp.c \
	ft_strrchr.c ft_strnstr.c ft_strsplit.c ft_lstnew.c ft_putchar_list.c \
	ft_putstr_list.c ft_putnbr_list.c ft_memclr.c ft_lstdelone.c ft_lstadd.c \
	ft_lstdup.c ft_lstpush.c ft_lstiter.c ft_lstmap.c ft_lstdel.c ft_lstlen.c \
	ft_strndup.c ft_strcount.c ft_putstrstr.c ft_strstrlen.c ft_strstrfree.c

OBJ_DIR = obj
OBJ = $(SRC:%.c=%.o)
OBJ_PATH = $(addprefix $(OBJ_DIR)/, $(OBJ))

INC = -I./inc

all : $(NAME)

$(NAME) : echo_libft $(OBJ_PATH) ./inc/libft.h
	@echo "\n$(C_BLACK)ar rc $(NAME) file.o"
	@ar rc  $(NAME) $(OBJ_PATH)
	@ranlib $(NAME)
	@echo "$(C_BLACK)rm -rf ./libft/obj/ $(C_DEFAULT)"
	@rm -rf $(OBJ_DIR)

echo_libft :
	@echo "$(C_BLACK)make ./libft/libft.a$(C_DEFAULT)"

$(OBJ_DIR)/%.o : %.c
	@printf "$(C_BLACK).$(C_DEFAULT)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $^ -o $@

fclean :
	@echo "$(C_BLACK)rm -rf ./libft/$(NAME)"
	@rm -rf $(NAME)

re : fclean all

