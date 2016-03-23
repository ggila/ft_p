# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:45:49 by ggilaber          #+#    #+#              #
#    Updated: 2016/03/23 09:27:31 by ggilaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


.PHONY : clean fclean re all serveur client

LIB = libft\
	hash_tables\
	ft_printf
LIB_DIR = $(addsuffix /, $(addprefix src/lib/, $(LIB)))
LIB_INC = $(addprefix -I./, $(LIB_DIR))
LIB_A = $(join $(LIB_DIR), $(addsuffix .a, $(LIB)))

all: serveur client

serveur: $(LIB_A)
	@echo "make serveur"
	@make -C src/serveur/
	@mv src/serveur/serveur .

client: $(LIBA_A)
	@echo "make client"
	@make -C src/client/
	@mv src/client/client .

$(LIB_A): $(LIB_DIR)
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

$(LIB_DIR):
	git submodule init
	git submodule update

clean:
	make -C src/client clean
	make -C src/serveur clean

fclean: clean
	for l in $(LIB_DIR); do make -C $$l fclean; done
	rm -f serveur client

re: fclean all
