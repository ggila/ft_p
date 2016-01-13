/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discuss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 20:59:38 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/13 18:55:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	checkstatus(int sock)
{
	char	b;
	int		r;

	if ((r = read(sock, &b, 1)) == -1)
	{
		ft_putstr("read() failed()");
		exit(0);
	}
	if (b == OK)
	{
		SET_YELLOW;
		ft_putstr("OK\n");
		SET_WHITE;
	}
	else
	{
		SET_RED;
		ft_putstr("KO: ");
	}
}

static void	cdnet_client(char *b, char *netpwd)
{
	char buf[250];

	netpwd[0] = 0;
	ft_strcat(netpwd, ft_strstr(b, getcwd(buf, 250)));
}

static void	listenserver(char *netpwd, char *request, int sock)
{
	char	b[250];
	int		r;

	checkstatus(sock);
	if ((r = read(sock, b, 250)) == -1)
	{
		ft_putendl("read() failed()");
		exit(0);
	}
	b[r] = 0;
	if (ft_strnequ(request, "cd ", 3) || ft_strequ(request, "cd"))
		cdnet_client(b, netpwd);
	else
		ft_putstr(b);
	ft_putstr("\n");
	SET_WHITE;
}

static char	localcommand(char *cmd)
{
	if (ft_strequ(cmd, "exit"))
		return (OK);
	else if (ft_strnequ(cmd, "lcd ", 4) || ft_strequ(cmd, "lcd"))
		return (OK);
	else if (ft_strequ(cmd, "lpwd"))
		return (OK);
	else if (ft_strnequ(cmd, "lls ", 4) || ft_strequ(cmd, "lls"))
		return (OK);
	return (KO);
}

void		discuss(int sock)
{
	char	line[250];
	char	*request;
	char	netpwd[250];

	ft_init(netpwd);
	while (1)
	{
		SET_BLACK;
		ft_prompt(netpwd);
		ft_get_cmd(line);
		SET_WHITE;
		request = ft_strtrim(line);
		if (localcommand(request) == OK)
			handlecmd(request);
		else
		{
			ft_putstr_fd(request, sock);
			listenserver(netpwd, request, sock);
		}
		ft_putendl("");
		free(request);
	}
}
