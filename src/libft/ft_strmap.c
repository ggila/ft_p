/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 19:56:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:45:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	i = -1;
	while (str[++i])
		str[i] = f(str[i]);
	return (str);
}
