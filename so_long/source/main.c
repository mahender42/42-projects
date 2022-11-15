/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:46:36 by mahender          #+#    #+#             */
/*   Updated: 2022/10/16 17:46:39 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (ac == 2)
	{
		check_arg(av[1], &game);
		create_map(&game);
		init_win(&game);
		drawmap(&game);
		mlx_key_hook(game.mlx, &my_keyhook, &game);
		mlx_loop(game.mlx);
		mlx_terminate(game.mlx);
	}
	else
		print_err("Error\nThe number of arguments is not correct.");
	return (0);
}
