/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:16 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 01:48:34 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_window_size(t_game *game)
{
	int	i;

	i = 0;
	game->win_width = ft_strlen(game->map[i]) * SPRITE_SIZE;
	game->win_height = 0;
	while (game->map[i])
	{
		game->win_height++;
		i++;
	}
	game->win_height *= SPRITE_SIZE;
}

void	game_init(t_game *game)
{
	data_init(game);
	img_init(game);
	map_init(game);
	mlx_hook(game->win, X_EVENT_KEY_PRESS, 1L << 0, &key_pressed, game);
	mlx_hook(game->win, X_EVENT_DESTROY_NOTIFY, 0, &exit_game, game);
	mlx_hook(game->win, X_EVENT_FOCUS_IN, 1L << 21, &map_resume, game);
}

void	data_init(t_game *game)
{
	get_window_size(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window
		(game->mlx, game->win_width, game->win_height, "so_long");
	game->moves = 0;
	game->collected = 0;
	game->collectable = 0;
	game->player_direction = 's';
	game->end_game = 0;
}

void	img_init(t_game *game)
{
	game->img_space = img_initalize(IMG_SPACE, game);
	game->img_wall = img_initalize(IMG_WALL, game);
	game->img_collect = img_initalize(IMG_COLLECT, game);
	game->img_exit = img_initalize(IMG_EXIT, game);
	game->img_end = img_initalize(IMG_END, game);
	game->player_w = img_initalize(PLAYER_W, game);
	game->player_a = img_initalize(PLAYER_A, game);
	game->player_s = img_initalize(PLAYER_S, game);
	game->player_d = img_initalize(PLAYER_D, game);
}

void	map_init(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_sprites(game, i, j, 0);
			j++;
		}
		i++;
	}
}
