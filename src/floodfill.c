/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:44:49 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 17:47:58 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_flood_tile(char tile)
{
	return (tile == '0' || tile == 'C' || tile == 'P');
}

void	flood_recursive(char **map, int x, int y, t_dim dim)
{
	map[y][x] = 'F';
	flood(map, x + 1, y, dim);
	flood(map, x - 1, y, dim);
	flood(map, x, y + 1, dim);
	flood(map, x, y - 1, dim);
}

void	flood(char **map, int x, int y, t_dim dim)
{
	if (x < 0 || y < 0)
		return ;
	if (x >= dim.w || y >= dim.h)
		return ;
	if (!is_valid_flood_tile(map[y][x]))
		return ;
	flood_recursive(map, x, y, dim);
}

int	is_exit_reachable(char **map, int x, int y)
{
	if (map[y + 1][x] == 'F')
		return (1);
	if (map[y - 1][x] == 'F')
		return (1);
	if (map[y][x + 1] == 'F')
		return (1);
	if (map[y][x - 1] == 'F')
		return (1);
	return (0);
}

char	**allocate_map(int h, int w)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (h + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < h)
	{
		map[i] = malloc(sizeof(char) * (w + 1));
		if (!map[i])
			return (NULL);
		i++;
	}
	map[i] = NULL;
	return (map);
}
