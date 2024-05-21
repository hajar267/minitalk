/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:41:52 by hfiqar            #+#    #+#             */
/*   Updated: 2024/05/21 12:32:53 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include<string.h>

void handler(int sig, siginfo_t *info, void *context)
{
   static int i = 7;
   static int bit = 0;
   static int client_pid = 0;

   if (client_pid != info->si_pid)
   {
      client_pid = info->si_pid;
      bit = 0;
      i = 7;
   }
   // int pid_client = info->si_pid;
   // printf("pid : %d\n", info->si_pid); // pid of the process sending 
   // printf("uid : %d\n", info->si_uid);
   if (sig == SIGUSR2)
      bit += 1 << i;
   else if (sig == SIGUSR1)
      bit += 0 << i;
   i--;
   if (i == -1)
   {
      write(1, &bit, 1);
      i = 7;
      bit = 0;
   }
}

int main()
{
   int pid = getpid();
   printf("%d\n", pid);
   struct sigaction sa;
   sa.sa_sigaction = handler;
   sa.sa_flags = SA_SIGINFO;
   sigemptyset(&sa.sa_mask);
   sigaction(SIGUSR2, &sa, NULL);
   sigaction(SIGUSR1, &sa, NULL);

   while (1) 
   {
      pause();
   }
   return 0;
}
