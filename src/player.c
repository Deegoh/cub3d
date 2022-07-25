/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:20:05 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/26 01:06:22 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'W' 
		|| c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	player_start(char c, int x, int y, t_data *data)
{
	int mid;

	mid = data->map->tile_size / 2;
	if (c == 'N')
		data->p->angle = 90. * (M_PI / 180.0);
	else if(c == 'W')
		data->p->angle =  180. * (M_PI / 180.0);
	else if(c == 'E')
		data->p->angle = 0. * (M_PI / 180.0);
	else if(c == 'S')
		data->p->angle = 270. * (M_PI / 180.0);
	else
		return (0);
	data->p->x = (float)(x * data->map->tile_size + mid);
	data->p->y = (float)(y * data->map->tile_size + mid);
	return (1);
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (data->p->initiated == 1)
		return;
	while (i < data->map->nbr_line)
	{
		j = 0;
		while (j < data->map->len_line)
		{
			if (player_start(data->map->map2d[i][j], j, i, data))
			{
				data->p->initiated = 1;
				printf("\n%f %f %f\n", data->p->x, data->p->y, data->p->angle);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	display_angle(t_data *data)
{
	int x2;
	int y2;
	int size;

	printf("%d\n", make_trgb(0, 255, 0, 0));
	size = (int)data->map->tile_size / 3;
	x2 = data->p->x + (int)((float)cos((double)data->p->angle) * size);
	y2 = data->p->y - (int)((float)sin((double)data->p->angle) * size);
	my_mlx_pixel_put(data->mlx, x2, y2, make_trgb(0, 255, 0, 0));
}

void	update_angle(int key, t_data *data)
{
	if (key == 123)
	{
		data->p->angle += 0.1;
		if (data->p->angle >= 360. * (M_PI / 180))
			data->p->angle = 0.;
	}
	if (key == 124)
	{
		data->p->angle -= 0.1;
		if (data->p->angle <= 0.)
			data->p->angle = 360. * (M_PI / 180);
	}
	display_map(data);
}

void	update_position(int key, t_data *data)
{
	int		speed;
	//float	tmp_angle;

	speed = (int)data->map->tile_size / 9;
	if (key == 13)
	{
		printf("ici\n");
		data->p->d_x = data->p->x + (int)((float)cos((double)data->p->angle) * speed);
		data->p->d_y = data->p->y - (int)((float)sin((double)data->p->angle) * speed);
	}
	data->p->x = data->p->d_x;
 	data->p->y =  data->p->d_y;
	display_map(data);
}