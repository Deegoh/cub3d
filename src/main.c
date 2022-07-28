/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybentaye <ybentaye@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/28 18:39:20 by ybentaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		err_msg(ERR_USAGE);
	data = malloc(sizeof(t_data));
	init_data(data, av);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, SCREENWIDTH, SCREENHEIGHT, "Hello cub3D");
	// print_info_map(data->map);
	// print_map2d(data->map);
	display_map(data);
	mlx_hook(data->mlx->mlx_win, 2, 1, key_hook, data);
	mlx_loop(data->mlx->mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
