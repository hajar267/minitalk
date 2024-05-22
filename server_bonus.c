/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 03:40:31 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/22 03:42:41 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handler(int sig, siginfo_t *info, void *context)
{
	static int	i = 7;
	static int	bit = 0;
	static int	client_pid = 0;

	(void)context;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		i = 7;
		bit = 0;
	}
	if (sig == SIGUSR2)
		bit += 1 << i;
	else if (sig == SIGUSR1)
		bit += 0 << i;
	i--;
	if (i == -1)
	{
		write(1, &bit, 1);
		if (bit == '\0')
			kill(client_pid, SIGUSR2);
		i = 7;
		bit = 0;
	}
}

void	write_nbr(int num)
{
	if (num > 9)
		write_nbr(num / 10);
	num = num % 10 + '0';
	write(1, &num, 1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	write(1, "pid : ", 6);
	write_nbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
