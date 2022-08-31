/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:09 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 01:49:30 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	free_map(game->map);
	free_game(game);
	exit(0);
	return (0);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		ft_free_ptr((void *)&map[i]);
		i++;
	}
	ft_free_ptr((void *)&map);
}

void	free_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_space);
	mlx_destroy_image(game->mlx, game->img_wall);
	mlx_destroy_image(game->mlx, game->img_collect);
	mlx_destroy_image(game->mlx, game->img_exit);
	mlx_destroy_image(game->mlx, game->img_end);
	mlx_destroy_image(game->mlx, game->player_w);
	mlx_destroy_image(game->mlx, game->player_a);
	mlx_destroy_image(game->mlx, game->player_s);
	mlx_destroy_image(game->mlx, game->player_d);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_ptr(&game->mlx);
}
