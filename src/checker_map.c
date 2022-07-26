/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:17:30 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/26 18:17:33 by tpinto-m         ###   ########.fr       */
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

void	check_map2d(t_map *map)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (++y < map->nbr_line)
	{
		x = 0;
		while (++x < map->len_line)
		{
			i = 0;
			if (map->map2d[y][x - 1] == '1' || map->map2d[y][x - 1] == '.')
				i++;
			if (map->map2d[y - 1][x] == '1' || map->map2d[y - 1][x] == '.')
				i++;
			if (map->map2d[y][x + 1] == '1' || map->map2d[y - 1][x + 1] == '.')
				i++;
			if (map->map2d[y + 1][x] == '1' || map->map2d[y + 1][x] == '.')
				i++;
			printf("%d", i);
		}
		printf("\n");
	}
}
