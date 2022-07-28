/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:56 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/07/28 18:49:00 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_data(t_data *data, char **av)
{
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		err_msg(ERR_MALLOC);
	data->mlx = malloc(sizeof(t_mlx));
	if (!data->mlx)
		err_msg(ERR_MALLOC);
	data->p = malloc(sizeof(t_player));
	if (!data->p)
		err_msg(ERR_MALLOC);
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		err_msg(ERR_MALLOC);
	data->mlx->mlx = mlx_init();
	data->mlx->img = mlx_new_image(data->mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img, &data->mlx->bits_per_pixel,
			&data->mlx->line_length, &data->mlx->endian);
	parse_map(data->map, av);
	get_player_pos(data);
	return (1);
}
