/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:18:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/31 20:53:16 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_ray(t_data *data, int x, int j)
{
	float 	distance;
	int		size;
	int		i;
	int		color;

	i = 0;
	distance = data->ray[j].delta * cos(data->ray->relative_angle);
	size = (SCREENHEIGHT / 2 - 1) / (distance / data->map->tile_size + 1);
	if (data->ray[x].side == 'N' || data->ray[j].side == 'S')
		color = make_trgb(0, 0, 76, 153);
	else
		color = make_trgb(0, 0, 128, 255);
	while (i < size)
	{
		my_mlx_pixel_put(data->mlx, x, SCREENHEIGHT / 2 + i, color);
		my_mlx_pixel_put(data->mlx, x, SCREENHEIGHT / 2 - i, color);
		i++;
	}
}

void	display_rays(t_data *data)
{
	int	x;
	int	i;

	i = SCREENWIDTH - 1;
	x = 0;
	while (i > 0)
	{	
		display_ray(data, x, i);
		x++;
		i--;
	}
}