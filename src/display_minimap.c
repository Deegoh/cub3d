/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_minimap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:22:22 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/24 12:22:25 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_grid(t_grid *grid, t_data *data)
{
	grid->size = data->map->tile_draw_size;
	grid->p_x = floor(data->p->x / data->map->tile_size);
	grid->p_y = floor(data->p->y / data->map->tile_size);
	grid->i = grid->p_y - 5;
	grid->k = 0;
}

void	put_rectangles(t_grid *grid, t_data *data)
{
	int	x;
	int	y;

	x = grid->l * grid->size + (data->map->tile_draw_size * 2);
	y = grid->k * grid->size + (data->map->tile_draw_size * 2);
	if (grid->i < 0 || grid->j < 0 || grid->i > data->map->nbr_line - 1
		|| grid->j > data->map->len_line - 1)
		put_rectangle(x, y, data, make_trgb(180, 230, 230, 230));
	else if (data->map->map2d[grid->i][grid->j] == '1'
		|| data->map->map2d[grid->i][grid->j] == '.')
		put_rectangle(x, y, data, make_trgb(100, 76, 0, 253));
	else if (data->map->map2d[grid->i][grid->j] == '0'
		|| is_player(data->map->map2d[grid->i][grid->j]))
		put_rectangle(x, y, data, make_trgb(100, 178, 102, 255));
	else if (data->map->map2d[grid->i][grid->j] == 'O'
		|| is_player(data->map->map2d[grid->i][grid->j])
		|| data->map->map2d[grid->i][grid->j] == 'D')
		put_rectangle(x, y, data, make_trgb(100, 51, 153, 255));
}

void	put_grid2(t_data *data)
{
	t_grid	grid;

	init_grid(&grid, data);
	while (grid.i < grid.p_y + 6)
	{
		grid.j = grid.p_x - 5;
		grid.l = 0;
		while (grid.j < grid.p_x + 6)
		{
			put_rectangles(&grid, data);
			grid.j++;
			grid.l++;
		}
		grid.k++;
		grid.i++;
	}
}

//void	put_grid(t_data *data)
//{
//	int	i;
//	int	j;
//	int	size;
//
//	i = -1;
//	size = data->map->tile_draw_size;
//	while (++i < data->map->nbr_line)
//	{
//		j = -1;
//		while (++j < data->map->len_line)
//		{
//			if (data->map->map2d[i][j] == '1')
//				put_rectangle(j * size + (data->map->tile_draw_size * 5),
//					i * size + (data->map->tile_draw_size * 5), data, 6316128);
//			else if (data->map->map2d[i][j] == '0'
//					|| is_player(data->map->map2d[i][j]))
//				put_rectangle(j * size + (data->map->tile_draw_size * 5),
//					i * size + (data->map->tile_draw_size * 5), data, 26316);
//			else if (data->map->map2d[i][j] == '.')
//				put_rectangle(j * size + (data->map->tile_draw_size * 5),
//					i * size + (data->map->tile_draw_size * 5), data, 10526880);
//			else if (data->map->map2d[i][j] == 'D')
//				put_rectangle(j * size + (data->map->tile_draw_size * 5),
//					i * size + (data->map->tile_draw_size * 5), data, 39244);
//		}
//	}
//}
