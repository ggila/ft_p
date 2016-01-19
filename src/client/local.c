/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   local.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 08:18:41 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/19 16:36:17 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

char	is_local_cmd(char *prog)
{
	if (ft_strequ(prog, "lcd"))
		return (LCD);
	else if (ft_strequ(prog, "lpwd"))
		return (LPWD);
	else if (ft_strequ(prog, "lls"))
		return (LLS);
	return (KO);
}

void	local_ls(char **request)
{
	int	pid;
	int	status;

	if ((pid = fork()) == -1)
		ft_putstr("fork() failed");
	if (pid == 0)
	{
		execve("/bin/ls", request, NULL);
		ft_putstr("execve() failed");
	}
	else if (waitpid(pid, &status, 0) == -1)
		ft_putstr("waitpid() failed");
}

void	local_cd(char **request)
{
	if (request[1] == NULL)
		return;
	if (chdir(request[1]) == -1)
		ft_putendl("lcd failed, probably cause dir does not exist");
}

void	local_pwd(char **request)
{
	char	buf[200];

	(void)request;
	ft_putendl(getcwd(buf, 200));
}
