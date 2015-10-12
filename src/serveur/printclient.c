/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serverloop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/08 22:07:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/11 20:25:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	printfd(void)
{
	int i;

	i = 0;
	ft_putchar('{');
	while (g_client[i].sock)
	{
		ft_putnbr(g_client[i].sock);
		if (g_client[++i].sock)
			ft_putstr(", ");
	}
	ft_putchar('}');
	ft_putchar('\n');
}

void	printclient(void)
{
	printfd();
}
