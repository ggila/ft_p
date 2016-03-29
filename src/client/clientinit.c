/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:12:03 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/29 15:17:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

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
	{
		ft_printf("getprotobyname() error\n");
		return (KO);
	}
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
	{
		ft_printf("socket() error\n");
		return (KO);
	}
	sininit(&sin, addr, port);
	if (connect(sock, (const struct sockaddr *) &sin, sizeof(sin)) == -1)
	{
		ft_printf("connect() error\n");
		return (KO);
	}
	return (sock);
}
