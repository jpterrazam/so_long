/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:27 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 00:36:09 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	setbuf(stdout, NULL);
	if (argc == 2)
	{
		game.map = map_gen(argv[1]);
		if (map_check(game.map, argv[1]))
		{
			game_init(&game);
			mlx_loop(game.mlx);
		}
		else
		{
			printf("Error\nInvalid map!\n");
			free_map(game.map);
			exit(1);
		}
	}
	else
	{
		printf("Error\nNo map specified!\n");
		exit(1);
	}
	return (0);
}

int	display_info(t_game *game)
{
	int	i;

	if (DEBUG)
	{
		i = 0;
		while (game->map[i])
		{
			printf("%s\n", game->map[i]);
			i++;
		}
		printf("collectable: %d\n", game->collectable);
		printf("collected: %d\n", game->collected);
		printf("player: X: %d | Y: %d | D: %c\n",
			game->x, game->y, ft_toupper(game->player_direction));
	}
	printf("moves: %d\n", game->moves);
	return (1);
}
