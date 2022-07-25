#include "cub3d.h"

void	put_grid(t_data *data)
{
	int	i;
	int	j;
	int size;

	i = 0;
	size = data->map->tile_size;
	while (i < data->map->nbr_line)
	{
		j = 0;
		while (j < data->map->len_line)
		{
			if (data->map->map2d[i][j] == '1')
				put_rectangle(j * size, i * size, data, 6316128);
			else if (data->map->map2d[i][j] == '0' || is_player(data->map->map2d[i][j]))
				put_rectangle(j * size, i * size, data, 26316);
			else if (data->map->map2d[i][j] == '.')
				put_rectangle(j * size, i * size, data, 10526880);
			j++;
		}
		i++;
	}
}

void	display_player(t_data *data)
{
	put_rectangle(data->p->x, data->p->y, data, 16776960);
	display_angle(data);
}

void	display_map(t_data *data)
{
	put_grid(data);
	display_player(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->mlx_win, data->mlx->img, 0, 0);
}