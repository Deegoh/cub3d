/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:59 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/11 17:51:45 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_data *data)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	ray = select_ray(data, data->p->angle, ray);
	
	if (ray->side == 'D' && ray->delta < data->map->tile_size)
	{
		data->map->map2d[(int)floor(ray->y / data->map->tile_size)]
			[(int)floor(ray->x / data->map->tile_size)] = '0';

		update_image(data);
	}
	free(ray);
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_LEFT_L || key == KEY_RIGHT_L)
		update_angle(key, data);
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D
		|| key == KEY_W_L || key == KEY_A_L || key == KEY_S_L || key == KEY_D_L)
		update_position(key, data);
	if (key == KEY_ESC || key == KEY_ESC_L)
		exit_cub(data);
	if (key == 46)
	{
		if (data->is_minimap)
			data->is_minimap = 0;
		else
			data->is_minimap = 1;
		display_map(data);
	}
	if (key == 49)
	{
		if (data->is_mouse)
			data->is_mouse = 0;
		else
			data->is_mouse = 1;
	}
	if (key == 31)
	{
		open_door(data);
	}
	return (0);
}

void	decrease_or_increase_angle(t_data *data, int increase, int x)
{
	if (increase)
	{
		data->p->angle += 0.03;
		if (data->p->angle == 360. * (M_PI / 180))
			data->p->angle = 0.;
		if (data->p->angle > 360. * (M_PI / 180))
			data->p->angle = 0. + (data->p->angle - 2 * M_PI);
		data->prev_x = x;
	}
	else
	{
		data->p->angle -= 0.03;
		if (data->p->angle == 0.)
			data->p->angle = 360. * (M_PI / 180);
		if (data->p->angle < 0.)
			data->p->angle = 2 * M_PI - (data->p->angle * -1);
		data->prev_x = x;
	}
}

int	mouse_hook(int x, int y, t_data *data)
{
	int	diff_x;

	if (data->is_mouse)
	{	
		if (y < SCREENHEIGHT && y > 0)
			data->pov_y = y - SCREENHEIGHT / 2;
		diff_x = data->prev_x - x;
		if (x <= 0)
			mlx_mouse_move(data->mlx->mlx_win, SCREENWIDTH, y);
		if (x >= SCREENWIDTH)
			mlx_mouse_move(data->mlx->mlx_win, 0, y);
		if (y <= 0)
			mlx_mouse_move(data->mlx->mlx_win, x, 0);
		if (y >= SCREENHEIGHT)
			mlx_mouse_move(data->mlx->mlx_win, x, SCREENHEIGHT);
		if (x > 0 && x < SCREENWIDTH && y < SCREENHEIGHT && y > 0)
		{
			if (x < data->prev_x && abs(diff_x) > 3)
				decrease_or_increase_angle(data, 1, x);
			else if (abs(diff_x) > 3)
				decrease_or_increase_angle(data, 0, x);
			update_image(data);
		}
	}
	return (0);
}
