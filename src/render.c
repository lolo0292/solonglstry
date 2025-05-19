/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:18:15 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/19 16:19:19 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Place la bonne image sur la carte selon le caractère de `map->grid`
void	put_image(t_game *game, int x, int y, char tile)
{
	void	*img;

	if (tile == '1')
		img = game->textures[0];
	else if (tile == '0')
		img = game->textures[1];
	else if (tile == 'C')
		img = game->textures[2];
	else if (tile == 'E')
		img = game->textures[3];
	else
		img = game->textures[4];
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

// Affiche la carte complète dans la fenêtre MiniLibX
void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_image(game, x, y, game->map.grid[y][x]);
			x++;
		}
		y++;
	}
}

void	display_move(t_game *game)
{
	char	*moves_str;
	char	*msg;

	moves_str = ft_itoa(game->moves);
	msg = ft_strjoin("Mouvements : ", moves_str);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, msg);
	free(moves_str);
	free(msg);
}

void	load_textures(t_game *game)
{
	check_xpm_files();
	game->textures[0] = mlx_xpm_file_to_image(game->mlx, "./sprites/wall.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[0])
		exit_clean(game, 0, "Erreur : .xpm introuvable \n");
	game->textures[1] = mlx_xpm_file_to_image(game->mlx, "./sprites/floor.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[1])
		exit_clean(game, 1, "Erreur : .xpm introuvable \n");
	game->textures[2] = mlx_xpm_file_to_image(game->mlx, "./sprites/c.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[2])
		exit_clean(game, 2, "Erreur : .xpm introuvable \n");
	game->textures[3] = mlx_xpm_file_to_image(game->mlx, "./sprites/exit.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[3])
		exit_clean(game, 3, "Erreur : .xpm introuvable\n");
	game->textures[4] = mlx_xpm_file_to_image(game->mlx, "./sprites/player.xpm",
			&game->tex_width, &game->tex_height);
	if (!game->textures[4])
		exit_clean(game, 4, "Erreur : .xpm introuvable \n");
}

void	check_xpm_files(void)
{
	int		i;
	char	*paths[5];

	paths[0] = "./sprites/wall.xpm";
	paths[1] = "./sprites/floor.xpm";
	paths[2] = "./sprites/c.xpm";
	paths[3] = "./sprites/exit.xpm";
	paths[4] = "./sprites/player.xpm";
	i = 0;
	while (i < 5)
	{
		if (ft_strncmp(paths[i] + ft_strlen(paths[i]) - 4, ".xpm", 4) != 0)
			exit(1);
		i++;
	}
}
