/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenclient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 15:58:37 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/13 17:34:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	netcd(int sock, char *buf)
{
	int	i;

	i = 0;
	while (g_client[i].sock != sock)
		i++;
	g_client[i].netpwd[0] = 0;
	ft_strcat(g_client[i].netpwd, buf);
	send_client(sock, buf, OK);
}

static char	checkpath(char request[250], char buf[350], int sock)
{
	char		cwd[100];
	struct stat	buf_stat;

	buf[0] = '\0';
	ft_strcat(buf, getcwd(cwd, 100));
	ft_strcat(buf, "/basedir/");
	ft_strcat(buf, request);
	if ((stat(buf, &buf_stat) == -1)
			|| (!S_ISDIR(buf_stat.st_mode)))
	{
		send_client(sock, "dir does not exist", KO);
		return (KO);
	}
	return (OK);
}

static void	sendpwd(int sock)
{
	int	i;

	i = 0;
	while (g_client[i].sock != sock)
		i++;
	send_client(sock, g_client[i].netpwd, OK);
}

static void	handle_request(char request[250], int sock, fd_set *all)
{
	pid_t	pid;
	int		status;
	char	buf[350];

	if (ft_strequ(request, "exit"))
		dropclient(sock, all);
	else if (ft_strequ(request, "pwd"))
		sendpwd(sock);
	else if (ft_strnequ(request, "cd ", 3))
	{
		if (checkpath(request + 3, buf, sock) == OK)
			netcd(sock, buf);
	}
	else if (ft_strnequ(request, "ls", 2))
	{
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
}

void		listenclient(int sock, fd_set *all)
{
	char	b[250];
	int r;

	if ((r = read(sock, b, 250)) == -1)
	{
		ft_putendl("read() failed()");
		exit(0);
	}
	b[r] = 0;
	handle_request(b, sock, all);
	ft_putstr("\n");
}
