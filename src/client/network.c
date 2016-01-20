/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:30:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/20 18:17:48 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char			is_network_cmd(char *prog)
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
	return (KO);
}

static ssize_t	read_sock(int sock, char *buf, size_t n)
{
	ssize_t	r;

	if ((r = read(sock, buf, n)) == -1)
	{
		ft_putstr("read() failed()");
		exit(0);
	}
	return r;
}

static char	get_request_status(int sock)
{
	char	buf[200];
	int		r;

	r = read_sock(sock, buf, 1);
	if (*buf == OK)
	{
		SET_BLUE;
		ft_putstr("OK\n");
		SET_WHITE;
		return (OK);
	}
	else
	{
		SET_RED;
		ft_putstr("KO: ");
		r = read_sock(sock, buf, 200);
		buf[r] = 0;
		write(1, buf, r);
		return (KO);
	}
}

void	network_quit(int sock)
{
	write(sock, "quit", 4);
	exit(0);
}

void	network_pwd(int sock, char *netpwd)
{
	(void)sock;

	SET_BLUE;
	ft_putstr("OK\n");
	SET_WHITE;
	ft_putendl(netpwd);
}

void	network_cd(int sock, char *netpwd, char **request)
{
	char	buf[250];

	buf[0] = 0;
	ft_strcat(buf, "cd ");
	ft_strcat(buf, (request[1] == NULL) ? "/" : request[1]);
	write(sock, buf, ft_strlen(buf));
	if (get_request_status(sock) == OK)
	{
		netpwd[0] = 0;
		ft_strcat(netpwd, request[1]);
	}
}

void	network_ls(int sock, char *netcwd, char **request)
{
	char	buf[250];
	int		r;

	(void)netcwd;
	buf[0] = 0;
	while (*request)
	{
		ft_strcat(buf, *request);
		ft_strcat(buf, " ");
		request++;
	}
	write(sock, buf, ft_strlen(buf));
	if (get_request_status(sock) == OK)
	{
		while ((r = read(sock, buf, 249)))
		{
			buf[r] = 0;
			write(1, buf, ft_strlen(buf));
		}
	}
}

//void	network_(char **request, char *netcwd, int sock)
//void	network_(char **request, char *netcwd, int sock)
