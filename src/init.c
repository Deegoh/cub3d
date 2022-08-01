/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:56 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/01 22:16:35 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_data *data)
{
	int	width;
	int	height;
	int	i;

	width = 100;
	height = 100;
	i = 0;
	data->t[0].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_no, &width, &height);
	data->t[1].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_so, &width, &height);
	data->t[2].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_ea, &width, &height);
	data->t[3].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_we, &width, &height);
	data->t[4].img = mlx_xpm_file_to_image(data->mlx->mlx,
			"./map/texture/Plank3_Light.xpm", &width, &height);
	while (i < 5)
	{
		if (!data->t[i].img)
			return (0);
		data->t[i].addr = (int *)mlx_get_data_addr(data->t[i].img,
				&data->t[0].bits_nb, &data->t[i].len_line, &data->t[i].endien);
			i++;
	}
	return (1);
}

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
	data->t = malloc(sizeof(t_texture) * 6);
	if (!data->t)
		err_msg(ERR_MALLOC);
	data->ray = ft_calloc(SCREENWIDTH + 1, sizeof(t_ray));
	if (!data->ray)
		err_msg(ERR_MALLOC);
	data->mlx->mlx = mlx_init();
	data->mlx->img = mlx_new_image(data->mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bits_per_pixel,
			&data->mlx->line_length, &data->mlx->endian);
	parse_map(data->map, av);
	init_texture(data);
	get_player_pos(data);
	return (1);
}
