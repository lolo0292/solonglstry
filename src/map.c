/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/19 18:01:05 by lleichtn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'P' || c == 'E');
}

void	check_map_characters(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->grid[y])
	{
		x = 0;
		while (map->grid[y][x])
		{
			if (map->grid[y][x] == '\n')
			{
				x++;
				continue ;
			}
			if (!is_valid_char(map->grid[y][x]))
			{
				write(2, "Erreur : caractère invalide dans la map\n", 40);
				free_map_struct(map->grid, map->height);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	count_map_dimensions(int fd, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			write(2, "Erreur : ligne vide détectée dans la map\n", 42);
			free(line);
			get_next_line(-1);
			close(fd);
			exit(1);
		}
		if (map->height == 0)
		{
			len = ft_strlen(line);
			map->width = len - (line[len - 1] == '\n');
		}
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
}

void	map_dim(char *filename, t_map *map)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Erreur : fichier ", 18);
		write(2, filename, ft_strlen(filename));
		write(2, " introuvable\n", 13);
		exit(1);
	}
	map->height = 0;
	map->width = 0;
	count_map_dimensions(fd, map);
	close(fd);
}

void	parse_map(char *filename, t_map *map)
{
	if (!check_map_name(filename))
	{
		write(2, "Erreur : le fichier doit se terminer par .ber\n", 47);
		exit(1);
	}
	map_dim(filename, map);
	map_load(filename, map);
	check_map_characters(map);
	if (!is_rectangular(map))
	{
		write(2, "Erreur : map non rectangulaire\n", 32);
		free_map_struct(map->grid, map->height);
		exit(1);
	}
}
