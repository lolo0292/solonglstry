/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:13 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 19:08:53 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Vérifie que l'extension du fichier est .ber
int	check_map_name(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 4)
		return (0);
	if (filename[i - 4] != '.' || filename[i - 3] != 'b'
		|| filename[i - 2] != 'e' || filename[i - 1] != 'r')
		return (0);
	return (1);
}

void	is_map_enclosed(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
		{
			write(2, "Error\nMap pas valide\n", 22);
			free_map(map);
			get_next_line(-1);
			exit(1);
		}
		x++;
	}
	x = -1;
	while (++x < map->height)
	{
		if (map->grid[x][0] != '1' || map->grid[x][map->width - 1] != '1')
		{
			write(2, "Error\nMap pas valide\n", 22);
			free_map(map);
			get_next_line(-1);
			exit(1);
		}
	}
}

// Compte les éléments essentiels de la map (P, E, C)
void	count_elements(t_map *map, int *player, int *ex, int *collectibles)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
			{
				(*player)++;
				map->player_x = x;
				map->player_y = y;
			}
			else if (map->grid[y][x] == 'E')
				(*ex)++;
			else if (map->grid[y][x] == 'C')
				(*collectibles)++;
			x++;
		}
		y++;
	}
}

void	has_required_elements(t_map *map)
{
	int	player;
	int	ex;
	int	collectibles;

	player = 0;
	ex = 0;
	collectibles = 0;
	count_elements(map, &player, &ex, &collectibles);
	if (player != 1 || ex != 1 || collectibles < 1)
	{
		write(2, "Error\nMap must contain 1 P, 1 E and at least 1 C\n", 48);
		free_map(map);
		get_next_line(-1);
		exit(1);
	}
	map->collectibles = collectibles;
}

// Appelle tous les contrôles principaux sur la map (sauf syntaxe)
void	check_map_validity(t_map *map)
{
	is_map_enclosed(map);
	has_required_elements(map);
}
