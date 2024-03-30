void send_to_server(char c, int pid)
{
    
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
    int i=0;
   int pid;
   pid = ft_atoi(av[1]);
   while(av[2][i])
   {
    send_to_server(av[2][i]);
    i++;
   }
}