/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 03:40:27 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/22 04:15:47 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_mssg(int sig)
{
	if (sig == SIGUSR2)
		write(1, "sf rah lmssg wssel (^--^)\n", 26);
}

void	send_to_server(unsigned char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(900);
		i--;
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		signe = signe * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		somme = somme * 10 + str[i++] - '0';
	return (signe * somme);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	signal(SIGUSR2, print_mssg);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			exit(EXIT_FAILURE);
		i = 0;
		while (av[2][i])
		{
			send_to_server(av[2][i], pid);
			i++;
		}
		send_to_server('\0', pid);
	}
	else
		write(2, "veuillez entrer one arg\n", 24);
}
