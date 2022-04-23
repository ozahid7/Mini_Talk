/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahid- <ozahid-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:48:13 by ozahid-           #+#    #+#             */
/*   Updated: 2022/04/23 22:29:25 by ozahid-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <string.h>

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

void	ft_get_bits(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c & (1 << i)) >> i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep (800);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	i = 0;
	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	if(pid == 0)
		return(1);
	if(pid == 0)
		return(1);
	while (i <= ft_strlen(av[2]))
		ft_get_bits(av[2][i++], pid);
}
