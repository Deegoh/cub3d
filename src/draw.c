/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:49 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/26 16:36:35 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_img_to_window(t_mlx mlx, char*path, int x, int y)
{
	int	img_width;
	int	img_height;

	mlx.img = mlx_xpm_file_to_image(mlx.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, x, y);
}

void	put_rectangle(int x, int y, t_data *data, int color)
{
	int i;
	int j;
	int size;

	size = data->map->tile_size;
	if (color == 16776960)
		size = data->map->tile_size / 10;
	i = y;
	while (i < size + y)
	{
		j = x;
		while(j < size + x)
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
