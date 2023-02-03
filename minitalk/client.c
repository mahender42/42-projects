/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:35:58 by mahender          #+#    #+#             */
/*   Updated: 2023/01/30 18:36:03 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	action(int pid)
{
	ft_printf("Termino cliente");
	exit(0);
}

void sendsig(int pid, char c)
{
    char	binario[8];
	int		j;
	
	j = 7;
	while (j >= 0)
	{
		if (c & (1 << j))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		j--;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;
	char				*str;
	int					i;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = malloc(sizeof(char) * ft_strlen(argv[2]) + 1);
		if (!str)
			return (-1);
		ft_strlcpy(str, argv[2], (ft_strlen(argv[2]) + 1));
		i = 0;
		while (i < ft_strlen(argv[2]))
		{
			sendsig(pid, str[i]);
			i++;
		}
		signal(SIGUSR1, &action);
		signal(SIGUSR2, &action);
		//while (1)
		//	pause();
		return (0);
	}
	else
		ft_putstr_fd("Wrong number of arguments", 1);
	return(0);
}
