/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 07:36:52 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/23 11:43:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

void	send_client(int sock, char *str, char success)
{
	ft_printf_fd(sock, "%c", success);
	ft_printf_fd(sock, "%s", str);
}
