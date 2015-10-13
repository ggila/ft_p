/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 00:29:14 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:39:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (!dst || !src)
		return (NULL);
	if (len && dst < src)
	{
		i = -1;
		while (++i < len)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
	}
	if (len && dst > src)
	{
		i = len;
		while (--i > 0)
			((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
		((unsigned char*)dst)[0] = ((unsigned char*)src)[0];
	}
	return (dst);
}
