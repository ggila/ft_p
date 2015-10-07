/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:12:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/07 18:43:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	sininit(struct sockaddr_in	*sin, int port)
{
	sin->sin_family = AF_INET;
	sin->sin_port = htons(port);
	sin->sin_addr.s_addr = htonl(INADDR_ANY);
}

int	serverinit(int port)
{
	int					socket;
	struct protoent		*prot;
	struct sockaddr_in	sin;

	if ((prot = getprotobyname("tcp")) == 0)
		return (KO);
	if((socket = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		return (KO);
	sininit(&sin, port);
	if (bind(sock, (const struct sockaddr *) &sin, sizeof(sin)) == -1)
		return (KO);
	listen(sock, NB_CONNEX);
	return (socket);
}
