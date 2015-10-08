/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/08 22:49:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	usage(char *prog)
{
	ft_putstr("Usage: ");
	ft_putstr(prog);
	ft_putstr(" <adress> <port>\n");
	exit(KO);
}

int			main(int ac, char **av)
{
	int	port;
	int	sock;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	if ((sock = clientinit(av[1], port)) == KO)
		return (KO);
	ft_putstr_fd("je suis un client\n", sock);
	close(sock);
	return (OK);
}
