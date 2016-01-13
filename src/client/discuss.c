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

static void	handle_network(char )
{
	ft_putstr_fd(request, sock);
	listenserver(netpwd, request, sock);
}

static char	is_network_cmd(char *prog)
{
	if (ft_strequ(prog, "quit"))
		return (QUIT);
	else if (ft_strequ(prog, "pwd"))
		return (PWD);
	else if (ft_strequ(prog, "ls"))
		return (LS);
	else if (ft_strequ(prog, "cd"))
		return (CD);
	else if (ft_strequ(prog, "get"))
		return (GET);
	else if (ft_strequ(prog, "put"))
		return (PUT);
	return (0);
}

static char	is_local_cmd(char *prog)
{
	if (ft_strequ(prog, "lcd"))
		return (LCD);
	else if (ft_strequ(prog, "lpwd"))
		return (LPWD);
	else if (ft_strequ(prog, "lls"))
		return (LLS);
	return (KO);
}

static char	**get_client_request(char netpwd[250])
{
	char	line[250];
	char	*l;
	char	**request;

	ft_prompt(netpwd);
	SET_BLACK;
	ft_get_cmd(line);
	SET_WHITE;
	l = ft_strtrim(line);
	request = ft_strsplit(l, ' ');
	free(request);
	return (request);
}

void		discuss(int sock)
{
	char	**request;
	char	netpwd[250];
	int		index;

	ft_init(netpwd);
	while (1)
	{
		request = get_client_request();
		if ((index = is_local_cmd(request[0])))
			local[index](request);
		else if ((index = is_network_cmd(request[0])))
			network[index](sock, request);
		free(request);
	}
}
