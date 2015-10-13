/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:09:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:38:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*str;
	size_t	i;

	if (!size)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = '\0';
	return ((void*)str);
}
