/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:19:06 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/22 04:05:15 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	send_to_server(unsigned char c, int pid);
int		ft_atoi(char *str);
void	handler(int sig, siginfo_t *info, void *context);
void	write_nbr(int num);
void	print_mssg(int sig);

#endif