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

static void	action(int sig)
{
	
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
		ft_strlcpy(str, argv[2], ft_strlen(argv[2]));
		//kill(pid, SIGUSR1);
		//ft_printf("%s", str);
		//ft_putnbr_fd(pid, 1);
		//kill(pid, SIGKILL);
		signal(SIGUSR2, &action);
		//signal(SIGUSR2, &action);
	}
	else
		ft_putstr_fd("Wrong umber of arguments", 1);
}
