/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:09:19 by ggilaber          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2015/10/12 18:33:40 by ggilaber         ###   ########.fr       */
=======
/*   Updated: 2015/10/11 20:59:26 by ggilaber         ###   ########.fr       */
>>>>>>> 992ced860c730542c8863ea01b59b00ed5ffcfe7
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

# define NB_CONNEX 10

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



t_client		g_client[NB_CONNEX + 1];
int				g_max;

//serveur
void	quit(char *str);
int		serverinit(int port);
void	serverloop(int socket);
void	listenclient(int sock, fd_set *all);
void	printclient(void);

//client
int		clientinit(char *addr, int port);
void	discuss(int sock);
<<<<<<< HEAD
void	handlecmd(char *str);
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
=======

//lib
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_memset(void *b, char c, size_t len);
>>>>>>> 992ced860c730542c8863ea01b59b00ed5ffcfe7

#endif
