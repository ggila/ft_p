/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 10:56:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 18:01:50 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"
static void		ft_get_cmd_init(int *cur, char buf[3], char line[])
{
	ft_edit_init(cur);
	ft_memclr(buf, 3);
	ft_memclr(line, 250);
}

static void		ft_go_down(void)
{
	char *area;
	char b[40];

	area = b;
	while (g_disp.cur_line != g_disp.nb_line)
	{
		tputs(tgetstr("do", &area), 1, ft_putchar_tputs);
		g_disp.cur_line += 1;
	}
}

void			ft_get_cmd(char line[])
{
	char	buf[3];
	int		cursor;

	ft_get_cmd_init(&cursor, buf, line);
	while (buf[0] != 10)
	{
		read(0, buf, 3);
		if (ft_is_map(buf[0]))
			ft_map(buf, &cursor, line);
		if (!ft_is_map(buf[0]))
		{
			ft_insert(line, buf[0], &cursor);
			g_flag & MASK_ENV_I ? ft_putchar(buf[0]) :
				ft_screen_insert(buf[0], line);
		}
	}
	ft_go_down();
	ft_putchar('\n');
}
