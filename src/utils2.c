/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 19:53:36 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/19 16:27:47 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_trailing_lines(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

static void	load_valid_lines(int fd, t_map *map)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < map->height)
	{
		if (line[0] && line[0] != '\n')
			map->grid[i++] = line;
		else
			free(line);
		if (i < map->height)
			line = get_next_line(fd);
	}
	map->grid[i] = NULL;
	clear_trailing_lines(fd);
}

void	map_load(char *filename, t_map *map)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		exit(1);
	load_valid_lines(fd, map);
	close(fd);
}
// void	map_load(char *filename, t_map *map)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(2, "Erreur : fichier ", 18);
// 		write(2, filename, ft_strlen(filename));
// 		write(2, " introuvable\n", 13);
// 		exit(1);
// 	}
// 	map->width = 0;
// 	map->height = 0;
// 	map_dim(filename, map);
// 	close(fd);
// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write(2, "Erreur : ouverture échouée\n", 28);
// 		exit(1);
// 	}
// 	map->grid = malloc(sizeof(char *) * (map->height + 1));
// 	if (!map->grid)
// 		exit(1);
// 	load_valid_lines(fd, map);
// 	close(fd);
// }

// void	exit_clean(t_game *game, int textures_loaded)
// {
// 	int	i;

// 	i = 0;
// 	while (i < textures_loaded)
// 	{
// 		if (game->textures[i])
// 			mlx_destroy_image(game->mlx, game->textures[i]);
// 		i++;
// 	}
// 	if (game->win)
// 		mlx_destroy_window(game->mlx, game->win);
// 	if (game->mlx)
// 	{
// 		mlx_destroy_display(game->mlx);
// 		free(game->mlx);
// 	}
// 	free_map(&game->map);
// 	get_next_line(-1);
// 	exit(1);
// }

void	exit_clean(t_game *game, int textures_loaded, char *errmsg)
{
	int	i;

	if (errmsg)
		write(2, errmsg, ft_strlen(errmsg));
	i = 0;
	while (i < textures_loaded)
	{
		if (game->textures[i])
			mlx_destroy_image(game->mlx, game->textures[i]);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(&game->map);
	get_next_line(-1);
	exit(1);
}
