/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:13 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 00:04:04 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_pressed(int keycode, t_game *game)
{
	if (keycode == KEY_ESC || keycode == KEY_Q)
		exit_game(game);
	else if (game->end_game)
		return (0);
	else
	{
		map_update(keycode, game);
	}
	return (0);
}

static void	next_0(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'P');
	game->moves++;
	display_info(game);
}

static void	next_c(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'P');
	game->moves++;
	game->collected++;
	display_info(game);
}

static void	next_e(t_game *game, int ny, int nx)
{
	int		gx;
	int		gy;

	gx = game->x;
	gy = game->y;
	change_position(&game->map[gy][gx], &game->map[ny][nx], '0', 'X');
	game->moves++;
	game->end_game = 1;
	display_info(game);
}

void	press_key(t_game *game, int ny, int nx)
{
	if (game->map[ny][nx] == '0')
		next_0(game, ny, nx);
	else if (game->map[ny][nx] == 'C')
		next_c(game, ny, nx);
	else if (game->map[ny][nx] == 'E'
		&& (game->collected == game->collectable))
		next_e(game, ny, nx);
	else
		return ;
}
