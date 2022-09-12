/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 18:01:27 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/04 01:47:24 by yacinebenta      ###   ########.fr       */
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

//macos
# define KEY_W 13
# define KEY_A 0
# define KEY_S 2
# define KEY_D 1
# define KEY_M 46
# define KEY_N 45
# define KEY_E 14
# define KEY_H 4
# define KEY_SPACE 49
# define KEY_RIGHT 124
# define KEY_LEFT 123
# define KEY_ESC 53
//linux
# define KEY_W_L 119
# define KEY_A_L 97
# define KEY_S_L 115
# define KEY_D_L 100
# define KEY_RIGHT_L 65361
# define KEY_LEFT_L 65363
# define KEY_ESC_L 65307

# define SCREENWIDTH 1400
# define SCREENHEIGHT 900
# define EXT ".cub"
# define IS_SPACE " \n\t\v\f\r"
# define IS_PLAYER "NSWE"
# ifndef IS_MAP
#  define IS_MAP "01NSWE"
# endif
# define IMG_DOOR "./texture/Plank3_Light.xpm"
# define IMG_KNIFE "./texture/knifeX4.xpm"

# define ERR_USAGE "Error\nUsage: ./cub3D map.cub\n"
# define ERR_SCREEN "Error\nInvalid size screen\n"
# define ERR_FILE "Error\nWrong file\n"
# define ERR_FD "Error\nFile not found\n"
# define ERR_COLOR "Error\nWrong color\n"
# define ERR_MALLOC "Error\nCannot allocate memory\n"
# define ERR_TEXTURE "Error\nTexture not found\n"
# define ERR_MAP_INFO "Error\nInvalid map info\n"
# define ERR_MAP_CLOSE "Error\nMap not closed\n"
# define ERR_MAP_CONTENT "Error\nInvalid content map\n"
# define ERR_MAP_SIZE "Error\nInvalid size map\n"
# define ERR_MAP_PLAYER "Error\nInvalid player map\n"

typedef struct s_grid
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	p_x;
	int	p_y;
	int	size;
}t_grid;

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
	int		tile_draw_size;
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
}t_mlx;

typedef struct s_player{
	int			initiated;
	long double	x;
	long double	y;
	long double	d_x;
	long double	d_y;
	long double	angle;
}t_player;

typedef struct s_ray
{
	long double	x;
	long double	y;
	long double	delta;
	char		side;
	int			ver_hor;
	long double	relative_angle;
	float		angle;
}t_ray;

typedef struct s_texture
{
	void	*img;
	int		bits_nb;
	int		len_line;
	int		endien;
	int		*addr;
	int		width;
	int		height;
}t_texture;

typedef struct s_hud
{
	void	*img;
	int		width;
	int		height;
	int		x;
	int		y;
	int		is_hud;
	int		sign;
	int		is_animated;
}t_hud;

typedef struct s_data
{
	t_mlx		*mlx;
	t_map		*map;
	t_player	*p;
	t_ray		*ray;
	t_texture	*t;
	t_hud		hud;
	int			nbr_t;
	int			frame;
	int			last_frame;
	int			is_mouse;
	int			prev_x;
	int			pov_y;
	int			is_minimap;
}t_data;

// error.c
void	err_msg(char *str);
int		exit_cub(t_data *data);

// parse.c
void	parse_map(t_map *map, char **av);

// free.c
void	free_all(t_data *data);
void	free_arr(char	**arr, int len);
void	free_map(t_map *map);

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
int		make_trgb(int t, int r, int g, int b);
void	draw_line(int x2, int y2, t_data *data, int color);
int		my_mlx_pixel_get(t_texture *texture, int x, int y);

// player .c
void	get_player_pos(t_data *data);
int		is_player(char c);
void	display_player(t_data *data);
void	display_angle(t_data *data);
void	update_angle(int key, t_data *data);
void	update_position(int key, t_data *data);
void	get_ray(t_data *data);

// init.c
t_data	*init_data(char **av);

// display_map.c
int		ft_loop_hook(t_data	*data);
void	put_background(t_data *data);
void	update_image(t_data *data);

// key_hook.c
void	update_hud(t_data *data);
int		key_hook(int key, t_data *data);
int		mouse_hook(int x, int y, t_data *data);
void	anim_schlass(t_data *data);
int		keymouse_hook(int button, int x, int y, t_data *data);

// ray.c
void	get_vertical_ray(t_data *data, t_ray *ray, float angle);
void	get_horizontal_ray(t_data *data, t_ray *ray, float angle);
t_ray	*select_ray(t_data *data, float angle, t_ray *ray);
void	get_all_rays(t_data *data);

// ray_tracing.c
void	display_rays(t_data *data);

// display_minimap.c
void	put_grid2(t_data *data);

// math_utils.c
double	rad_to_degree(double rad);
double	degree_to_rad(double degree);
float	precision(double num, int digit);
int		ft_abs(int x);

#endif