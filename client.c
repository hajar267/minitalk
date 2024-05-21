/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:23:07 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/21 22:11:19 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_to_server(unsigned char c, int pid)
{
	int i;

	i = 7;
	while(i >= 0)
	{
		if((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		
		usleep(900);
		i--;
	}
}

int ft_atoi(char *str)
{
	int i=0;
	int signe = 1;
	int somme=0;
	while(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if(str[i] == '-')
		signe=signe*-1;
	if(str[i] == '-' || str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
		somme = somme * 10 + str[i++] - '0';
	return(signe * somme);
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		int pid;
		int i;
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			exit(EXIT_FAILURE);
		i = 0;
		while(av[2][i])
		{
			send_to_server(av[2][i], pid);
			i++;
		}
		send_to_server('\0',pid);
   }
	else
		write(2,"veuillez entrer one arg\n", 24);
}
