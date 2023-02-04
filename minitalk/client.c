/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:35:58 by mahender          #+#    #+#             */
/*   Updated: 2023/02/04 12:36:41 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"

static void	action(int sig)
{
	static int	ok = 0;

	if (sig == SIGUSR1)
		ok++;
	else
	{
		ft_putstr_fd("Signals well received: ", 1);
		ft_putnbr_fd(ok, 1);
		ft_putstr_fd("String sent. Client ends.", 1);
		exit(0);
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
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	char				*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = malloc(sizeof(char) * ft_strlen(argv[2]) + 1);
		if (!str)
			return (-1);
		ft_strlcpy(str, argv[2], (ft_strlen(argv[2]) + 1));
		signal(SIGUSR1, action);
		signal(SIGUSR2, action);
		sendsig(pid, str);
		while (1)
			pause();
		return (0);
	}
	else
		ft_putstr_fd("Wrong number of arguments", 1);
	return (0);
}
