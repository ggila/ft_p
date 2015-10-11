/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenclient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 15:58:37 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/11 20:37:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	listenclient(int sock, fd_set *all)
{
	char	b[30];
	int r;

	(void)all;
	r=read(sock, b, 30);
b[r] = 0;
	ft_putstr(b);
}
