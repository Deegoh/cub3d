/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:18:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/01 20:00:31 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	get_texture_color(t_data *data, t_ray *ray, int x, int y)
// {
// 	if (ray->ver_hor == 1)
// 	{
// 		if (ray->side == 'N')
// 		{
			
// 		}
// 	}
// 	else if (ray->ver_hor == 0)
// 	{
// 		if (ray->side == 'N')
// 		{
			
// 		}
// 	}
// }

void	display_ray(t_data *data, int x, int j)
{
	float 	distance;
	int		size;
	int		i;
	int		color;

	i = 0;
	distance = data->ray[j].delta * cos(data->ray->relative_angle);
	size = data->map->tile_size / distance * 255;
	// size = (SCREENHEIGHT / 2 - 1) / (distance / data->map->tile_size + 1);
	if (data->ray[j].side == 'N' || data->ray[j].side == 'S')
		color = make_trgb(0, 153, 0, 153);
	else if (data->ray[j].side == 'D')
		color = make_trgb(0, 102, 255, 178);
	else
		color = make_trgb(0, 255, 153, 255);
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