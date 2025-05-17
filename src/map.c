/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleichtn <lleichtn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:04:03 by lleichtn          #+#    #+#             */
/*   Updated: 2025/05/17 20:02:30 by lleichtn         ###   ########.fr       */
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
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	map_dim(char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(1);
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			if (map->height == 0)
			{
				len = ft_strlen(line);
				map->width = len - (line[len - 1] == '\n');
			}
			map->height++;
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

// static void	clear_trailing_lines(int fd)
// {
// 	char	*line;

// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// }

// static void	load_valid_lines(int fd, t_map *map)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	line = get_next_line(fd);
// 	while (line && i < map->height)
// 	{
// 		if (line[0] && line[0] != '\n')
// 			map->grid[i++] = line;
// 		else
// 			free(line);
// 		if (i < map->height)
// 			line = get_next_line(fd);
// 	}
// 	map->grid[i] = NULL;
// 	clear_trailing_lines(fd);
// }

// void	map_load(char *filename, t_map *map)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 		exit(1);
// 	map->grid = malloc(sizeof(char *) * (map->height + 1));
// 	if (!map->grid)
// 		exit(1);
// 	load_valid_lines(fd, map);
// 	close(fd);
// }

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
