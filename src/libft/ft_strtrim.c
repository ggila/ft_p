/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 23:27:46 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/09 18:06:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ispace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	len;

	if (!s)
		return (NULL);
	while (s && ft_ispace(*s))
		s++;
	len = ft_strlen(s);
	if (len)
	{
		while (ft_isspace(s[len - 1]))
			len--;
	}
	return (ft_strsub(s, 0, len));
}
