/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 03:29:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/10 22:53:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	long unsigned int	l;

	if (!b)
		return (NULL);
	i = 0;
	l = 0;
	while (i < 8)
		l += c << (8 * i);
	while (i < len / 8)
	{
		*((long unsigned int*)b + i) = l;
		i += 8;
	}
	while (i < len)
	{
		((char*)b)[i] = c;
		++i;
	}
	return (b);
}
