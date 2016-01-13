/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlecmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 18:23:07 by ggilaber          #+#    #+#             */
/*   Updated: 2016/01/13 11:15:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void	localls(char **tab_cmd)
{
	int	pid;
	int status;

	if ((pid = fork()) == -1)
		ft_putstr("fork() failed");
	if (pid == 0)
	{
		execve("/bin/ls", tab_cmd, NULL);
		ft_putstr("execve() failed");
	}
	else if (waitpid(pid, &status, 0) == -1)
		ft_putstr("waitpid() failed");
}

static void	localcmd(char *cmd)
{
	char buf[200];
	char **tab_cmd;

	tab_cmd = ft_strsplit(cmd, ' ');
	SET_BLUE;
	ft_putstr("local\n");
	SET_WHITE;
	if (ft_strequ(cmd, "pwd"))
		ft_putendl(getcwd(buf, 200));
	else if (ft_strnequ(cmd, "cd", 2))
		chdir(tab_cmd[1]);
	else if (ft_strnequ(cmd, "ls", 2))
		localls(tab_cmd);
	free(tab_cmd);
}

void		handlecmd(char *cmd)
{
	if (ft_strequ(cmd, "exit"))
		ft_quit_ok();
	else if (cmd[0] == 'l')
		localcmd(++cmd);
}
