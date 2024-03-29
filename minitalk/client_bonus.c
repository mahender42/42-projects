/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:26:22 by mahender          #+#    #+#             */
/*   Updated: 2023/02/17 14:26:24 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

static void	resp_act(int sig)
{
	static int	ok = 0;

	if (sig == SIGUSR1)
		++ok;
	else if (sig == SIGUSR2)
	{
		ft_putstr_fd("\033[0;34mSignals well received: ", 1);
		ft_putnbr_fd(ok, 1);
		ft_putstr_fd("\nString sent. Client ends.\033[0m", 1);
		exit(0);
	}
}

void	send_null(int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if ('\0' & (1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j--;
	}
}

void	sendsig(int pid, char *str)
{
	int		j;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		j = 7;
		while (j >= 0)
		{
			if (str[i] & (1 << j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			j--;
		}
		i++;
	}
	send_null(pid);
}

int	main(int argc, char **argv)
{
	int					pid;
	char				*str;

	if (argc == 3)
	{
		signal(SIGUSR1, resp_act);
		signal(SIGUSR2, resp_act);
		pid = ft_atoi(argv[1]);
		str = malloc(sizeof(char) * ft_strlen(argv[2]) + 1);
		if (!str)
			return (-1);
		ft_strlcpy(str, argv[2], (ft_strlen(argv[2]) + 1));
		sendsig(pid, str);
		while (1)
			pause();
		free(str);
	}
	else
	{
		ft_putstr_fd("Wrong number of arguments\n", 1);
		ft_putstr_fd("Try: ./client [PID] [STRING]", 1);
	}
	return (0);
}
