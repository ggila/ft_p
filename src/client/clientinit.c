/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:12:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/11 20:20:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	sininit(struct sockaddr_in	*sin, char *addr, int port)
{
	sin->sin_family = AF_INET;
	sin->sin_port = htons(port);
	sin->sin_addr.s_addr = inet_addr(addr);
}

int	clientinit(char *addr, int port)
{
	int					sock;
	struct protoent		*prot;
	struct sockaddr_in	sin;

	if ((prot = getprotobyname("tcp")) == 0)
		return (ft_putstr("getprotobyname() error\n"), KO);
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		return (ft_putstr("socket() error\n"), KO);
	sininit(&sin, addr, port);
	if (connect(sock, (const struct sockaddr *) &sin, sizeof(sin)) == -1)
		return (ft_putstr("connect() error\n"), KO);
	return (sock);
}
