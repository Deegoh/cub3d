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

char	**init_map2d_check(t_map *map)
{
	int		i;
	int		j;
	char	**new_map;

	new_map = ft_calloc(sizeof(char *), map->nbr_line);
	if (!new_map)
		err_msg("Error\nMalloc\n");
	i = -1;
	while (++i < map->nbr_line)
	{
		new_map[i] = ft_calloc(sizeof(char), map->len_line);
		if (!new_map[i])
			err_msg("Error\nMalloc[i]\n");
	}
	i = -1;
	while (++i < map->nbr_line)
	{
		j = -1;
		while (++j < map->len_line)
		{
			if (map->map2d[i][j] == '.')
				new_map[i][j] = '5';
//			else
//				new_map[i][j] = map->map2d[i][j];
		}
	}
	return (new_map);
}

//void	popu_map2d_check(t_map *map)
//{
//
//}

void	check_map2d(t_map *map)
{
	int		x;
	int		y;
	int		i;
//	char	**check_map;

//	check_map = init_map2d_check(map);
//	(void)check_map;
//	y = -1;
//	while (++y < map->nbr_line)
//	{
//		x = -1;
//		while (++x < map->len_line)
//		{
//			printf("%c", check_map[y][x]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	free_arr(check_map);
	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			if (x > 0 && y > 0 && x < map->len_line -1 && y < map->nbr_line -1)
			{
				i = 0;
				if (map->map2d[y][x - 1] == '1')
					i++;
				if (map->map2d[y - 1][x] == '1')
					i++;
				if (map->map2d[y][x + 1] == '1')
					i++;
				if (map->map2d[y + 1][x] == '1')
					i++;
				if (map->map2d[y][x] == '1')
					printf("%d", i);
				else
					if(map->map2d[y][x] == '.')
						printf(".");
					else
						printf("%c", map->map2d[y][x]);
			}
			else
			{
				if (map->map2d[y][x] == '1')
					printf("2");
				else
					printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
}
