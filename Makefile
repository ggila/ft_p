# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:45:49 by ggilaber          #+#    #+#              #
#    Updated: 2015/10/08 22:46:57 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

all: serveur client

serveur: serveur
	@echo "make serveur"
	@make -C src/serveur/
	@mv src/serveur/serveur .

client: client
	@echo "make client"
	@make -C src/client/
	@mv src/client/client .
