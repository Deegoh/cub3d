/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:42 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/01 23:23:11 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO quand un fichier de texture ne s'ouvre pas exit error
void	err_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	exit_cub(t_data *data)
{
	free_all(data);
	free_map(data->map);
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	free(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}
