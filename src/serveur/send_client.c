/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 07:36:52 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/13 16:52:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	send_client(int sock, char *str, char success)
{
	ft_putchar_fd(success, sock);
	ft_putstr_fd(str, sock);
}
