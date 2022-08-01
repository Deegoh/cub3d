/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:35:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/01 23:17:55 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_arr(char **arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_map(t_map *map)
{
	free(map->map);
	free(map->w_no);
	free(map->w_so);
	free(map->w_we);
	free(map->w_ea);
	free_arr(map->map2d, map->nbr_line);
}

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	free(data->p);
	free(data->ray);
	while (i < 5)
	{
		mlx_destroy_image(data->mlx->mlx, data->t[i].img);
		i++;
	}
	free(data->t);
}
