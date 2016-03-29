# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/08 19:45:49 by ggilaber          #+#    #+#              #
#    Updated: 2016/03/29 16:07:19 by ggilaber         ###   ########.fr        #
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
	make -C src/serveur/
	@ln -fs src/serveur/serveur serveur

client: $(LIB_A)
	make -C src/client/
	@ln -fs src/client/client client

$(LIB_A): src/lib/.git
	@echo 'build $(notdir $@)'
	@make -C $(dir $@)
	@make clean -C $(dir $@)

src/lib/.git:
	git submodule init
	git submodule update

clean:
	make -C src/client clean
	make -C src/serveur clean

fclean: clean
	for l in $(LIB_DIR); do make -C $$l fclean; done
	rm -f serveur client
	@echo

re: fclean all
