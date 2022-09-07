/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:33:21 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/09/04 18:33:23 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	decrease_or_increase_angle(t_data *data, int increase, int x, int diff)
{
	if (increase)
	{
		data->p->angle += (0.03 * ft_abs(diff) / 10);
		if (data->p->angle == degree_to_rad(360))
			data->p->angle = 0.;
		if (data->p->angle > degree_to_rad(360))
			data->p->angle = 0. + (data->p->angle - 2 * M_PI);
		data->prev_x = x;
	}
	else
	{
		data->p->angle -= (0.03 * ft_abs(diff) / 10);
		if (data->p->angle == 0.)
			data->p->angle = degree_to_rad(360);
		if (data->p->angle < 0.)
			data->p->angle = 2 * M_PI - (data->p->angle * -1);
		data->prev_x = x;
	}
}

void	mouse_checker(t_data *data, int x, int y)
{
	if (y < SCREENHEIGHT && y > 0)
		data->pov_y = y - SCREENHEIGHT / 2;
	if (x < 0)
	{
		data->prev_x = SCREENWIDTH + 1;
		mlx_mouse_move(data->mlx->mlx_win, SCREENWIDTH, y);
	}
	if (x > SCREENWIDTH)
	{
		data->prev_x = -1;
		mlx_mouse_move(data->mlx->mlx_win, 0, y);
	}
	if (y < -30)
		mlx_mouse_move(data->mlx->mlx_win, x, -30);
	if (y > SCREENHEIGHT)
		mlx_mouse_move(data->mlx->mlx_win, x, SCREENHEIGHT);
}

int	mouse_hook(int x, int y, t_data *data)
{
	if (data->is_mouse)
	{
		mouse_checker(data, x, y);
		if (x > 0 && x < SCREENWIDTH && y < SCREENHEIGHT && y > 0)
		{
			if (x < data->prev_x && abs(data->prev_x - x) >= 1)
				decrease_or_increase_angle(data, 1, x, abs(data->prev_x - x));
			else if (abs(data->prev_x - x) >= 1)
				decrease_or_increase_angle(data, 0, x, abs(data->prev_x - x));
		}
	}
	return (0);
}

int	keymouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 1 && x >= 0 && y >= 0
		&& x <= SCREENWIDTH && y <= SCREENHEIGHT)
		anim_schlass(data);
	return (0);
}
