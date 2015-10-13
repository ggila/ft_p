/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 17:00:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:42:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** print a char** which ends by NULL
*/

void	ft_putstrstr(char **str)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putendl(*str);
		str++;
	}
}
