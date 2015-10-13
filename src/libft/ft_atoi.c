/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:53:00 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/06 09:13:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	myatoi(const char *str, int n)
{
	if (*str >= '0' && *str <= '9')
	{
		n = 10 * n + *str - '0';
		str++;
		return (myatoi(str, n));
	}
	else
		return (n);
}

int			ft_atoi(const char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		str++;
		return (-myatoi(str, 0));
	}
	if (*str == '+')
		str++;
	return (myatoi(str, 0));
}
