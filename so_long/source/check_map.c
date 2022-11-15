/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:17:02 by mahender          #+#    #+#             */
/*   Updated: 2022/10/25 19:17:07 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_map(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == 'P')
				p_pos(game, y, x);
			counter(game, game->map[y][x]);
			x++;
		}
		y++;
	}
	game->ac_collect = game->c_collect;
	check_wall(game);
	if (game->c_collect < 1 || game->c_exit != 1 || game->c_player != 1)
	{
		free_exit(game);
		print_err("Error.\nPlayer, exit or collectable couldn't be found.");
	}
	return (0);
}

void	p_pos(t_data *game, int y, int x)
{
	game->player.pos_y = y;
	game->player.pos_x = x;
}

void	counter(t_data *game, char c)
{
	if (c == 'P')
		game->c_player ++;
	else if (c == 'E')
		game->c_exit ++;
	else if (c == 'C')
		game->c_collect ++;
	else if (c != '0' && c != '1')
	{
		free_exit(game);
		print_err("Error.\nInvalid character on the map.");
	}
}

int	check_wall(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if ((y == 0 && game->map[y][x] != '1') || (y == game->h - 1
			&& game->map[y][x] != '1') || (x == 0 && game->map[y][x] != '1')
			|| (x == game->w - 1 && game->map[y][x] != '1'))
			{
				free_exit(game);
				print_err("Error.\nThe wall is damaged.");
			}
			else
				x++;
		}
		y++;
	}
	return (0);
}
