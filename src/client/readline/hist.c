/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/24 18:53:55 by ggilaber          #+#    #+#             */
/*   Updated: 2015/08/24 18:54:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	ft_save_hist(char *line)
{
	t_hll	*new;

	if (line[0])
	{
		while (g_hist->n)
			g_hist = g_hist->n;
		if (!(new = (t_hll*)malloc(sizeof(t_hll))))
			ft_error("error in malloc (ft_save_hist)");
		new->line = NULL;
		new->p = g_hist;
		new->n = NULL;
		if (!(g_hist->line = ft_strdup(line)))
			ft_error("error in malloc (ft_save_hist)");
		g_hist->n = new;
		g_hist = new;
	}
}

void	ft_free_hist(void)
{
	t_hll	*tmp;

	while (g_hist->n)
	{
		tmp = g_hist->n;
		free(g_hist->line);
		free(g_hist);
		g_hist = tmp;
	}
	free(g_hist->line);
	free(g_hist);
}
