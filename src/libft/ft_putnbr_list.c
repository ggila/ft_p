/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 14:31:14 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:41:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_list(t_list *list)
{
	while (list->next)
	{
		ft_putnbr(*(int*)(list->content));
		ft_putstr("->");
		list = list->next;
	}
	ft_putnbr(*(int*)list->content);
	ft_putchar('\n');
}
