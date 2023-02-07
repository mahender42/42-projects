/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:55:52 by angalsty          #+#    #+#             */
/*   Updated: 2022/12/13 19:43:11 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_signal(int signal, siginfo_t *siginfo, void *unused)
{
	static char	c;
	static int	bit;

	(void)unused;
	(void)siginfo;
	if (signal == SIGUSR1)
		c |= 0x01 << bit;
	bit++;
	if (bit == 8)
	{
		bit = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill (siginfo->si_pid, SIGUSR1);
			return ;
		}
		write(1, &c, 1);
		c = 0;
	}
	kill (siginfo->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int					pid;

	(void)argv;
	pid = getpid();
	ft_printf("Server started successfully and now is waiting for client\n");
	ft_printf("PID is: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO | SA_RESTART | SA_NODEFER;
	sa.sa_sigaction = &handler_signal;
	if ((sigaction(SIGUSR1, &sa, 0)) == -1)
		ft_printf("Error sigaction\n");
	if ((sigaction(SIGUSR2, &sa, 0)) == -1)
		ft_printf("Error sigaction\n");
	while (argc == 1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
		usleep(200);
	}
	return (0);
}
