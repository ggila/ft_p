/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/23 11:42:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

static void	printfd(void)
{
	int i;

	i = 0;
	ft_printf("{");
	while (g_client[i].sock)
	{
		ft_printf("%d", g_client[i].sock);
		if (g_client[++i].sock)
			ft_printf(", ");
	}
	ft_printf("}");
	ft_printf("\n");
}

void	printclient(void)
{
	printfd();
}
