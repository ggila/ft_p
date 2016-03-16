/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/16 15:36:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

static int	addtoglobal(int csock)
{
	int	i;

	i = 0;
	while (g_client[i].sock)
		i++;
	if (i == NB_CONNEX)
		return (KO);
	g_client[i].sock = csock;
	g_client[i].netpwd[0] = '/';
	g_client[i].netpwd[1] = '\0';
	return (OK);
}

static void	newclient(int sock, fd_set *all, int *max_sock)
{
	struct sockaddr_in	client_sin;
	unsigned int		cs_len;
	int					client_sock;

	cs_len = sizeof(struct sockaddr);
	if ((client_sock = accept(sock, (struct sockaddr*)&client_sin, &cs_len))
			== -1)
	{
		ft_printf("accept() failed\n");
		return ;
	}
	if (addtoglobal(client_sock) == KO)
	{
		ft_printf("too much client right now\n");
		return ;
	}
	if (client_sock > *max_sock)
		*max_sock = client_sock;
	FD_SET(client_sock, all);
	printclient();
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
	int	max_sock;

	max_sock = sock;
	FD_ZERO(&all);
	FD_SET(sock, &all);
	while (1)
	{
		FD_ZERO(&fds);
		FD_COPY(&all, &fds);
		if (select(max_sock + 1, &fds, NULL, NULL, NULL) == -1)
			quit("select() error");
		if (FD_ISSET(sock, &fds))
			newclient(sock, &all, &max_sock);
		checkclient(&fds, &all);
	}
}
