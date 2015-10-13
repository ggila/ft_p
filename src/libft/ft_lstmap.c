/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 19:14:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 16:38:32 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *clist;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	clist = ft_lstdup(lst);
	temp = clist;
	while (temp)
	{
		f(temp);
		temp = temp->next;
	}
	free(temp);
	return (clist);
}
