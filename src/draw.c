/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:49 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/26 18:50:05 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_rectangle(int x, int y, t_data *data, int color)
{
	int	i;
	int	j;
	int	size;

	size = data->map->tile_size;
	if (color == 16776960)
		size = data->map->tile_size / 10;
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

void plot_line_low(int x2, int y2, t_data *data)
{
	int	dx;
	int	dy;
	int	D;
	int	x;
	int	y;
	int	s;

	dx = x2 - data->p->x;
	dy = y2 - data->p->y;
	s = 1;
	if (dy < 0)
	{
		s = -1;
		dy *= -1;
	}
	D = (2 * dy) - dx;
	y = data->p->y;
	x = data->p->x;
	while (x <= x2)
	{
		my_mlx_pixel_put(data->mlx, x, y, make_trgb(0, 255, 0, 0));
		if (D > 0)
		{
			y += s;
			D += 2 * (dy - dx);
		}
		else
			D += 2 * dy;
		x++;
	}
}

void	draw_line(int x2, int y2, t_data *data)
{
	double	pixel_x;
	double	pixel_y;
	double	delta_x;
	double	delta_y;
	int		pixels;

	delta_x = (double)x2 - data->p->x;
	delta_y = (double)y2 - data->p->y;
	pixels = sqrt((delta_x * delta_x) +(delta_y * delta_y));
	pixel_x = data->p->x;
	pixel_y = data->p->y;
	delta_x /= pixels;
	delta_y /= pixels;
	while (pixels)
	{
		my_mlx_pixel_put(data->mlx, pixel_x, pixel_y, make_trgb(0, 255, 0, 0));
		pixel_x += delta_x;
		pixel_y += delta_y;
		pixels--;
	}
}