/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/26 01:18:43 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac != 2)
		err_msg(ERR_USAGE);
//<<<<<<< dispay_map
	data = malloc(sizeof(t_data));
	init_data(data, av);
	data->mlx->mlx_win = mlx_new_window(data->mlx->mlx, screenWidth, screeHeight, "Hello cub3D");
	display_map(data);
	mlx_hook(data->mlx->mlx_win, 2, 1, key_hook, data);
	mlx_loop(data->mlx->mlx);
	free_all(data->map);
	return (EXIT_SUCCESS);
}

//=======
//	parse_map(&map, av);
//	print_info_map(&map);
//	print_map2d(&map);
//	free_all(&map);
//	return (EXIT_SUCCESS);
//}
//	t_data	mlx;
//	mlx.mlx = mlx_init();
//	mlx.mlx_win = mlx_new_window(mlx.mlx, 128, 128, "Hello cub3D");
//	mlx.img = mlx_new_image(mlx.mlx, 128, 128);
//	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
//								 &mlx.endian);
//>>>>>>> main
//	put_img_to_window(mlx, "map/texture/wall1.xpm", 0, 0);
//	put_img_to_window(mlx, "map/texture/wall_b1.xpm", 64, 0);
//	put_img_to_window(mlx, "map/texture/wall_d1.xpm", 0, 64);
//	put_img_to_window(mlx, "map/texture/wall_p1.xpm", 64, 64);
//<<<<<<< dispay_map
//=======
//	mlx_loop(mlx.mlx);
//>>>>>>> main
