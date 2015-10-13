/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:32:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:46:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s2))
		return ((char*)s1);
	i = 0;
	while (*s1)
	{
		i = 0;
		while (s1[i] == s2[i] && s1[i] && s2[i])
		{
			i++;
			if (!s2[i])
				return ((char*)s1);
		}
		s1++;
	}
	return (NULL);
}
