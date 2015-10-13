/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 15:13:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/13 11:24:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_go_downleft(void)
{
	char	*area;
	char	b[40];

	area = b;
	tputs(tgetstr("do", &area), 1, ft_putchar_tputs);
	tputs(tgetstr("cr", &area), 1, ft_putchar_tputs);
}

void	ft_go_upright(void)
{
	char	*res;
	char	*area;
	char	b[40];
	int		end;

	area = b;
	tputs(tgetstr("up", &area), 1, ft_putchar_tputs);
	tputs(tgetstr("cr", &area), 1, ft_putchar_tputs);
	end = g_disp.size - 1;
	res = tgetstr("nd", &area);
	while (end--)
		tputs(res, 1, ft_putchar_tputs);
}
