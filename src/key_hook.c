/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:59 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/03 00:39:05 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}
