/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 00:01:26 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/13 00:41:10 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_collision(t_data *data, int col_x, int col_y)
{
	if (data->map->map2d[(int)floor(col_y / data->map->tile_size)]
		[(int)floor(col_x / data->map->tile_size)] != '1')
	{
		if (data->map->map2d[(int)floor(col_y / data->map->tile_size)]
			[(int)floor(col_x / data->map->tile_size)] != 'D')
		{
			data->p->x = data->p->d_x;
			data->p->y = data->p->d_y;
		}
	}
}

void	choose_direction(t_data *data, int key, float speed)
{
	float			tmp_angle;
	float			col_x;
	float			col_y;

	if (key == KEY_D || key == KEY_D_L)
		tmp_angle = data->p->angle + 180. * (M_PI / 180.0);
	if (key == KEY_A || key == KEY_A_L)
		tmp_angle = data->p->angle + 90. * (M_PI / 180.0);
	if (key == KEY_S || key == KEY_S_L)
		tmp_angle = data->p->angle - 90. * (M_PI / 180.0);
	if (key == KEY_W || key == KEY_W_L)
		tmp_angle = data->p->angle;
	data->p->d_x = data->p->x + (int)((float)cos((double)tmp_angle) * speed);
	data->p->d_y = data->p->y - (int)((float)sin((double)tmp_angle) * speed);
	col_x = data->p->x + (int)((float)cos((double)tmp_angle) * (speed * 3.8));
	col_y = data->p->y - (int)((float)sin((double)tmp_angle) * (speed * 3.8));
	check_collision(data, col_x, col_y);
}

void	update_position(int key, t_data *data)
{
	float	speed;

	speed = (int)data->map->tile_size / 7;
	choose_direction(data, key, speed);
	display_map(data);
}
