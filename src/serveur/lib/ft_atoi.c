/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 13:53:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/08 20:07:43 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	while (*str == ' ')
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
