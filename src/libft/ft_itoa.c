/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 00:29:07 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:37:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char *c;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		return (ft_strjoin("-", ft_itoa(-n)));
	if (!(c = ft_strdup("0")))
		return (NULL);
	*c += n % 10;
	if (n >= 0 && n <= 9)
		return (ft_strdup(c));
	else
		return (ft_strjoin(ft_itoa(n / 10), c));
	return (0);
}
