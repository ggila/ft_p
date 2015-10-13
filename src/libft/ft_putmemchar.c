/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmemchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:19:15 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:40:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmemchar(const void *p, size_t n)
{
	size_t i;

	if (!p || !n)
		return ;
	ft_putchar('_');
	i = -1;
	while (++i < n)
	{
		if (!(((unsigned char*)p)[i]))
			ft_putstr("\\0_");
		else if (ft_isprint(((unsigned char*)p)[i]))
		{
			ft_putchar(((unsigned char *)p)[i]);
			ft_putstr(" _");
		}
		else
		{
			ft_putchar('\'');
			ft_putnbr((((char*)p)[i]));
			ft_putstr("'_");
		}
	}
	ft_putchar('\n');
}
