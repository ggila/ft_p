/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/11 20:56:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int	addtoglobal(int csock)
{
	int	i;

	i = 0;
	while (g_client[i].sock)
		i++;
	if (i == NB_CONNEX)
		return (KO);
	g_client[i].sock = csock;
	return (OK);
}

static void	newclient(int sock, fd_set *all)
{
	struct sockaddr_in	client_sin;
	unsigned int		cs_len;
	int					client_sock;

	cs_len = sizeof(struct sockaddr);
	if ((client_sock = accept(sock, (struct sockaddr*)&client_sin, &cs_len))
			== -1)
	{
		ft_putstr("accept() failed\n");
		return ;
	}
	if (addtoglobal(client_sock) == KO)
	{
		ft_putstr("too much client right now\n");
		return ;
	}
	if (client_sock > g_max)
		g_max = client_sock;
	FD_SET(client_sock, all);
	return ;
}

static void	checkclient(fd_set *fds, fd_set *all)
{
	int	i;

	i = -1;
	while (g_client[++i].sock)
		if (FD_ISSET(g_client[i].sock, fds))
			listenclient(g_client[i].sock, all);
}

void		serverloop(int sock)
{
	fd_set 	fds;
	fd_set 	all;

	FD_ZERO(&all);
	FD_SET(sock, &all);
	while (1)
	{
		FD_COPY(&all, &fds);
		if (select(g_max + 1, &fds, NULL, NULL, NULL) == -1)
			quit("select() error");
		if (FD_ISSET(sock, &fds))
			newclient(sock, &all);
		checkclient(&fds, &all);
	}
}
