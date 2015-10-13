/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 10:12:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:43:39 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		n;
	char	*dst;

	if (!s1)
		return (NULL);
	n = ft_strlen(s1) + 1;
	if (!(dst = (char*)malloc(sizeof(char) * n)))
		return (NULL);
	while (--n)
		dst[n] = s1[n];
	*dst = *s1;
	return (dst);
}
