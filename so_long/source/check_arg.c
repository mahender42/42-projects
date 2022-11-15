/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:32:17 by mahender          #+#    #+#             */
/*   Updated: 2022/10/16 18:32:19 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_arg(char *arg, t_data *game)
{
	char	*ptr;
	char	*path;
	int		fd;

	ptr = ft_strrchr(arg, '.');
	if (!ptr || ft_strncmp(".ber", ptr, 4) != 0)
		print_err("Error\nIt´s not a .ber flie.");
	path = ft_strjoin("./maps/", arg);
	fd = open (path, O_RDONLY);
	if (fd == -1)
	{
		free(path);
		print_err("Error\nMap not found.");
	}
	else
	{
		game->map_path = ft_strdup(path);
		free(path);
	}
	close(fd);
}
