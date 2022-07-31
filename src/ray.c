/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:27:27 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/31 21:36:32 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	reach_wall(int x, int y, t_data *data, t_ray *ray)
{
	if (x <= 0 || y <= 0)
		return (1);
	if (x >= SCREENWIDTH || y >= SCREENHEIGHT)
		return (1);
	if (x / data->map->tile_size > data->map->len_line - 1
		|| y / data->map->tile_size > data->map->nbr_line - 1)
		return (1);
	if (data->map->map2d[y / data->map->tile_size]
		[x / data->map->tile_size] == '1'
		|| data->map->map2d[y / data->map->tile_size]
		[x / data->map->tile_size] == 'D')
	{
		if (data->map->map2d[y / data->map->tile_size]
			[x / data->map->tile_size] == 'D')
			ray->side = 'D';
		else
			ray->side = 0;
		return (1);
	}
	return (0);
}

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
		if (angle > 360)
			angle = 0. + (angle - 360);
		select_ray(data, angle * (M_PI / 180.), &(data->ray[i]));
		if (data->ray[i].side == 'S' || data->ray[i].side == 'N')
			draw_line(data->ray[i].x, data->ray[i].y,
				data, make_trgb(0, 255, 0, 0));
		else
			draw_line(data->ray[i].x, data->ray[i].y,
				data, make_trgb(0, 0, 255, 0));
		i++;
	}
}

t_ray	*select_ray(t_data *data, float angle, t_ray *ray)
{
	int	d_hor;
	int	d_ver;

	d_hor = 0;
	d_ver = 0;
	ray->relative_angle = angle - data->p->angle;
	get_horizontal_ray(data, ray, angle);
	d_hor = ray->delta;
	get_vertical_ray(data, ray, angle);
	d_ver = ray->delta;
	if (d_hor < d_ver)
		get_horizontal_ray(data, ray, angle);
	else
		get_vertical_ray(data, ray, angle);
	return (ray);
}

void	get_vertical_ray(t_data *data, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle < 180. * (M_PI / 180))
		ray->y = floor(data->p->y / data->map->tile_size)
			* data->map->tile_size - 1;
	else
	{
		ray->y = floor(data->p->y / data->map->tile_size)
			* data->map->tile_size + data->map->tile_size;
		direction = -1;
	}
	ray->x = (data->p->y - ray->y) / tan(angle) + data->p->x;
	while (!reach_wall(ray->x, ray->y, data, ray))
	{
		ray->y -= data->map->tile_size * direction;
		ray->x += data->map->tile_size / tan(angle) * direction;
	}
	ray->delta = sqrt(pow(data->p->x - ray->x, 2.)
			+ pow(data->p->y - ray->y, 2.));
	if (direction == 1 && ray->side != 'D')
		ray->side = 'N';
	else if (ray->side != 'D')
		ray->side = 'S';
}

void	get_horizontal_ray(t_data *data, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle < M_PI / 2 || angle > 3 * M_PI / 2)
		ray->x = floor(data->p->x / data->map->tile_size)
			* data->map->tile_size + data->map->tile_size;
	else
	{
		ray->x = floor(data->p->x / data->map->tile_size)
			* data->map->tile_size - 1;
		direction = -1;
	}
	ray->y = data->p->y + (data->p->x - ray->x)
		* tan(angle);
	while (!reach_wall(ray->x, ray->y, data, ray))
	{
		ray->x += data->map->tile_size * direction;
		ray->y -= data->map->tile_size * tan(angle) * direction;
	}
	ray->delta = sqrt(pow(data->p->x - ray->x, 2.)
			+ pow(data->p->y - ray->y, 2.));
	if (direction == 1 && ray->side != 'D')
		ray->side = 'E';
	else if (ray->side != 'D')
		ray->side = 'W';
}
