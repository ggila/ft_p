/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 13:06:11 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:42:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_list(t_list *list)
{
	while (list->next)
	{
		ft_putstr((char const*)(list->content));
		ft_putstr("->");
		list = list->next;
	}
	ft_putstr((char const*)list->content);
	ft_putchar('\n');
}
