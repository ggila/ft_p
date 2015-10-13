/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 17:30:02 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:38:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstpush(t_list *alst, t_list *new)
{
	if (!alst || !new)
		return ;
	while (alst->next)
		alst = alst->next;
	alst->next = new;
}
