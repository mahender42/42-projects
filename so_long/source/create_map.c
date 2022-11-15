/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:45:54 by mahender          #+#    #+#             */
/*   Updated: 2022/10/17 17:45:57 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	create_map(t_data *game)
{
	map_height(game);
	map_width(game);
	save_map(game);
	init_vars(game);
	check_map(game);
}

void	map_height(t_data *game)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open (game->map_path, O_RDONLY);
	if (fd == -1)
		print_err("Error!\nMap not found");
	line = get_next_line(fd);
	while (line != NULL)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	game->h = i;
}

void	map_width(t_data *game)
{
	size_t	i;
	int		fd;
	char	*line;

	fd = open (game->map_path, O_RDONLY);
	if (fd == -1)
		print_err("Error!\nMap not found");
	line = get_next_line(fd);
	i = ft_strlen(line) - 1;
	while (line != NULL)
	{
		is_rect(line, i);
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	game->w = i;
}

void	is_rect(char *line, size_t i)
{
	char	*aux;
	size_t	j;

	aux = ft_strtrim(line, "\n");
	j = ft_strlen(aux);
	if (j == i)
		free (aux);
	else
	{
		free(aux);
		free(line);
		print_err("ERROR!\nMap is not rectangular.");
	}
}

void	save_map(t_data *game)
{
	int	fd;
	int	i;

	fd = open (game->map_path, O_RDONLY);
	if (fd == -1)
		print_err("Error!\nMap not found");
	i = 0;
	game->map = calloc(game->h + 1, game->w);
	while (i < game->h)
	{
		game->map[i] = get_next_line(fd);
		i++;
	}
	game->map[i] = 0;
	close(fd);
}
