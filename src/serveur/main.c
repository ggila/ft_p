/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/19 20:46:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void		quit(char *str)
{
	int	i;

	i = -1;
	while (g_client[++i].sock)
		close(g_client[i].sock);
	ft_putstr(str);
	ft_putstr("\n");
	exit(KO);
}

static void	usage(char *prog)
{
	ft_putstr("Usage: ");
	ft_putstr(prog);
	ft_putstr(" <port>\n");
	exit(KO);
}

static char	is_basedir(void)
{
	struct stat	buf;

	if ((stat("./basedir/", &buf) == -1)
			|| (!S_ISDIR(buf.st_mode)))
	{
		ft_putendl("basedir/ should be present");
		return (KO);
	}
	return (OK);
}

int			main(int ac, char **av)
{
	int	port;
	int	sock;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	if (is_basedir() == KO)
		return (OK);
	ft_memset(g_client, 0, NB_CONNEX + 1);
	if ((sock = serverinit(port)) == KO)
		return (KO);
	serverloop(sock);
	close(sock);
	return (OK);
}
