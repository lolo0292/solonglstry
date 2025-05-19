/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:21:58 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/19 18:00:19 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	free_game(game);
	return (0);
}

static int	init_and_run_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->moves = 0;
	load_textures(game);
	game->win = mlx_new_window(game->mlx,
			game->map.width * 32,
			game->map.height * 32,
			"so_long");
	if (!game->win)
	{
		write(2, "Erreur : création de la fenêtre échouée\n", 41);
		exit_clean(game, 5, NULL);
	}
	render_map(game);
	mlx_hook(game->win, 2, 1L << 0, handle_keypress, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	mlx_loop(game->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_dim	dim;

	if (argc != 2)
		return (1);
	parse_map(argv[1], &game.map);
	check_map_validity(&game.map);
	dim.w = game.map.width;
	dim.h = game.map.height;
	if (!is_valid_path(game.map.grid, game.map.player_x,
			game.map.player_y, dim))
	{
		write(2, "Error\nno path possible\n", 22);
		free_map(&game.map);
		get_next_line(-1);
		return (1);
	}
	init_and_run_game(&game);
	free_map(&game.map);
	get_next_line(-1);
	return (0);
}
