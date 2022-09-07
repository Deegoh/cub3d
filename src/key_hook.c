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
	if (data->hud.sign && !data->hud.is_animated)
	{
		data->hud.y -= 1;
		if (data->hud.y < -10)
			data->hud.sign = ft_bool(data->hud.sign);
	}
	else if (!data->hud.sign && !data->hud.is_animated)
	{
		data->hud.y += 1;
		if (data->hud.y > 10)
			data->hud.sign = ft_bool(data->hud.sign);
	}
}

void	anim_schlass(t_data *data)
{
	if (!data->hud.is_animated)
	{
		data->last_frame = data->frame;
		data->hud.is_animated = 1;
		data->hud.y -= 100;
		data->hud.x -= 100;
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
	else if (key == KEY_E)
		open_door(data);
	else if (key == KEY_H)
		data->hud.is_hud = ft_bool(data->hud.is_hud);
	else if (key == KEY_SPACE)
		anim_schlass(data);
	return (0);
}
