/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:36:56 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 00:26:55 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*img_initalize(char *img, t_game *game)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(game->mlx, img, &game->img_width, &game->img_height);
	return (img_ptr);
}

void	t_map_init(t_map *m)
{
	m->col = 0;
	m->row = 0;
	m->e_count = 0;
	m->p_count = 0;
	m->c_count = 0;
}
