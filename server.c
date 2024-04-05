/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:41:52 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/04 22:49:50 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_print_string(int sig)
{
   static int i = 7;
   static int bit = 0;

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
      signal(SIGUSR2, ft_print_string);
      signal(SIGUSR1, ft_print_string);
    while (1)
      pause();
}
