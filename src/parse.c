/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:40 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/25 08:44:41 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_ext(char *path)
{
	char	*ext;

	ext = ft_strnstr(path, EXT, ft_strlen(path));
	if (ext && ft_strlen(ext) == ft_strlen(EXT))
		return ;
	err_msg(ERR_FILE);
}

static void	get_map(t_map *map, int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	map->map = NULL;
	map->nbr_line = 0;
	map->len_line = 0;
	while (gnl)
	{
		if (map->nbr_line > 6 && map->len_line < (int)ft_strlen(gnl))
			map->len_line = (int)ft_strlen(gnl);
		if (ft_strlen(gnl) > 2)
		{
			if (!map->map)
				map->map = ft_strdup(gnl);
			else
				map->map = ft_strjoin_f(map->map, gnl, 1);
			map->nbr_line++;
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	map->nbr_line -= 6;
	map->len_line -= 1;
}

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	get_floor_or_ceiling(t_map *map, int i)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 0;
	while (!ft_isdigit(map->map[i]))
		i++;
	r = ft_atoi(map->map + i);
	i += ft_nbrlen(r);
	while (!ft_isdigit(map->map[i]))
		i++;
	g = ft_atoi(map->map + i);
	i += ft_nbrlen(g);
	while (!ft_isdigit(map->map[i]))
		i++;
	b = ft_atoi(map->map + i);
	//TODO err mgnt color (0-255 only)
	return (create_trgb(a, r, g, b));
}

static int	get_info(t_map *map, char *type, int i)
{
	if (!strncmp(map->map + i, type, ft_strlen(type)))
	{
		i += ft_strlen(type);
		while (ft_isspace(map->map[i]))
			i++;
		if (!ft_strncmp(type, "NO ", 3))
			map->w_no = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "SO ", 3))
			map->w_so = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "WE ", 3))
			map->w_we = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "EA ", 3))
			map->w_ea = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "F ", 2))
			map->floor = get_floor_or_ceiling(map, i);
		else if (!ft_strncmp(type, "C ", 2))
			map->ceiling = get_floor_or_ceiling(map, i);
	}
	return (i);
}

static int	get_elems(t_map *map)
{
	int	i;
	int	count_nl;

	i = -1;
	count_nl = 0;
	while (map->map[++i] && count_nl <= 6)
	{
		if (map->map[i] == '\n')
		{
			count_nl++;
			continue ;
		}
		if (count_nl == 6)
			break ;
		if (ft_isspace(map->map[i]))
			continue ;
		i = get_info(map, "NO ", i);
		i = get_info(map, "SO ", i);
		i = get_info(map, "WE ", i);
		i = get_info(map, "EA ", i);
		i = get_info(map, "F ", i);
		i = get_info(map, "C ", i);
	}
	return (i);
}

static void	init_map2d(t_map *map)
{
	int	i;

	map->map2d = ft_calloc(sizeof(char **), map->nbr_line);
	if (!map->map2d)
		err_msg("Error\nMalloc\n");
	i = -1;
	while (++i < map->nbr_line)
	{
		map->map2d[i] = ft_calloc(sizeof(char *), map->len_line);
		if (!map->map2d[i])
			err_msg("Error\nMalloc[i]\n");
	}
}

static void	populate_map2d(t_map *map, int i)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			map->map2d[y][x] = '.';
		}
	}
	y = -1;
	while (++y < map->nbr_line && map->map[i])
	{
		x = -1;
		while (++x < map->len_line && map->map[i])
		{
			if (map->map[i] == '\n')
				continue ;
			if (map->map[i] == '1' || map->map[i] == '0' || map->map[i] == 'N')
				map->map2d[y][x] = map->map[i];
			i++;
		}
		i++;
	}
}

void	parse_map(t_map *map, char **av)
{
	int	fd;
	int	i;

	check_ext(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_msg(ERR_FD);
	get_map(map, fd);
	i = get_elems(map);
	init_map2d(map);
	populate_map2d(map, i);
	int	x;
	int	y;
	y = -1;
	while (++y < map->nbr_line)
	{
		x = -1;
		while (++x < map->len_line)
		{
			printf("%c", map->map2d[y][x]);
		}
		printf("\n");
	}
}
