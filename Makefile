# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:45:49 by ggilaber          #+#    #+#              #
#    Updated: 2015/10/12 16:55:56 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

all: serveur client

serveur: src/libft/libft.a
	@echo "make serveur"
	@make -C src/serveur/
	@mv src/serveur/serveur .

client: src/libft/libft.a
	@echo "make client"
	@make -C src/client/
	@mv src/client/client .

src/libft/libft.a:
	@echo 'make lib'
	@make -C src/libft
	@echo "\n"

clean:
	make -C src/client clean
	make -C src/serveur clean

fclean: clean
	make -C src/libft fclean
	rm -f serveur client

re: fclean all
