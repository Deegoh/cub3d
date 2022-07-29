/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:17:30 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/29 07:12:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_ext(char *path)
{
	char	*ext;

	ext = ft_strnstr(path, EXT, ft_strlen(path));
	if (ext && ft_strlen(ext) == ft_strlen(EXT))
		return ;
	err_msg(ERR_FILE);
}

int	is_color(int one_color)
{
	if (one_color < 0 || one_color > 255)
		err_msg(ERR_COLOR);
	return (one_color);
}

static void	check_border_map(t_map *map, int x, int y)
{
	if (y == 0 || y == map->nbr_line - 1 || x == 0 || x == map->len_line -1)
		if (map->map2d[y][x] != '.' && map->map2d[y][x] != '1')
			err_msg(ERR_MAP_CLOSE);
}

static void	check_center_map(t_map *map, int x, int y)
{
	if (x > 0 && y > 0 && x < map->len_line - 1 && y < map->nbr_line - 1)
	{
		if ((map->map2d[y][x] == '0' && map->map2d[y][x - 1] == '.')
			|| (map->map2d[y][x] == '0' && map->map2d[y][x + 1] == '.')
			|| (map->map2d[y][x] == '0' && map->map2d[y - 1][x] == '.')
			|| (map->map2d[y][x] == '0' && map->map2d[y + 1][x] == '.'))
		{
			err_msg(ERR_MAP_CLOSE);
		}
	}
}

void	check_map2d(t_map *map)
{
	int	x;
	int	y;
	int	player;

	player = 0;
	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			if (map->map2d[y][x] == 'X')
				err_msg(ERR_MAP_CONTENT);
			check_border_map(map, x, y);
			check_center_map(map, x, y);
			if (is_player(map->map2d[y][x]))
				player++;
		}
	}
	if (map->len_line < 3 || map->nbr_line < 3)
		err_msg(ERR_MAP_SIZE);
	if (player != 1)
		err_msg(ERR_MAP_PLAYER);
}
