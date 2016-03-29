/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:09:19 by ggilaber          #+#    #+#             */
/*   Updated: 2016/03/29 15:20:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <term.h>
# include <signal.h>

# define OK 0
# define KO -1

# define LCD 0
# define LPWD 1
# define LLS 2

# define QUIT 0
# define PWD 1
# define LS 2
# define CD 3
# define GET 4
# define PUT 5

# define SET_BLACK ft_printf("\033[1;30m")
# define SET_WHITE ft_printf("\033[1;37m")
# define SET_BLUE ft_printf("\033[1;34m")
# define SET_YELLOW ft_printf("\033[1;33m")
# define SET_RED ft_printf("\033[1;31m")

# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68

# define PROMPT_SIZE 15

# define NB_CONNEX 10

# define MASK 1U
# define MASK_ENV_I MASK<<0

typedef struct	s_client
{
	int			sock;
	char		netpwd[200];
}				t_client;

typedef struct	s_screen
{
	int				size;
	int				cur_line;
	int				nb_line;
	int				cur_lines;
	int				nb_lines;
	int				pos;
}				t_screen;

typedef struct	s_hll
{
	struct s_hll	*p;
	struct s_hll	*n;
	char			*line;
}				t_hll;

t_client		g_client[NB_CONNEX + 2];

//serveur
void	quit(char *str);
int		serverinit(int port);
void	serverloop(int socket);
void	listenclient(int sock, fd_set *all);
void	printclient(void);
void	dropclient(int sock, fd_set *all);
char	is_network_cmd(char *prog);

//client
int		clientinit(char *addr, int port);
void	discuss(int sock);
void	handlecmd(char *str);
void	send_client(int sock, char *str, char success);
char	is_local_cmd(char *prog);

void	local_ls(char **request);
void	local_cd(char **request);
void	local_pwd(char **request);

//void	network_quit(char **request, char *netcwd, int sock);
//void	network_pwd(char **request, char *netcwd, int sock);
//void	network_ls(char **request, char *netcwd, int sock);
//void	network_cd(char **request, char *netcwd, int sock);

void	network_quit(int sock);
void	network_pwd(int sock, char *netpwd);
void	network_cd(int sock, char *netpwd, char **request);
void	network_ls(int sock, char *netcwd, char **request);

//void	network_(char **request, char *netcwd, int sock)
//void	network_(char **request, char *netcwd, int sock)

#endif
