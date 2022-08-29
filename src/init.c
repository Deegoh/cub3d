/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:19:56 by yacinebenta       #+#    #+#             */
/*   Updated: 2022/08/04 01:29:05 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_texture(t_data *data)
{
	int	i;

	i = -1;
	data->t[0].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_no, &data->t[0].width, &data->t[0].height);
	data->t[1].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_so, &data->t[1].width, &data->t[1].height);
	data->t[2].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_ea, &data->t[2].width, &data->t[2].height);
	data->t[3].img = mlx_xpm_file_to_image(data->mlx->mlx,
			data->map->w_we, &data->t[3].width, &data->t[3].height);
	data->t[4].img = mlx_xpm_file_to_image(data->mlx->mlx, IMG_DOOR,
			&data->t[4].width, &data->t[4].height);
	data->t[5].img = mlx_xpm_file_to_image(data->mlx->mlx, IMG_KNIFE,
			&data->t[5].width, &data->t[5].height);
	while (++i < data->nbr_t)
	{
		if (!data->t[i].img)
			err_msg(ERR_TEXTURE);
		data->t[i].addr = (int *)mlx_get_data_addr(data->t[i].img,
				&data->t[0].bits_nb, &data->t[i].len_line, &data->t[i].endien);
	}
	return (1);
}

void	malloc_data(t_data *data)
{
	data->map = ft_calloc(sizeof(t_map), 1);
	if (!data->map)
		err_msg(ERR_MALLOC);
	data->mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!data->mlx)
		err_msg(ERR_MALLOC);
	data->p = ft_calloc(sizeof(t_player), 1);
	if (!data->p)
		err_msg(ERR_MALLOC);
	data->t = ft_calloc(sizeof(t_texture), data->nbr_t);
	if (!data->t)
		err_msg(ERR_MALLOC);
	data->ray = ft_calloc(SCREENWIDTH, sizeof(t_ray));
	if (!data->ray)
		err_msg(ERR_MALLOC);
}

t_data	*init_data(char **av)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		err_msg(ERR_MALLOC);
	data->is_minimap = 1;
	data->is_mouse = 1;
	data->hud.is_hud = 0;
	data->hud.sign = 0;
	data->nbr_t = 6;
	data->hud.anim = 0;
	malloc_data(data);
	data->mlx->mlx = mlx_init();
	data->mlx->img = mlx_new_image(data->mlx->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->mlx->addr = mlx_get_data_addr(data->mlx->img,
			&data->mlx->bits_per_pixel,
			&data->mlx->line_length, &data->mlx->endian);
	parse_map(data->map, av);
	init_texture(data);
	get_player_pos(data);
	data->prev_x = SCREENWIDTH / 2;
	data->pov_y = 0;
	return (data);
}
