/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angalsty <angalsty@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:55:35 by angalsty          #+#    #+#             */
/*   Updated: 2022/12/14 14:32:23 by angalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_num;

//funcion para mandar mensaje en bits
void	sender_bits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		g_num = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_num == 0)
			usleep(1);
		bit++;
	}
}

int	ft_atoi(const char *str)
{
	long int	i;
	long int	pos;
	long int	res;

	i = 0;
	pos = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pos = -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			res = (res * 10) + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (res * pos);
}

void	handler(int signal)
{
	static int	bits = 0;

	if (signal == SIGUSR2)
	{
		bits++;
		g_num = 1;
	}
	else if (signal == SIGUSR1)
	{
		bits++;
		g_num = 1;
	}
}

//to put salto linea al final de funccion despues que mandas bits
int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc == 3)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			sender_bits(pid, argv[2][i]);
			i++;
		}
		sender_bits(pid, argv[2][i]);
	}
	else
	{
		ft_printf("Nesesita argumentos validos\n");
		return (-1);
	}
	return (0);
}
