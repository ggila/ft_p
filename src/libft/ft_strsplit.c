/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:04:06 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/09 22:59:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_strcdup(char const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = '\0';
	while (i-- >= 1)
		str[i] = s[i];
	return (str);
}

static int	ft_countword(char const *s, char c)
{
	int flag;
	int n;

	flag = 1;
	n = 0;
	while (*s)
	{
		if (flag && *s != c)
		{
			n++;
			flag = 0;
		}
		if (!flag && *s == c)
			flag = 1;
		s++;
	}
	return (n);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		n;
	int		i;

	if (!s)
		return (NULL);
	n = ft_countword(s, c);
	if (!n)
		n++;
	if (!(str = (char**)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	str[n] = NULL;
	i = 0;
	while (i < n)
	{
		while (*s == c)
			s++;
		if (!(str[i] = ft_strcdup(s, c)))
			return (NULL);
		if (i < n - 1)
			s = s + ft_strlen(str[i]);
		i++;
	}
	return (str);
}
