/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/07 18:45:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	usage(char *prog)
{
	ft_putstr("Usage: ");
	ft_putstr(prog);
	ft_putstr(" <port>\n");
	exit(KO);
}

int			main(int ac, char **av)
{
	int	port;
	int	socket;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	if ((socket = serverinit(port)) == KO)
		return (KO);
	tobenamed(socket)
	close(socket);
	return (OK)
}
