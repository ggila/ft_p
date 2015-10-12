/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/21 14:13:13 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/12 18:03:07 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		ft_insert(char *line, char c, int *cur)
{
	char	temp[250];
	int		len;
	int		i;

	len = ft_strlen(line);
	ft_memclr(temp, len + 3);
	if (*cur == 248)
		ft_error("too long, fuck it");
	if (*cur != len)
	{
		ft_tabcpy(line, temp, *cur);
		line[*cur] = c;
		i = 0;
		while (temp[i])
		{
			line[*cur + i + 1] = temp[i];
			i++;
		}
		line[*cur + i + 1] = '\0';
	}
	else
		line[*cur] = c;
	*cur += 1;
}

void		ft_word_insert(char *line, char *word, int *cur)
{
	int i;

	i = 0;
	while (word[i])
	{
		ft_insert(line, word[i], cur);
		i++;
	}
}
