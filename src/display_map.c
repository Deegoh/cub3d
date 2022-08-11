/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:29:23 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/11 19:31:40 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_grid2(t_data *data)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	p_x;
	int	p_y;
	int	size;

	size = data->map->tile_draw_size;
	p_x = floor(data->p->x / data->map->tile_size);
	p_y = floor(data->p->y / data->map->tile_size);
	printf("player %d %d\n", p_x, p_y);
	i = p_y - 5;
	k = 0;
	while (i < p_y + 6)
	{
		j = p_x - 5;
		l = 0;
		while (j < p_x + 6)
		{
			if (i < 0 || j < 0 || i > data->map->nbr_line - 1 || j > data->map->len_line - 1)
			{
			printf("outside %d %d\n", i, j);	
				put_rectangle(l * size + (data->map->tile_draw_size * 2), k * size + (data->map->tile_draw_size * 2), data, 10526880);		
			}
			else if (data->map->map2d[i][j] == '1')
				put_rectangle(l * size + (data->map->tile_draw_size * 2), k * size + (data->map->tile_draw_size * 2), data, 6316128);
			else if (data->map->map2d[i][j] == '0' || is_player(data->map->map2d[i][j]))
				put_rectangle(l * size + (data->map->tile_draw_size * 2), k * size + (data->map->tile_draw_size * 2), data, 26316);
			else if (data->map->map2d[i][j] == '.')
				put_rectangle(l * size + (data->map->tile_draw_size * 2), k * size + (data->map->tile_draw_size * 2), data, 10526880);
			else if (data->map->map2d[i][j] == 'D')
				put_rectangle(l * size + (data->map->tile_draw_size * 2), k * size + (data->map->tile_draw_size * 2), data, 39244);
			j++;
			l++;
		}
		k++;
		i++;
	}
}

void	put_grid(t_data *data)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = data->map->tile_draw_size;
	while (i < data->map->nbr_line)
	{
		j = 0;
		while (j < data->map->len_line)
		{
			if (data->map->map2d[i][j] == '1')
				put_rectangle(j * size + (data->map->tile_draw_size * 5), i * size + (data->map->tile_draw_size * 5), data, 6316128);
			else if (data->map->map2d[i][j] == '0' || is_player(data->map->map2d[i][j]))
				put_rectangle(j * size + (data->map->tile_draw_size * 5), i * size + (data->map->tile_draw_size * 5), data, 26316);
			else if (data->map->map2d[i][j] == '.')
				put_rectangle(j * size + (data->map->tile_draw_size * 5), i * size + (data->map->tile_draw_size * 5), data, 10526880);
			else if (data->map->map2d[i][j] == 'D')
				put_rectangle(j * size + (data->map->tile_draw_size * 5), i * size + (data->map->tile_draw_size * 5), data, 39244);
			j++;
		}
		i++;
	}
}

void	display_player(t_data *data)
{
	// put_rectangle(data->p->x / data->map->tile_size * data->map->tile_draw_size
	// 	- data->map->tile_draw_size / 8,
	// 	data->p->y / data->map->tile_size * data->map->tile_draw_size
	// 	- data->map->tile_draw_size / 8, data, 16776960);
	put_rectangle(data->map->tile_draw_size * 7,
		data->map->tile_draw_size * 7, data, make_trgb(0, 255, 200, 0));
	//display_angle(data);
}

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREENHEIGHT / 2 - data->pov_y)
	{
		j = 0;
		while (j < SCREENWIDTH)
		{
			my_mlx_pixel_put(data->mlx, j, i, data->map->ceiling);
			j++;
		}
		i++;
	}
	j = 0;
	while (i < SCREENHEIGHT)
	{
		j = 0;
		while (j < SCREENWIDTH)
		{
			my_mlx_pixel_put(data->mlx, j, i, data->map->floor);
			j++;
		}
		i++;
	}
}

void	display_map(t_data *data)
{
	put_background(data);
	get_all_rays(data);
	display_rays(data);
	if (data->is_minimap)
	{
		put_grid2(data);
		display_player(data);
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
}
