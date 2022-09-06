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

int	ft_loop_hook(t_data	*data)
{
	mlx_clear_window(data->mlx->mlx, data->mlx->mlx_win);
	update_image(data);
	data->frame = (data->frame + 1) % 1000000000;
	if (data->hud.is_animated && ft_abs(data->last_frame + data->frame) >= 200)
	{
		data->hud.y += 100;
		data->hud.x += 100;
		data->hud.is_animated = 0;
	}
	return (0);
}

void	put_hud(t_data *data)
{
	data->hud.img = mlx_xpm_file_to_image(data->mlx->mlx, IMG_KNIFE,
			&data->hud.width, &data->hud.height);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->hud.img, (SCREENWIDTH - data->hud.width) / 4 * 3 + data->hud.x,
		SCREENHEIGHT - data->hud.height + data->hud.y + 15);
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

void	update_image(t_data *data)
{
	put_background(data);
	get_all_rays(data);
	display_rays(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
	if (data->is_minimap)
	{
		put_grid2(data);
		display_player(data);
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win,
		data->mlx->img, 0, 0);
	if (data->hud.is_hud)
		put_hud(data);
}

void	display_player(t_data *data)
{
	put_rectangle(data->map->tile_draw_size * 7,
		data->map->tile_draw_size * 7, data, make_trgb(50, 6, 92, 204));
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
