/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:59 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/13 00:08:00 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_door(t_data *data)
{
	float	x2;
	float	y2;
	char	c;
	float	size;

	size = data->map->tile_size / 1.;
	x2 = (data->p->x + size * cos(data->p->angle)) / data->map->tile_size ;
	y2 = (data->p->y - size * sin(data->p->angle)) / data->map->tile_size;
	c = data->map->map2d[(int)floor(y2)][(int)floor(x2)];
	if (c == 'D')
	{
		data->map->map2d[(int)floor(y2)][(int)floor(x2)] = 'O';
	}
	else if (c == 'O')
	{
		data->map->map2d[(int)floor(y2)][(int)floor(x2)] = 'D';
	}
}

void	update_hud(t_data *data)
{
	if (data->hud.sign)
	{
		data->hud.anim -= 1;
		if (data->hud.anim < -10)
			data->hud.sign = ft_bool(data->hud.sign);
	}
	else
	{
		data->hud.anim += 1;
		if (data->hud.anim > 10)
			data->hud.sign = ft_bool(data->hud.sign);
	}
}

int	key_hook(int key, t_data *data)
{
	if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_LEFT_L || key == KEY_RIGHT_L)
		update_angle(key, data);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D
		|| key == KEY_W_L || key == KEY_A_L || key == KEY_S_L || key == KEY_D_L)
	{
		update_position(key, data);
		update_hud(data);
	}
	else if (key == KEY_ESC || key == KEY_ESC_L)
		exit_cub(data);
	else if (key == KEY_M)
		data->is_minimap = ft_bool(data->is_minimap);
	else if (key == KEY_N)
		data->is_mouse = ft_bool(data->is_mouse);
	else if (key == KEY_O)
		open_door(data);
	else if (key == KEY_H)
		data->hud.is_hud = ft_bool(data->hud.is_hud);
	return (0);
}

void	decrease_or_increase_angle(t_data *data, int increase, int x)
{
	if (increase)
	{
		data->p->angle += 0.03;
		if (data->p->angle == degree_to_rad(360))
			data->p->angle = 0.;
		if (data->p->angle > degree_to_rad(360))
			data->p->angle = 0. + (data->p->angle - 2 * M_PI);
		data->prev_x = x;
	}
	else
	{
		data->p->angle -= 0.03;
		if (data->p->angle == 0.)
			data->p->angle = degree_to_rad(360);
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
		}
	}
	return (0);
}
