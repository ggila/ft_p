/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:09:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/10 23:52:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

# define OK 0
# define KO -1

# define NB_CONNEX 10

typedef struct	s_client
{
	int			sock;
	char		buf[250];
}				t_client;

t_client		g_client[NB_CONNEX + 1];
int				g_max;

//serveur
void	quit(char *str);
int		serverinit(int port);
void	serverloop(int socket);
void	printclient(void);

//client
int		clientinit(char *addr, int port);

//lib
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putchar(char c);
void	ft_putchar_fd(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);
void	ft_memset(void *b, char c, size_t len);

#endif
