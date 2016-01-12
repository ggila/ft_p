/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/12 18:52:50 by ggilaber         ###   ########.fr       */
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

void		handle_sig(void)
{
	struct sigaction	sig;

	sig.sa_handler = SIG_IGN;
	sigaction(SIGTSTP, &sig, NULL);
}

int			main(int ac, char **av)
{
	int	port;
	int	sock;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	handle_sig();
	if ((sock = clientinit(av[1], port)) == KO)
		return (KO);
	discuss(sock);
	close(sock);
	return (OK);
}
