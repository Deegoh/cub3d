/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:56 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/26 00:19:57 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_data(t_data *data, char **av)
{
	data->map = malloc(sizeof(t_map));
	data->mlx = malloc(sizeof(t_mlx));
	data->p = malloc(sizeof(t_player));
	data->mlx->mlx = mlx_init();
	data->mlx->img = mlx_new_image(data->mlx->mlx, screenWidth, screeHeight);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel,
										&data->mlx->line_length, &data->mlx->endian);
	parse_map(data->map, av);
	get_player_pos(data);
	return (1);
}