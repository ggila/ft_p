/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:45:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:45:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t srclen;
	size_t dstlen;
	size_t i;

	if (!dst || !src)
		return (0);
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	if (size > dstlen + 1)
	{
		while (src[i] && i < size - dstlen - 1)
		{
			dst[i + dstlen] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = '\0';
	if (size < dstlen)
		return (size + srclen);
	return (dstlen + srclen);
}
