/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:54:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:46:16 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((char)c == *s)
		{
			while (s[++i])
			{
				if ((char)c == s[i])
					return (ft_strrchr(s + i, c));
			}
			return ((char*)s);
		}
		s++;
	}
	if ((char)c == *s)
		return ((char *)s);
	return (NULL);
}
