/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:40:03 by mahender          #+#    #+#             */
/*   Updated: 2022/10/27 18:40:06 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_img(t_data *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*text;

	text = mlx_load_png(path);
	if (text == NULL)
	{
		mlx_close_window(game->mlx);
		free_exit(game);
	}
	else
	{
		*img = mlx_texture_to_image(game->mlx, text);
		mlx_delete_texture(text);
	}
}

void	save_images(t_data *game)
{
	check_img(game, &game->wimg, "./images/wall.png");
	check_img(game, &game->bimg, "./images/back.png");
	check_img(game, &game->pimg, "./images/player.png");
	check_img(game, &game->eimg, "./images/cexit.png");
	check_img(game, &game->cimg, "./images/collect.png");
	check_img(game, &game->oeimg, "./images/oexit.png");
}

static void	drawback(t_data *game)
{
	int	y;
	int	x;

	y = 0;
	save_images(game);
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			mlx_image_to_window(game->mlx, game->bimg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	drawmap(t_data *game)
{
	int	y;
	int	x;

	drawback(game);
	y = 0;
	while (y < game->h)
	{
		x = 0;
		while (x < game->w)
		{
			if (game->map[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wimg, x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->pimg, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->eimg, x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->cimg, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
