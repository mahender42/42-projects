/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:39:06 by mahender          #+#    #+#             */
/*   Updated: 2023/02/01 15:39:10 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include <signal.h>

static void	action(int sig, siginfo_t *info, void *context)
{
	static unsigned char	chr = 0;
	static int		i = 0;
	
	if (sig == SIGUSR1)
		chr |= 1;  //ft_printf("1");
	else if (sig == SIGUSR2)
		chr |= 0;  //ft_printf("0");

	if (++i == 8)
	{
		ft_putchar_fd(chr, 1);
		i = 0;
		chr = 0;
	}
	else
		chr <<= 1;
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	write (1, "\n", 1);
	sa.sa_sigaction = action;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
