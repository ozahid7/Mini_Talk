/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:17:08 by ozahid-           #+#    #+#             */
/*   Updated: 2022/04/24 01:32:48 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long long int	i;
	size_t			s;
	long long int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == ' '
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r') && str[i])
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != 0)
		return (0);
	return (r * s);
}

void	handle_srv(int nb)
{
	if (nb == SIGUSR1)
		write(1, "Done", 4);
}

void	ft_get_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) >> i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				write(1, "error\n", 6);
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				write(1, "error\n", 6);
				exit(1);
			}
		}
		i--;
		usleep(800);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	if (ac != 3)
	{
		write(1, "invalid arguments\n", 18);
		return (1);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	if (pid == 0)
	{
		write(1, "invalid pid\n", 12);
		return (1);
	}
	signal(SIGUSR1, &handle_srv);
	while (i <= ft_strlen(av[2]))
		ft_get_bits(av[2][i++], pid);
}
