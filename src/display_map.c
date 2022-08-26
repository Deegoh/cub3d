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

void	update_image(t_data *data)
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

void	display_player(t_data *data)
{
	put_rectangle(data->map->tile_draw_size * 7,
		data->map->tile_draw_size * 7, data, make_trgb(0, 6, 92, 204));
}

void	put_background(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREENHEIGHT)
	{
		j = 0;
		while (j < SCREENWIDTH)
		{
			if (i < SCREENHEIGHT / 2 - data->pov_y)
				my_mlx_pixel_put(data->mlx, j, i, data->map->ceiling);
			else
				my_mlx_pixel_put(data->mlx, j, i, data->map->floor);
			j++;
		}
		i++;
	}
}
