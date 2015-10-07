/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:36:57 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/07 18:41:06 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	tobenamed(int socket)
{
	struct sockaddr_in	client_sin;
	unsigned int		cs_len;
	int					client_socket;

	client_socket = accept(socket, (struc sockaddr*)&client_sin, &cs_len);
	close(client_socket);
}
