/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/08 22:52:08 by ggilaber         ###   ########.fr       */
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
