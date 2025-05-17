/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:01:10 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 17:43:35 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #ifndef SO_LONG_H
// #define SO_LONG_H

// # include <signal.h>
// #include <limits.h>
// #include <stdarg.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <strings.h>
// #include <unistd.h>
// #include <fcntl.h>
// // #include "mlx.h"
// # include "libft/include/libft.h"
// # include "libft/include/ft_printf.h"
// # include "minilibx-linux/mlx.h"
// # include "libft/include/get_next_line.h"

// typedef struct s_map {
//     char **grid;
//     int width;
//     int height;
//     int collectibles;
//     int player_x;
//     int player_y;
//     int exit_x;
//     int exit_y;
// } t_map;

// typedef struct s_game
// {
//     void    *mlx;
//     void    *win;
//     t_map   map;
//     void    *textures[5];
//     int     tex_width;
//     int     tex_height;
//     int     moves;
// }   t_game;

// typedef struct s_dim
// {
// 	int	w;
// 	int	h;
// }	t_dim;

// void	free_map(t_map *map);
// void	free_textures(t_game *game);
// void	free_game(t_game *game);
// int	close_game(t_game *game);
// void	is_map_enclosed(t_map *map);
// void	count_elements(t_map *map, int *player, int *ex, int *collectibles);
// void	has_required_elements(t_map *map);
// void	check_map_validity(t_map *map);
// void	map_dim(char *filename, t_map *map);
// void	map_load(char *filename, t_map *map);
// void	parse_map(char *filename, t_map *map);
// int	can_move(t_game *game, int new_x, int new_y);
// void	move_player(t_game *game, int dx, int dy);
// int	handle_keypress(int keycode, t_game *game);
// void	load_textures(t_game *game);
// void	put_image(t_game *game, int x, int y, char tile);
// void	render_map(t_game *game);
// void	display_moves(t_game *game);
// int	is_valid_path(char **map, int x, int y, t_dim dim);
// void handle_exit(t_game *game, int x, int y);
// void	check_map_characters(t_map *map);
// int	check_map_name(char *filename);

// #endif

#ifndef SO_LONG_H
# define SO_LONG_H

# include <signal.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "libft/include/get_next_line.h"
# include "minilibx-linux/mlx.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	void	*textures[5];
	int		tex_width;
	int		tex_height;
	int		moves;
}	t_game;

typedef struct s_dim
{
	int		w;
	int		h;
}	t_dim;

void	free_map(t_map *map);
void	free_textures(t_game *game);
void	free_game(t_game *game);
int		close_game(t_game *game);

void	is_map_enclosed(t_map *map);
void	count_elements(t_map *map, int *player, int *ex, int *collectibles);
void	has_required_elements(t_map *map);
void	check_map_validity(t_map *map);
void	check_map_characters(t_map *map);
int		check_map_name(char *filename);

void	map_dim(char *filename, t_map *map);
void	map_load(char *filename, t_map *map);
void	parse_map(char *filename, t_map *map);

int		can_move(t_game *game, int new_x, int new_y);
void	move_player(t_game *game, int dx, int dy);
int		handle_keypress(int keycode, t_game *game);
void	handle_exit(t_game *game, int x, int y);

void	load_textures(t_game *game);
void	put_image(t_game *game, int x, int y, char tile);
void	render_map(t_game *game);
void	display_moves(t_game *game);

int		is_valid_path(char **map, int x, int y, t_dim dim);
void	free_map_struct(char **map, int h);
void	check_xpm_files(void);
void	free_map_struct(char **map, int h);
void	display_move(t_game *game);
void	display_move(t_game *game);
int		is_rectangular(t_map *map);
int		is_valid_path(char **map, int x, int y, t_dim dim);
char	**allocate_map(int h, int w);
void	copy_map(char **src, char **dst, int h, int w);
void	flood(char **map, int x, int y, t_dim dim);
int		is_exit_reachable(char **map, int x, int y);
void	find_exit_position(t_map *data);

#endif
