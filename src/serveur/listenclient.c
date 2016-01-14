/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenclient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 15:58:37 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/13 18:30:31 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	net_cd(int sock, char *buf)
{
	int	i;

	if (checkpath(request, buf, sock) == OK)
	{
		i = 0;
		while (g_client[i].sock != sock)
			i++;
		g_client[i].netpwd[0] = 0;
		ft_strcat(g_client[i].netpwd, buf);
		send_client(sock, buf, OK);
	}
	else
		send_client(sock, "dir does not exist", KO);
}

static char	checkpath(char **request, char buf[350], int sock)
{
	char		cwd[100];
	struct stat	buf_stat;

	buf[0] = '\0';
	ft_strcat(buf, getcwd(cwd, 100));
	ft_strcat(buf, "/basedir/");
	if (request[1] == NULL)
		return (OK);
	ft_strcat(buf, request + 3);
	if ((stat(buf, &buf_stat) == -1)
			|| (!S_ISDIR(buf_stat.st_mode)))
		return (KO);
	return (OK);
}

static void	net_pwd(int sock)
{
	int	i;

	i = 0;
	while (g_client[i].sock != sock)
		i++;
	send_client(sock, g_client[i].netpwd, OK);
}

static void	net_ls(char **request, int sock)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) == -1)
	{
		ft_putstr("execve");
		send_client(sock, "fork() failed", KO);
	}
	if (pid == 0)
	{
		dup2(sock, 1);
		ft_putchar_fd(OK, sock);
		execve("/bin/ls", ft_strsplit(request, ' '), NULL);
		send_client(sock, "execve() failed", KO);
	}
	else if (waitpid(pid, &status, 0) == -1)
		send_client(sock, "waitpid() failed", KO);
}

static void	handle_request(char **request, int sock, fd_set *all)
{
	char	buf[350];

	if (ft_strequ(request[0], "quit"))
		dropclient(sock, all);
	else if (ft_strequ(request[0], "pwd"))
		net_pwd(sock);
	else if (ft_strequ(request[0], "cd"))
		net_cd(request, sock, buf);
	else if (ft_strnequ(request[0], "ls"))
		net_ls(request, sock, buf);
//	else if (ft_strequ(request[0], "get"))
//		send_file(request, sock, buf);
//	else if (ft_strequ(request[0], "put"))
//		write_file(request, sock, buf);
}

void		listenclient(int sock, fd_set *all)
{
	char	**request;
	char	buf[250];
	int		r;

	if ((r = read(sock, buf, 250)) == -1)
	{
		ft_putendl("read() failed()");
		exit(0);
	}
	buf[r] = 0;
	request = ft_strsplit(buf);
	handle_request(request, sock, all);
	free(request);
}
