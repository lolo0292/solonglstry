/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:08:46 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 14:32:35 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// // Vérifie si le déplacement est valide (pas un mur '1')
// int	can_move(t_game *game, int new_x, int new_y)
// {
// 	if (game->map.grid[new_y][new_x] == '1')
// 		return (0);
// 	return (1);
// }

// // Met à jour la position du joueur et interagit avec la carte
// void	move_player(t_game *game, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = game->map.player_x + dx;
// 	new_y = game->map.player_y + dy;
// 	if (!can_move(game, new_x, new_y))
// 		return ;
// 	if (game->map.grid[new_y][new_x] == 'C')
// 	{
// 		game->map.collectibles--;
// 		game->map.grid[new_y][new_x] = '0';
// 	}
// 	if (game->map.grid[new_y][new_x] == 'E')
// 	{
// 		handle_exit(game, new_x, new_y);
// 		return ;
// 	}
// 	game->map.grid[game->map.player_y][game->map.player_x] = '0';
// 	game->map.grid[new_y][new_x] = 'P';
// 	game->map.player_x = new_x;
// 	game->map.player_y = new_y;
// 	game->moves++;
// 	render_map(game);
// 	display_moves(game);
// }

// // Gère les touches du clavier
// int	handle_keypress(int keycode, t_game *game)
// {
// 	if (keycode == 65307)
// 		free_game(game);
// 	else if (keycode == 119)
// 		move_player(game, 0, -1);
// 	else if (keycode == 97)
// 		move_player(game, -1, 0);
// 	else if (keycode == 115)
// 		move_player(game, 0, 1);
// 	else if (keycode == 100)
// 		move_player(game, 1, 0);
// 	return (0);
// }

// // Empêche de finir tant qu'il reste des collectibles
// void	handle_exit(t_game *game, int x, int y)
// {
// 	(void)x;
// 	(void)y;
// 	if (game->map.collectibles == 0)
// 	{
// 		write(1, "Well done champ\n", 16);
// 		free_game(game);
// 	}
// }

// void	free_map_struct(char **map, int h)
// {
// 	int	i;

// 	i = 0;
// 	while (i < h)
// 	{
// 		free(map[i]);
// 		i++;
// 	}
// 	free(map);
// }

#include "so_long.h"
#include <unistd.h>

int	can_move(t_game *game, int new_x, int new_y)
{
	if (game->map.grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	display_moves(t_game *game)
{
	char	buffer[12];
	int		n;
	int		i;

	n = game->moves;
	i = 10;
	buffer[11] = '\n';
	while (i >= 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
		i--;
	}
	write(1, "Mouvements : ", 13);
	write(1, &buffer[i], 12 - i);
}

void	handle_exit(t_game *game, int x, int y)
{
	(void)x;
	(void)y;
	if (game->map.collectibles == 0)
	{
		write(1, "Well done champ\n", 16);
		free_game(game);
	}
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->map.player_x + dx;
	new_y = game->map.player_y + dy;
	if (!can_move(game, new_x, new_y))
		return ;
	if (game->map.grid[new_y][new_x] == 'C')
	{
		game->map.collectibles--;
		game->map.grid[new_y][new_x] = '0';
	}
	if (game->map.grid[new_y][new_x] == 'E')
		return (handle_exit(game, new_x, new_y));
	game->map.grid[game->map.player_y][game->map.player_x] = '0';
	game->map.grid[new_y][new_x] = 'P';
	game->map.player_x = new_x;
	game->map.player_y = new_y;
	game->moves++;
	render_map(game);
	display_move(game);
	display_moves(game);
}

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
		free_game(game);
	else if (keycode == 119)
		move_player(game, 0, -1);
	else if (keycode == 97)
		move_player(game, -1, 0);
	else if (keycode == 115)
		move_player(game, 0, 1);
	else if (keycode == 100)
		move_player(game, 1, 0);
	return (0);
}
