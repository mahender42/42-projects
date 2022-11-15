/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahender <mahender@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:38:55 by mahender          #+#    #+#             */
/*   Updated: 2022/10/15 18:38:59 by mahender         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_possiton
{
	int	pos_y;
	int	pos_x;
}	t_pos;

typedef struct s_moves
{
	t_pos	mup;
	t_pos	mdown;
	t_pos	mright;
	t_pos	mleft;
}	t_moves;

typedef struct s_data
{
	int			w;
	int			h;
	char		*arch;
	char		*map_path;
	char		**map;
	int			c_exit;
	int			c_player;
	int			c_collect;
	int			ac_collect;
	t_pos		player;
	int			collected;
	mlx_t		*mlx;
	mlx_image_t	*wimg;
	mlx_image_t	*bimg;
	mlx_image_t	*eimg;
	mlx_image_t	*oeimg;
	mlx_image_t	*pimg;
	mlx_image_t	*cimg;
	t_moves		move;
	int			c_steps;
}	t_data;

void	check_arg(char *arg, t_data *game);
void	print_err(char *str);
void	free_exit(t_data *game);
void	map_height(t_data *game);
void	map_width(t_data *game);
void	save_map(t_data *game);
void	init_vars(t_data *game);
int		check_map(t_data *game);
void	p_pos(t_data *game, int x, int y);
void	counter(t_data *game, char c);
int		check_wall(t_data *game);
void	create_map(t_data *game);
void	init_win(t_data *game);
void	drawmap(t_data *game);
void	init_moves(t_data *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	moves(t_data *game, t_pos *mov);
void	exit_door(t_data *game);
void	close_exit(t_data *game);
void	is_rect(char *line, size_t i);
void	save_images(t_data *game);

#endif
