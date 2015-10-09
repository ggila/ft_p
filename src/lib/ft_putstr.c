/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 22:01:48 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/08 20:03:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char const *str)
{
	size_t n;

	if (!str)
		return (0);
	n = 0;
	while (str[n])
		++n;
	return (n);
}

void	ft_putstr_fd(const char *str, int fd)
{
	if (!str)
		return ;
	else
		write(fd, str, ft_strlen(str));
}

void	ft_putstr(char const *str)
{
	ft_putstr_fd(str, 1);
}
