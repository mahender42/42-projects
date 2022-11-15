/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:50:11 by mahender          #+#    #+#             */
/*   Updated: 2022/10/30 12:50:13 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*game;
	t_moves	*move;

	game = param;
	move = &game->move;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		moves(game, &move->mup);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		moves(game, &move->mdown);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		moves(game, &move->mright);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		moves(game, &move->mleft);
	else if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		close_exit(game);
}

static int	check_collision(t_data *game, t_pos *mov)
{
	int	x;
	int	y;

	y = game->player.pos_y + mov->pos_y;
	x = game->player.pos_x + mov->pos_x;
	if (game->map[y][x] == '1')
		return (0);
	return (1);
}

static void	coun_n_door(t_data *game)
{
	game->ac_collect--;
	if (game->ac_collect == 0)
	{
		game->eimg->instances[0].enabled = false;
		mlx_image_to_window(game->mlx, game->oeimg,
			game->eimg->instances[0].x, game->eimg->instances[0].y);
	}
}

static void	check_collect(t_data *game, t_pos *player)
{
	char	aux;
	int		i;

	aux = game->map[player->pos_y][player->pos_x];
	if (aux == 'C')
	{
		coun_n_door(game);
		ft_printf("Nice, %d items left to collect.\n", game->ac_collect);
		game->map[player->pos_y][player->pos_x] = '0';
		i = 0;
		while (i < game->c_collect)
		{
			if (game->cimg->instances[i].y == game->pimg->instances[0].y
				&& game->cimg->instances[i].x == game->pimg->instances[0].x)
				game->cimg->instances[i].enabled = false;
			i++;
		}
	}
	else if (aux == 'E')
	{
		exit_door(game);
	}
}

void	moves(t_data *game, t_pos *mov)
{
	if (check_collision(game, mov))
	{
		game->player.pos_x += mov->pos_x;
		game->player.pos_y += mov->pos_y;
		game->pimg->instances[0].x = game->player.pos_x * 64;
		game->pimg->instances[0].y = game->player.pos_y * 64;
		game->c_steps++;
		ft_printf("Player steps: %d\n", game->c_steps);
		check_collect(game, &game->player);
	}
}
