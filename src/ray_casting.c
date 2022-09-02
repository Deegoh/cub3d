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

// if you want to display the fov in the minimap,
// we should use my_put_pixel in a separate function after the raycasting
void	get_all_rays(t_data *data)
{
	int		i;
	float	angle;
	float	angle_diff;

	i = 0;
	angle_diff = (60. / (float)SCREENWIDTH);
	angle = data->p->angle / (M_PI / 180.) - 30.;
	if (angle < 0.)
		angle += 360;
	while (i < SCREENWIDTH)
	{
		angle += angle_diff;
		if (angle >= 360)
			angle = 0. + (angle - 360);
		select_ray(data, angle * (M_PI / 180.), &(data->ray[i]));
		i++;
	}
}
// code to display the fov on the minimap
// if (data->is_minimap)
// 	draw_line(data->ray[i].x * data->map->tile_draw_size
// 		/ data->map->tile_size, data->ray[i].y * data->map->tile_draw_size
// 		/ data->map->tile_size, data, make_trgb(100, 255, 0, 0));

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
	while (i < size)
	{
		if (data->ray[j].side == -1 && j > SCREENWIDTH / 2)
			data->ray[j].side = data->ray[j - 10].side;
		else if (data->ray[j].side == -1 && j < SCREENWIDTH / 2)
			data->ray[j].side = data->ray[j + 10].side;
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
	while (i >= 0)
	{	
		display_ray(data, x, i);
		x++;
		i--;
	}
}
