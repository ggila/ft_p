# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:45:49 by ggilaber          #+#    #+#              #
#    Updated: 2015/10/09 18:35:25 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : clean fclean re all

all: serveur client

serveur: src/lib/lib.a
	@echo "make serveur"
	@make -C src/serveur/
	@mv src/serveur/serveur .

client: src/lib/lib.a
	@echo "make client"
	@make -C src/client/
	@mv src/client/client .

src/lib/lib.a:
	@echo 'make lib'
	@make -C src/lib
	@echo "\n"

clean:
	make -C src/client clean
	make -C src/serveur clean

fclean: clean
	make -C src/lib fclean
	rm -f serveur client

re: fclean all
