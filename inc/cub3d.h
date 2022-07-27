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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

# define EXT ".cub"
# define IS_SPACE " \n\t\v\f\r"
# define IS_SPACE_NO_NL " \t\v\f\r"
# define ERR_USAGE "Error\nUsage: ./cub3D map.cub\n"
# define ERR_FILE "Error\nWrong file\n"
# define ERR_FD "Error\nFile not found\n"
# define ERR_COLOR "Error\nWrong color\n"

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
}t_map;

// error.c
void	err_msg(char *str);

// parse.c
void	parse_map(t_map *map, char **av);

// free.c
void	free_all(t_map *map);
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

#endif