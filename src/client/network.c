/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   network.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 09:30:24 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/14 11:57:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	network_quit(char **request, char *netcwd, int sock)
{
	(void)request;
	(void)netcwd;
	write(sock, "quit", 4);
	exit(0);
}

void	network_pwd(char **request, char *netcwd, int sock)
{
	char	buf[250];
	int		r;

	(void)request;
	(void)netcwd;
	write(sock, "pwd", 3);
	if (get_request_status(sock) == OK)
	{
		if ((r = read(sock, buf, 250)) == -1)
		{
			ft_putendl("read() failed()");
			exit(0);
		}
		write(1, buf, r);
	}
	ft_putendl("");
}


void	network_cd(char **request, char *netpwd, int sock)
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


void	network_ls(char **request, char *netcwd, int sock)
{
	char	buf[250];
	int		r;

	(void)request;
	(void)netcwd;
	buf[0] = 0;
	while (*request)
	{
		ft_strcat(buf, *request);
		ft_strcat(buf, " ");
		(*request)++;
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
