/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discuss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 20:59:38 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 18:22:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	discuss(int sock)
{
	char	line[250];

	ft_init();
	while (1)
	{
		SET_BLACK;
		ft_prompt();
		ft_get_cmd(line);
		SET_WHITE;
		ft_putstr_fd(line, sock);
		handlecmd(line);
	}
}
