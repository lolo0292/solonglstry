/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 17:18:49 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 18:46:23 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(t_map *map)
{
	int	y;
	int	x;
	int	width;

	if (!map || !map->grid || !map->grid[0])
		return (0);
	y = 0;
	width = 0;
	while (map->grid[0][width] && map->grid[0][width] != '\n')
		width++;
	map->width = width;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x] && map->grid[y][x] != '\n')
			x++;
		if (x != width)
			return (0);
		y++;
	}
	return (1);
}

static int	check_path_and_collectibles(t_map *data, t_dim dim)
{
	char	**copy;
	int		i;

	copy = allocate_map(dim.h, dim.w);
	if (!copy)
		return (0);
	copy_map(data->grid, copy, dim.h, dim.w);
	flood(copy, data->player_x, data->player_y, dim);
	if (!is_exit_reachable(copy, data->exit_x, data->exit_y))
		return (free_map_struct(copy, dim.h), 0);
	i = 0;
	while (i < dim.h)
	{
		if (ft_strchr(copy[i], 'C'))
			return (free_map_struct(copy, dim.h), 0);
		i++;
	}
	free_map_struct(copy, dim.h);
	return (1);
}

int	is_valid_path(char **map, int x, int y, t_dim dim)
{
	t_map	data;

	data.grid = map;
	data.player_x = x;
	data.player_y = y;
	data.height = dim.h;
	data.width = dim.w;
	data.exit_x = -1;
	data.exit_y = -1;
	find_exit_position(&data);
	if (data.exit_x == -1 || data.exit_y == -1)
		return (0);
	return (check_path_and_collectibles(&data, dim));
}

void	find_exit_position(t_map *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->grid[i][j] == 'E')
			{
				data->exit_x = j;
				data->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	copy_map(char **src, char **dst, int h, int w)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		dst[i][j] = '\0';
		i++;
	}
}
