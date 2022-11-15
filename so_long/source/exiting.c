/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:10:22 by mahender          #+#    #+#             */
/*   Updated: 2022/10/25 20:10:25 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_err(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

void	free_exit(t_data *game)
{
	int	i;

	i = 0;
	while (i <= game->h)
	{
		free(game->map[i]);
		i++;
	}
}

void	exit_door(t_data *game)
{
	if (game->ac_collect == 0)
	{
		ft_printf("Congrats! You´ve done it in %d steps!\n", game->c_steps);
		close_exit(game);
	}
	else
		ft_printf("%d items left to collect.\n", game->ac_collect);
}

void	close_exit(t_data *game)
{
	mlx_terminate(game->mlx);
	free_exit(game);
	exit(EXIT_SUCCESS);
}
