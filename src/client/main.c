/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/29 21:25:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

static void	usage(char *prog)
{
	ft_printf("Usage: %s <adress> <port>\n", prog);
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
	int		port;
	int		sock;
	char	*addr;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	addr = ft_strcmp(av[1], "localhost") ? av[1] : "127.0.0.1";
	handle_sig();
	if ((sock = clientinit(addr, port)) == KO)
		return (KO);
	ft_printf("blabla");
	discuss(sock);
	close(sock);
	return (OK);
}
