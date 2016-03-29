/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discuss.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 20:59:38 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/29 15:30:14 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"
#include "ft_printf.h"

static void	init(char netpwd[250], void (*local[3])(char**)
		, void (*network[6])())
{
	ft_bzero(netpwd, 250);
	netpwd[0] = '/';
	local[0] = local_cd;
	local[1] = local_pwd;
	local[2] = local_ls;
	network[0] = network_quit;
	network[1] = network_pwd;
	network[2] = network_ls;
	network[3] = network_cd;
//	network[4] = network_get;
//	network[5] = network_put;
}

void	ft_prompt(char *netpwd)
{
	char	buf[1000];

	SET_BLACK;
	ft_printf(" \\------> loc: ");
	SET_BLUE;
	getcwd(buf, 1000);
	ft_printf("%s\n", buf);
	SET_BLACK;
	ft_printf("   \\----> net: ");
	SET_YELLOW;
	ft_printf("%s\n", netpwd);
	SET_BLACK;
	ft_printf("     \\-------> ");
}

static char	**get_client_request(char netpwd[250])
{
	char	line[250];
	char	**request;
	int		r;

	ft_prompt(netpwd);
	SET_BLACK;
	if ((r = read(0, line, 250)) == -1)
	{
		ft_printf("read() failed\n");
		exit(KO);
	}
	line[r - 1] = 0;
	SET_WHITE;
	request = ft_strsplit(line, ' ');
	return (request);
}

void		discuss(int sock)
{
	char	**request;
	char	netpwd[250];
	int		index;
	void	(*local[3])(char**);
	void	(*network[6])();

	init(netpwd, local, network);
	while (1)
	{
		request = get_client_request(netpwd);
		if ((index = is_local_cmd(request[0])) != KO)
		{
			SET_YELLOW;
			ft_printf("local\n");
			SET_WHITE;
			local[index](request);
		}
		else if ((index = is_network_cmd(request[0])) != KO)
			network[index](sock, netpwd, request);
		else
			ft_printf("unkown command\n");
		free(request);
		ft_printf("\n");
	}
}
