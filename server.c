/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:21:58 by ozahid-           #+#    #+#             */
/*   Updated: 2022/04/23 22:34:43 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long long int	n;

	n = nb;
	if (n >= 0 && n <= 9)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	handler_su(int nb, siginfo_t *info, void *vod)
{
	static int	i = 7;
	static char	r = 0;
	static int	pid = -1;
	
	(void)vod;
	if (pid != info->si_pid && info->si_pid != 0)
	{
		r = 0;
		i = 7;
		pid = info->si_pid;
	}
	if (nb == SIGUSR1)
		r = (r | (1 << i));
	if (i == 0)
	{
		ft_putchar(r);
		i = 8;
		r = 0;
	}
	i--;
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handler_su;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "pid = ", 6);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
