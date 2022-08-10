/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:49 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/03 22:10:58 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if ((0 < x && x < SCREENWIDTH) && (0 < y && y < SCREENHEIGHT))
	{
		dst = mlx->addr + (y * mlx->line_length
				+ x * (mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	my_mlx_pixel_get(t_texture *texture, int x, int y)
{
	unsigned int	color;

	color = 0;
	if ((0 <= x && x <= texture->width) && (0 <= y && y <= texture->height))
	{
		color = texture->addr[y * texture->len_line / 4 + x];
	}
	return (color);
}

void	put_rectangle(int x, int y, t_data *data, int color)
{
	int	i;
	int	j;
	int	size;

	size = data->map->tile_draw_size;
	if (color == 16776960)
		size = data->map->tile_draw_size / 5;
	i = y;
	while (i < size + y)
	{
		j = x;
		while (j < size + x)
		{
			my_mlx_pixel_put(data->mlx, j, i, color);
			j++;
		}
		i++;
	}
}

int	make_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_line(int x2, int y2, t_data *data, int color)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - data->p->x / data->map->tile_size
		* data->map->tile_draw_size;
	delta_y = (double)y2 - data->p->y / data->map->tile_size
		* data->map->tile_draw_size;
	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
	pixel_x = data->p->x / data->map->tile_size * data->map->tile_draw_size;
	pixel_y = data->p->y / data->map->tile_size * data->map->tile_draw_size;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(data->mlx, pixel_x, pixel_y, color);
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}
