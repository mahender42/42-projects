/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:34:13 by mahender          #+#    #+#             */
/*   Updated: 2022/10/25 18:34:16 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_vars(t_data *game)
{
	game->c_exit = 0;
	game->c_player = 0;
	game->c_collect = 0;
	game->c_steps = 0;
	game->collected = 0;
	init_moves(game);
}

void	init_moves(t_data *game)
{
	game->move.mup.pos_x = 0;
	game->move.mup.pos_y = -1;
	game->move.mdown.pos_x = 0;
	game->move.mdown.pos_y = +1;
	game->move.mright.pos_x = +1;
	game->move.mright.pos_y = 0;
	game->move.mleft.pos_x = -1;
	game->move.mleft.pos_y = 0;
}

void	init_win(t_data *game)
{
	int	win_w;
	int	win_h;

	win_w = game->w * 64;
	win_h = game->h * 64;
	game->mlx = mlx_init(win_w, win_h, "So long", true);
	if (!game->mlx)
	{
		free_exit(game);
		print_err("Error.\nThe window couldn't be opened.");
	}
}
