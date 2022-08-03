/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/04 01:45:06 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		err_msg(ERR_USAGE);
	data = malloc(sizeof(t_data));
	data->is_minimap = 1;
	data->is_mouse = 1;
	init_data(data, av);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx,
		SCREENWIDTH, SCREENHEIGHT, "Hello cub3D");
	// print_info_map(data->map);
	// print_map2d(data->map);
	display_map(data);
	mlx_hook(data->mlx->mlx_win, 2, 1, key_hook, data);
	mlx_hook(data->mlx->mlx_win,6 , 1, mouse_hook, data);
	mlx_loop(data->mlx->mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
