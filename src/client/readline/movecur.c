/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:src/client/readline/movecur.c
/*   Created: 2015/08/21 15:13:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 14:43:26 by ggilaber         ###   ########.fr       */
=======
/*   Created: 2014/11/07 03:29:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/11 19:09:26 by ggilaber         ###   ########.fr       */
>>>>>>> 992ced860c730542c8863ea01b59b00ed5ffcfe7:src/lib/ft_memset.c
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_go_downleft(void)
{
	char	*area;
	char	b[40];

<<<<<<< HEAD:src/client/readline/movecur.c
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
=======
	if (!b)
		return (NULL);
	i = 0;
	l = -1;
	while (++i < 8)
		l += c << (8 * i);
	while (i < len / 8)
	{
		*((long unsigned int*)b + i) = l;
		i += 8;
	}
	while (i < len)
	{
		((char*)b)[i] = c;
		++i;
	}
	return (b);
>>>>>>> 992ced860c730542c8863ea01b59b00ed5ffcfe7:src/lib/ft_memset.c
}
