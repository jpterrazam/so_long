/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaulo-d <jpaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 03:24:29 by jpaulo-d          #+#    #+#             */
/*   Updated: 2022/08/31 02:06:45 by jpaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libs/libft/libft.h"
# include "libs/minilibx/mlx.h"
# include "libs/minilibx/mlx_int.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	*img_space;
	t_img	*img_wall;
	t_img	*img_collect;
	t_img	*img_exit;
	t_img	*img_end;
	t_img	*player_w;
	t_img	*player_a;
	t_img	*player_s;
	t_img	*player_d;
	char	**map;
	int		player_direction;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
	int		moves;
	int		collected;
	int		collectable;
	int		end_game;
}	t_game;

typedef struct s_map
{
	int	col;
	int	row;
	int	e_count;
	int	p_count;
	int	c_count;
}	t_map;

# define DEBUG 0

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define X_EVENT_FOCUS_IN 9

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# define IMG_SPACE "images/0.xpm"
# define IMG_WALL "images/1.xpm"
# define IMG_COLLECT "images/C.xpm"
# define IMG_EXIT "images/E.xpm"
# define IMG_END "images/X.xpm"

# define PLAYER_W "images/P_W.xpm"
# define PLAYER_A "images/P_A.xpm"
# define PLAYER_S "images/P_S.xpm"
# define PLAYER_D "images/P_D.xpm"

# define SPRITE_SIZE 32

int		display_info(t_game *game);
void	draw_sprites(t_game *game, int i, int j, int update);
int		exit_game(t_game *game);
int		key_pressed(int keycode, t_game *game);
int		map_check(char **map, char *file);
int		map_resume(t_game *game);
void	change_position(char *pos, char *next_pos, char val, char new_val);
void	data_init(t_game *game);
void	free_game(t_game *game);
void	free_map(char **map);
void	game_init(t_game *game);
void	*img_initalize(char *img, t_game *game);
void	get_window_size(t_game *game);
void	press_key(t_game *game, int ny, int nx);
void	img_draw(t_game *game, void *img, int x, int y);
void	draw_player(t_game *game, int i, int j);
void	img_init(t_game *game);
void	map_init(t_game *game);
void	map_update(int keycode, t_game *game);
void	t_map_init(t_map *m);
void	update_direction(int player_direction, t_game *game);
void	update_player(int keycode, t_game *game);
char	**map_gen(char *path_to_file);

#endif
