/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:40 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/03 00:25:10 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//TODO change the site of tile_draw_size if you want to change the minimap
static void	get_map(t_map *map, int fd)
{
	char	*gnl;

	gnl = ft_strtrim_head(get_next_line(fd), IS_SPACE);
	while (gnl)
	{
		if (map->nbr_line > 6 && map->len_line < (int)ft_strlen(gnl))
			map->len_line = (int)ft_strlen(gnl);
		if (ft_strlen(gnl) > 1)
		{
			if (map->nbr_line < 6)
				gnl = ft_strtrim_head(gnl, IS_SPACE);
			if (!map->map)
				map->map = ft_strdup(gnl);
			else
				map->map = ft_strjoin_f(map->map, gnl, 1);
			map->nbr_line++;
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	map->nbr_line -= 6;
	map->len_line -= 1;
	map->tile_size = 512;
	map->tile_draw_size = SCREENHEIGHT / 50;
}

static void	populate_map2d(t_map *map, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line && map->map[i])
		{
			if (map->map[i] != '\n')
			{
				if (is_map(map->map[i]) || map->map[i] == ' ')
				{
					if (map->map[i] != ' ')
						map->map2d[y][x] = (char)ft_toupper(map->map[i]);
				}
				else
					map->map2d[y][x] = 'X';
			}
			else
				continue ;
			i++;
		}
		i++;
	}
}

static void	init_map2d(t_map *map)
{
	int	i;
	int	j;

	map->map2d = ft_calloc(sizeof(char *), map->nbr_line);
	if (!map->map2d)
		err_msg(ERR_MALLOC);
	i = -1;
	while (++i < map->nbr_line)
	{
		map->map2d[i] = ft_calloc(sizeof(char), map->len_line);
		if (!map->map2d[i])
			err_msg(ERR_MALLOC);
	}
	i = -1;
	while (++i < map->nbr_line)
	{
		j = -1;
		while (++j < map->len_line)
			map->map2d[i][j] = '.';
	}
}

void	parse_map(t_map *map, char **av)
{
	int	fd;
	int	i;

	check_ext(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_msg(ERR_FD);
	map->map = NULL;
	map->nbr_line = 0;
	map->len_line = 0;
	get_map(map, fd);
	i = get_elems(map);
	init_map2d(map);
	populate_map2d(map, i);
	check_map2d(map);
}
