/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:31 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 02:04:37 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_draw(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, img, x * SPRITE_SIZE, y * SPRITE_SIZE);
}

void	change_position(char *pos, char *next_pos, char val, char new_val)
{
	*pos = val;
	*next_pos = new_val;
}

void	update_player(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		game->player_direction = 'w';
		press_key(game, game->y - 1, game->x);
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		game->player_direction = 'a';
		press_key(game, game->y, game->x - 1);
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{	
		game->player_direction = 's';
		press_key(game, game->y + 1, game->x);
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		game->player_direction = 'd';
		press_key(game, game->y, game->x + 1);
	}
	else
		return ;
}

void	draw_sprites(t_game *game, int i, int j, int update)
{
	if (game->map[i][j] == '1')
		img_draw(game, game->img_wall, j, i);
	else if (game->map[i][j] == '0')
		img_draw(game, game->img_space, j, i);
	else if (game->map[i][j] == 'C')
	{
		img_draw(game, game->img_collect, j, i);
		if (update == 0)
			game->collectable++;
	}
	else if (game->map[i][j] == 'E')
		img_draw(game, game->img_exit, j, i);
	else if (game->map[i][j] == 'P')
	{
		draw_player(game, i, j);
		game->x = j;
		game->y = i;
	}
	else if (game->map[i][j] == 'X')
		img_draw(game, game->img_end, j, i);
}

void	draw_player(t_game *game, int i, int j)
{
	if (game->player_direction == 'w')
		img_draw(game, game->player_w, j, i);
	else if (game->player_direction == 'a')
		img_draw(game, game->player_a, j, i);
	else if (game->player_direction == 's')
		img_draw(game, game->player_s, j, i);
	else if (game->player_direction == 'd')
		img_draw(game, game->player_d, j, i);
}
