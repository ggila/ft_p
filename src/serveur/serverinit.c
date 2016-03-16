/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:12:03 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/16 15:35:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

static void	sininit(struct sockaddr_in	*sin, int port)
{
	sin->sin_family = AF_INET;
	sin->sin_port = htons(port);
	sin->sin_addr.s_addr = htonl(INADDR_ANY);
}

int	serverinit(int port)
{
	int					sock;
	struct protoent		*prot;
	struct sockaddr_in	sin;

	if ((prot = getprotobyname("tcp")) == 0)
		return (ft_printf("getprotobyname() error\n"), KO);
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		return (ft_printf("socket() error\n"), KO);
	sininit(&sin, port);
	if (bind(sock, (const struct sockaddr *) &sin, sizeof(sin)) == -1)
		return (ft_printf("bind() error\n"), KO);
	listen(sock, NB_CONNEX);
	return (sock);
}
