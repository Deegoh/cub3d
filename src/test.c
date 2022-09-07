/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 12:26:33 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/26 12:26:38 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info_map(t_map *map)
{
	printf("w_no[%s]\n", map->w_no);
	printf("w_so[%s]\n", map->w_so);
	printf("w_we[%s]\n", map->w_we);
	printf("w_ea[%s]\n", map->w_ea);
	printf("floor[%d]\n", map->floor);
	printf("ceiling[%d]\n", map->ceiling);
}

void	print_map2d(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			printf("%c", map->map2d[y][x]);
		}
		printf("\n");
	}
}

//void	put_grid(t_data *data)
//{
//	int	i;
//	int	j;
//	int	size;
//
//	i = 0;
//	size = data->map->tile_draw_size;
//	while (i < data->map->nbr_line)
//	{
//		j = 0;
//		while (j < data->map->len_line)
//		{
//			if (data->map->map2d[i][j] == '1')
//				put_rectangle(j * size, i * size, data, 6316128);
//			else if (data->map->map2d[i][j] == '0'
//					|| is_player(data->map->map2d[i][j]))
//				put_rectangle(j * size, i * size, data, 26316);
//			else if (data->map->map2d[i][j] == '.')
//				put_rectangle(j * size, i * size, data, 10526880);
//			else if (data->map->map2d[i][j] == 'D')
//				put_rectangle(j * size, i * size, data, 39244);
//			j++;
//		}
//		i++;
//	}
//}
