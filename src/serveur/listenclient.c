/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenclient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 15:58:37 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/12 19:23:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	handle_request(char request[250], int sock)
{
	pid_t	pid;

	if (ft_strequ(b, "exit"))
		dropclient(sock, all);
	else if (ft_strequ(b. "ls"))
	{
		if ((pid = fork()) == -1)
			send_client(sock, "fork() failed", ERROR);
		if (pid == 0)
			ls;
		else if (waitpid(pid, &status, 0) == -1)
			send_client(sock, "fork() failed", ERROR);
	}
		

}

void	listenclient(int sock, fd_set *all)
{
	char	b[250];
	int r;

	(void)all;
	r=read(sock, b, 250);
	b[r] = 0;
	ft_putstr(b);
	handle_request(b, sock);
	ft_putstr("\n");
}
