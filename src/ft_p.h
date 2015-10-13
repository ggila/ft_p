/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:09:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/13 11:40:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <term.h>

# define OK 0
# define KO -1

# define SET_BLACK ft_putstr("\033[1;30m")
# define SET_BLUE ft_putstr("\033[1;34m")
# define SET_WHITE ft_putstr("\033[1;37m")

# define UP 65
# define DOWN 66
# define RIGHT 67
# define LEFT 68

# define PROMPT_SIZE 15

# define NB_CONNEX 3

# define MASK 1U
# define MASK_ENV_I MASK<<0

typedef struct	s_client
{
	int			sock;
	char		buf[250];
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


char			g_flag;
struct termios	g_term;
struct termios	g_term_init;
t_hll			*g_hist;
t_screen		g_disp;



t_client		g_client[NB_CONNEX + 2];
int				g_max;

//serveur
void	quit(char *str);
int		serverinit(int port);
void	serverloop(int socket);
void	listenclient(int sock, fd_set *all);
void	printclient(void);
void	dropclient(int sock, fd_set *all);

//client
int		clientinit(char *addr, int port);
void	discuss(int sock);
void	handlecmd(char *str);



//readline
//main
int		ft_putchar_tputs(int c);
void	ft_tabcpy(char *line, char temp[], int cur);
void	ft_prompt(void);
void	ft_edit_init(int *cur);
void	ft_lineclr(char *line);
void	ft_init_term(void);
void	ft_init_hist(void);
void	ft_init_screen(void);
void	ft_init(void);
//ft_get_cmd.c
void			ft_get_cmd(char line[]);
//key_map.c
int		ft_is_map(char c);
void	ft_map(char *buf, int *cur, char *line);
//hist.c
void	ft_save_hist(char *line);
void	ft_free_hist(void);
//flech.c
void	ft_fleche(char c, int *cur, char *line);
void	ft_hist(char c, int *cur, char *line);
//line_del
void	ft_del(int cur, char *line);
void	ft_del_pre(int *cur, char *line);
//line_insert
void	ft_insert(char *line, char c, int *cur);
//screen_insert
void	ft_screen_insert(char c, char *line);
//update_pos.c
void	ft_update_screen_insert_pos(int len);
//move_cur.c
void	ft_go_upright(void);
void	ft_go_downleft(void);
//quit.c
void	ft_error(char *str);
void	ft_quit_ok(void);
void	ft_restore_term(void);

#endif
