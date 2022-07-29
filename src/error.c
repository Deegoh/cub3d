/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:42 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/29 06:53:30 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	exit_cub(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->mlx_win);
	exit(EXIT_SUCCESS);
}
