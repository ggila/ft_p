/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/10 23:55:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*void	serverloop(int sock)
{
	struct sockaddr_in	client_sin;
	unsigned int		cs_len;
	int					client_sock;
	int					r;
	char				buf[25];

	client_sock = accept(sock, (struct sockaddr*)&client_sin, &cs_len);
	r = read(client_sock, buf, 25);
	buf[r] = '\0';
	ft_putstr(buf);
	close(client_sock);
}
*/
static void	addsocks(fd_set *fds, int sock)
{
	int	i;

	i = -1;
	while (g_client[++i].sock)
		FD_SET(g_client[i].sock, fds);
	FD_SET(sock, fds);
}

void		serverloop(int sock)
{
	fd_set 	fds;
	int i;

	while (1)
	{
		FD_ZERO(&fds);
		addsocks(&fds, sock);
		if ((i = select(g_max + 1, &fds, NULL, NULL, NULL)) == -1)
			quit("select() error");
		while (i)
		{
			ft_putnbr(((int*)(&fds))[i]);
			ft_putchar('\t');
		}
//		if (FD_ISSET(sock, fdset))
//			acceptclient();
//		check_fdset()  // pour chaque client, verifie si il parle ()
	}
}
