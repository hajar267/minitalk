/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:23:07 by hfiqar            #+#    #+#             */
/*   Updated: 2024/04/04 01:56:59 by hfiqar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
void send_to_server(unsigned char c, int pid)
{
    int i=7;
    unsigned char bit;
    while(i >= 0)
    {
        if((bit = c >> i) & 1)
            kill(SIGUSR2, pid);
        else
            kill(SIGUSR1, pid);
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
        somme = somme * 10 + str[i] - '0';
    return(signe * somme);
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
    int i=0;
    int pid;
    pid = ft_atoi(av[1]);
    while(av[2][i])
    {
        send_to_server(av[2][i], pid);
        i++;
    }
   }
}
