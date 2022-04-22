#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void   handler_su(int nb, siginfo_t *info, void *vod)
{
	static int i = 7;
	static char r = 0;
	
	
	if (nb == SIGUSR1)
        r = (r | (1 << i));
    if (i == 0)
    {
        write(1, &r, 1);
        i = 8;
        r = 0;
    }
    i--;
}

int main ()
{
    struct sigaction sa;
	int pid;
	sa.sa_sigaction = &handler_su;
	sa.sa_flags = SA_RESTART;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	printf("%d\n", pid);
	while(1);
}