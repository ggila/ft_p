/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fleche.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 09:35:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/22 12:03:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	ft_extreme_case(char c)
{
	if (g_disp.pos == 0 && c == LEFT)
	{
		g_disp.pos = g_disp.size - 1;
		g_disp.cur_line -= 1;
		ft_go_upright();
	}
	else if (g_disp.pos == g_disp.size - 1 && c == RIGHT)
	{
		g_disp.pos = 0;
		g_disp.cur_line += 1;
		ft_go_downleft();
	}
}

void		ft_fleche(char c, int *cur, char *line)
{
	char	*res;
	char	*area;
	char	b[40];

	if ((c == LEFT && *cur != 0) || (c == RIGHT && *cur != ft_strlen(line)))
	{
		*cur += c == LEFT ? -1 : 1;
		if ((g_disp.pos == 0 && c == LEFT)
				|| (g_disp.pos == g_disp.size - 1 && c == RIGHT))
			ft_extreme_case(c);
		else
		{
			area = b;
			g_disp.pos += c == LEFT ? -1 : 1;
			res = tgetstr(c == LEFT ? "le" : "nd", &area);
			tputs(res, 1, ft_putchar_tputs);
		}
	}
}

static void	ft_del_current(int *cur)
{
	char	*area;
	char	b[40];

	area = b;
	while (g_disp.cur_line != g_disp.nb_line)
	{
		tputs(tgetstr("do", &area), 1, ft_putchar_tputs);
		g_disp.cur_line += 1;
	}
	while (g_disp.cur_line != 1)
	{
		tputs(tgetstr("dl", &area), 1, ft_putchar_tputs);
		tputs(tgetstr("up", &area), 1, ft_putchar_tputs);
		g_disp.cur_line -= 1;
	}
	tputs(tgetstr("dl", &area), 1, ft_putchar_tputs);
	tputs(tgetstr("cr", &area), 1, ft_putchar_tputs);
	ft_putstr("     --------> ");
	ft_edit_init(cur);
}

void		ft_hist(char c, int *cur, char *line)
{
	int	i;

	if ((c == UP && g_hist->p) || (c == DOWN && g_hist->n))
	{
		ft_del_current(cur);
		ft_lineclr(line);
		g_hist = c == UP ? g_hist->p : g_hist->n;
		if (g_hist->line)
		{
			i = 0;
			while ((g_hist->line)[i])
			{
				ft_insert(line, (g_hist->line)[i], cur);
				ft_screen_insert((g_hist->line)[i], line);
				i++;
			}
		}
	}
}
