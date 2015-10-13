/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 12:12:34 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:46:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	if (!s1 || !s2)
		return (NULL);
	if (!(*s2))
		return ((char*)s1);
	i = 0;
	while (s1[i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[j + i] && s2[j] && i + j < n)
		{
			j++;
			if (!s2[j])
				return ((char*)(s1 + i));
		}
		i++;
	}
	return (NULL);
}
