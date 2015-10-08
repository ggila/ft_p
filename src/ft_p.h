/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/07 18:09:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/10/08 22:49:09 by ggilaber         ###   ########.fr       */
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

//serveur
int		serverinit(int port);
void	serverloop(int socket);

//client
int		clientinit(char *addr, int port);

//lib
void	ft_putstr_fd(const char *str, int fd);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_atoi(char *str);

#endif
