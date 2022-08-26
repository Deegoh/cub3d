/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 19:18:50 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/13 00:42:27 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	choose_texture(t_data *data, t_ray *ray, int y, int size)
{
	int	s;
	int	color;

	if (ray->side == 'N')
		s = 0;
	if (ray->side == 'S')
		s = 1;
	if (ray->side == 'E')
		s = 2;
	if (ray->side == 'W')
		s = 3;
	if (ray->side == 'D')
		s = 4;
	if (ray->ver_hor == 0)
		color = (my_mlx_pixel_get(&data->t[s],
					floor(((int)ray->x % data->map->tile_size)
						* data->t[s].width / data->map->tile_size),
					floor(y * data->t[s].height / size)));
	if (ray->ver_hor == 1)
		color = (my_mlx_pixel_get(&data->t[s],
					floor(((int)ray->y % data->map->tile_size)
						* data->t[s].width / data->map->tile_size),
					floor(y * data->t[s].height / size)));
	return (color);
}

void	display_ray(t_data *data, int x, int j)
{
	float	distance;
	int		size;
	int		i;
	int		color;

	i = 0;
	distance = data->ray[j].delta * cos(data->ray[j].relative_angle);
	size = data->map->tile_size / distance * 512;
	if (data->ray[j].side == 'N' || data->ray[j].side == 'S')
		color = make_trgb(0, 153, 0, 153);
	else if (data->ray[j].side == 'D')
		color = make_trgb(0, 102, 255, 178);
	else
		color = make_trgb(0, 255, 153, 255);
	while (i < size)
	{
		color = choose_texture(data, &data->ray[j], size + i, size * 2);
		my_mlx_pixel_put(data->mlx, x,
			SCREENHEIGHT / 2 + i - data->pov_y, color);
		color = choose_texture(data, &data->ray[j], size - i, size * 2);
		my_mlx_pixel_put(data->mlx, x,
			SCREENHEIGHT / 2 - i - data->pov_y, color);
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
