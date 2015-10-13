/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:05:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:48:38 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstrlen(char **str)
{
	int	n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		++n;
	return (n);
}
