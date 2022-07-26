/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 10:59:54 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/24 18:02:42 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_img_to_window(t_data mlx, char*path, int x, int y)
{
	int	img_width;
	int	img_height;

	mlx.img = mlx_xpm_file_to_image(mlx.mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, x, y);
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		err_msg(ERR_USAGE);
	parse_map(&map, av);
	print_info_map(&map);
	print_map2d(&map);
	free_all(&map);
	return (EXIT_SUCCESS);
}
//	t_data	mlx;
//	mlx.mlx = mlx_init();
//	mlx.mlx_win = mlx_new_window(mlx.mlx, 128, 128, "Hello cub3D");
//	mlx.img = mlx_new_image(mlx.mlx, 128, 128);
//	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
//								 &mlx.endian);
//	put_img_to_window(mlx, "map/texture/wall1.xpm", 0, 0);
//	put_img_to_window(mlx, "map/texture/wall_b1.xpm", 64, 0);
//	put_img_to_window(mlx, "map/texture/wall_d1.xpm", 0, 64);
//	put_img_to_window(mlx, "map/texture/wall_p1.xpm", 64, 64);
//	mlx_loop(mlx.mlx);
