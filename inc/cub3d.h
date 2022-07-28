/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:01:27 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/24 18:01:27 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define SCREENWIDTH 1200
# define SCREENHEIGHT 1200
# define EXT ".cub"
# define IS_SPACE " \n\t\v\f\r"
# define PLAYER "NSWE"
//TODO check D for bonus
# ifndef IS_MAP
#  define IS_MAP "01NSWED"
# endif
# define ERR_USAGE "Error\nUsage: ./cub3D map.cub\n"
# define ERR_FILE "Error\nWrong file\n"
# define ERR_FD "Error\nFile not found\n"
# define ERR_COLOR "Error\nWrong color\n"
# define ERR_MALLOC "Error\nCannot allocate memory\n"
# define ERR_MAP_CLOSE "Error\nMap not closed\n"
# define ERR_MAP_CONTENT "Error\nInvalid content map\n"
# define ERR_MAP_SIZE "Error\nInvalid size map\n"
# define ERR_MAP_PLAYER "Error\nInvalid player map\n"

typedef struct s_map
{
	char	*map;
	char	**map2d;
	char	*w_no;
	char	*w_so;
	char	*w_we;
	char	*w_ea;
	int		floor;
	int		ceiling;
	int		nbr_line;
	int		len_line;
	int		tile_size;
}t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_mlx;

typedef struct s_player{
	int		initiated;
	float	x;
	float	y;
	float	d_x;
	float	d_y;
	float	angle;
}			t_player;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*p;
}			t_data;

// error.c
void	err_msg(char *str);

// parse.c
void	parse_map(t_map *map, char **av);

// free.c
void	free_all(t_data *data);
void	free_arr(char	**arr);

// map.c

// map_utils.c
int		get_elems(t_map *map);
int		is_map(char c);

// checker_map.c
void	check_ext(char *path);
int		is_color(int one_color);
void	check_map2d(t_map *map);

// test.c
void	print_map2d(t_map *map);
void	print_info_map(t_map *map);

// draw.c
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	put_rectangle(int x, int y, t_data *data, int color);
void	put_grid(t_data *data);
int		make_trgb(int t, int r, int g, int b);
void	draw_line(int x2, int y2, t_data *data);

// player .c
void	get_player_pos(t_data *data);
int		is_player(char c);
void	display_player(t_data *data);
void	display_angle(t_data *data);
void	update_angle(int key, t_data *data);
void	update_position(int key, t_data *data);

// init.c
int		init_data(t_data *data, char **av);

// display_map.c
void	display_map(t_data *data);

// key_hook.c
int		key_hook(int key, t_data *data);

#endif