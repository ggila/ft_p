/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discuss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 20:59:38 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/14 11:56:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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

static void	init_func(void (*local[3])(char**)
		, void (*network[6])(char**, char*, int))
{
	local[0] = local_cd;
	local[1] = local_pwd;
	local[2] = local_ls;
	network[0] = network_quit;
	network[1] = network_pwd;
	network[2] = network_ls;
	network[3] = network_cd;
//	network[4] = network_;
//	network[5] = network_;
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
	free(l);
	return (request);
}

void		discuss(int sock)
{
	char	**request;
	char	netpwd[250];
	int		index;
	void	(*local[3])(char**);
	void	(*network[6])(char**, char*, int);

	ft_init(netpwd);
	init_func(local, network);
	while (1)
	{
		request = get_client_request(netpwd);
		if ((index = is_local_cmd(request[0])) != KO)
		{
			SET_YELLOW;
			ft_putendl("local");
			SET_WHITE;
			local[index](request);
		}
		else if ((index = is_network_cmd(request[0])) != KO)
			network[index](request, netpwd, sock);
		free(request);
		ft_putendl("");
	}
}
