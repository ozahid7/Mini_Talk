#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handle_srv(int nb)
{
	if(nb == SIGUSR1)
		write(1,"wa5a", 4);
}

void    ft_get_bits(char c, int pid)
{
	int i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) >> i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(800);
	}
}

int main (int ac, char *av[])
{
	int i;
	int pid;
	
	i = 0;
	pid = atoi(av[1]);
	signal(SIGUSR1, &handle_srv);		
	if (ac != 3)
		return (0);
	while(i <= strlen(av[2]))
		ft_get_bits(av[2][i++], pid);
	//ft_get_bits(0, pid);
}