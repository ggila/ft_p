/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/22 08:26:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 17:54:58 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_error(char *str)
{
	SET_WHITE;
	ft_putendl(str);
	ft_restore_term();
	exit(1);
}

void	ft_restore_term(void)
{
	char	*res;
	char	*area;
	char	buf[20];

	area = buf;
	res = tgetstr("ei", &area);
	tputs(res, 1, ft_putchar_tputs);
	tcsetattr(0, TCSANOW, &g_term_init);
}

void	ft_quit_ok(void)
{
	SET_WHITE;
	ft_free_hist();
	ft_restore_term();
	exit(0);
}
