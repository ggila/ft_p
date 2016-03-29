/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:03:55 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/29 20:20:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

void		quit(char *str)
{
	int	i;

	i = -1;
	while (g_client[++i].sock)
		close(g_client[i].sock);
	ft_printf("%s\n", str);
	exit(KO);
}

static void	usage(char *prog)
{
	ft_printf("Usage: %s <port>", prog);
	exit(KO);
}

static char	is_basedir(void)
{
	struct stat	buf;

	if ((stat("./basedir/", &buf) == -1)
			|| (!S_ISDIR(buf.st_mode)))
	{
		ft_printf("basedir/ should be present\n");
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
	ft_bzero(g_client, sizeof(t_client) * (NB_CONNEX + 2));
	if ((sock = serverinit(port)) == KO)
		return (KO);
	serverloop(sock);
	close(sock);
	return (OK);
}
