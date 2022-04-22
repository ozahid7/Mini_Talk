#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
		usleep(100);
	}
}

int main (int ac, char *av[])
{
	int i;
	i = 0;
	int pid;
	pid = atoi(av[1]);
	if (ac < 3)
		return (0);
	while(av[2][i])
		ft_get_bits(av[2][i++], pid);
}