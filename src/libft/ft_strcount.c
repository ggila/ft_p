/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:29:42 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:43:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcount(char *str, char c)
{
	int n;

	if (!str)
		return (0);
	n = 0;
	while (*str)
	{
		if (*str == c)
			n++;
		str++;
	}
	return (n);
}