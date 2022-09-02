/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 00:27:27 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/13 00:49:08 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// if (x >= SCREENWIDTH || y >= SCREENHEIGHT)
	// 	return (1);
//--> the code above does not work but we need another way
// to check high value x and y in order to reduce the lag
int	reach_wall(int x, int y, t_data *data, t_ray *ray)
{
	if (x <= 0 || y <= 0)
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
		else if (data->map->map2d[y / data->map->tile_size]
			[x / data->map->tile_size] == 'O')
			ray->side = 'O';
		else
			ray->side = 0;
		return (1);
	}
	return (0);
}

void	dup_ray(t_ray *ray, t_ray *dup)
{
	dup->x = ray->x;
	dup->y = ray->y;
	dup->delta = ray->delta;
	dup->side = ray->side;
	dup->ver_hor = ray->ver_hor;
	dup->relative_angle = ray->relative_angle;
	dup->angle = ray->angle;
}

t_ray	*select_ray(t_data *data, float angle, t_ray *ray)
{
	int		d_hor;
	int		d_ver;
	t_ray	last_ray;
	t_ray	dup;

	ray->relative_angle = angle - data->p->angle;
	dup_ray(ray, &last_ray);
	get_horizontal_ray(data, ray, angle);
	d_hor = ray->delta;
	dup_ray(ray, &dup);
	get_vertical_ray(data, ray, angle);
	d_ver = ray->delta;
	if (d_hor < d_ver)
	{
		dup_ray(&dup, ray);
	}
	if (ft_abs(d_ver - d_hor) <= 5)
	{
		ray->side = -1;
	}
	return (ray);
}

void	get_vertical_ray(t_data *data, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle > 0 && angle < degree_to_rad(180))
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
	ray->ver_hor = 0;
}

void	get_horizontal_ray(t_data *data, t_ray *ray, float angle)
{
	int	direction;

	direction = 1;
	if (angle <= degree_to_rad(90) || angle >= degree_to_rad(270))
		ray->x = floor(data->p->x / data->map->tile_size)
			* data->map->tile_size + data->map->tile_size;
	else
	{
		ray->x = floor(data->p->x / data->map->tile_size)
			* data->map->tile_size - 1;
		direction = -1;
	}
	ray->y = floor(data->p->y + (data->p->x - ray->x) * tan(angle));
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
	ray->ver_hor = 1;
}
