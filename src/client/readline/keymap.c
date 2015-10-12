/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:56:16 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 17:54:01 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void	ft_move(int n, int *cur, char *line)
{
	int	end;

	end = (n == 1) ? 0 : ft_strlen(line);
	while (*cur != end)
		ft_fleche(n == 1 ? LEFT : RIGHT, cur, line);
}

int			ft_is_map(char c)
{
	if (c == 27)
		return (1);
	if (c == 4)
		return (1);
	if (c == 10)
		return (1);
	if (c == 126 && c == 91)
		return (1);
	if (c == 127)
		return (1);
	if (c == 9)
		return (1);
	if (c == 1)
		return (1);
	if (c == 2)
		return (1);
	return (0);
}

void		ft_map(char *buf, int *cur, char *line)
{
//	if (buf[0] == 9 && !(g_flag & MASK_ENV_I)
//			&& (*cur == ft_strlen(line) || line[*cur] == ' '))
//		ft_tab(buf, cur, line);
	if (buf[0] == 4)
	{
		ft_putendl("\n");
		ft_quit_ok();
		exit(0);
	}
	else if (buf[0] == 10)
		ft_save_hist(line);
	else if (buf[0] == 27 && buf[2] % 5 > 1)
		ft_fleche(buf[2], cur, line);
	else if (buf[0] == 27 && !(g_flag & MASK_ENV_I))
		ft_hist(buf[2], cur, line);
	else if (buf[0] == 126 && buf[1] == 91)
		ft_del(*cur, line);
	else if (buf[0] == 127)
		ft_del_pre(cur, line);
	else if (buf[0] == 1)
		ft_move(buf[0], cur, line);
}
