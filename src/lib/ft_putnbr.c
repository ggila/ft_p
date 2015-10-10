/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:29:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/10 23:13:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	ft_putnbr_fd(int n, int fd);

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}