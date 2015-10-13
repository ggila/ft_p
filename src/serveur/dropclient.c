/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dropclient.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 11:21:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/13 12:00:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	dropclient(int sock, fd_set *all)
{
	int i;

	FD_CLR(sock, all);
	i = 0;
	while (g_client[i].sock != sock)
		i++;
	g_client[i].sock = 0;
	while (i < NB_CONNEX)
	{
		g_client[i].sock = g_client[i + 1].sock;
		i++;
	}
	close(sock);
	printclient();
}
