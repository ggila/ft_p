/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:46:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:39:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	if (!b)
		return (NULL);
	i = -1;
	while (++i < len)
		((unsigned char *)b)[i] = (unsigned char)c;
	return (b);
}
