/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:24 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 02:04:55 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_updater(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_sprites(game, i, j, 1);
			j++;
		}
		i++;
	}
}

void	map_update(int keycode, t_game *game)
{
	update_player(keycode, game);
	map_updater(game);
}

int	map_resume(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			draw_sprites(game, i, j, 1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**map_gen(char *path_to_file)
{
	char	**result;
	char	*holder;
	char	*old_address;
	char	*map;
	int		fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_strdup("");
	while (1)
	{
		holder = ft_get_next_line(fd);
		if (!holder)
			break ;
		old_address = map;
		map = ft_strjoin(old_address, holder);
		ft_free_ptr((void *)&holder);
	}
	result = ft_split(map, '\n');
	ft_free_ptr((void *)&map);
	close(fd);
	return (result);
}
