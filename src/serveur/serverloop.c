/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/09 17:03:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	serverloop(int sock)
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


/*
void	serverloop(int sock)
{
	fd_set 	fds;

	while (1)
	{
		FD_ZERO(&fds);
		add_client_socket();
		FD_SET(sock, &fds);
		if (select(max + 1, &fdset, NULL, NULL, NULL) == pasbon)
			return
		if (FD_ISSET(sock, fdset))
			acceptclient();
		check_fdset()  // pour chaque client, verifie si il parle ()
	}
}*/
