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

static int	get_map(t_map *map, int fd)
{
	char	*gnl;
	int		i;

	gnl = get_next_line(fd);
	map->map = NULL;
	i = 1;
	while (gnl)
	{
		if (ft_strlen(gnl) > 2)
		{
			if (!map->map)
				map->map = ft_strdup(gnl);
			else
				map->map = ft_strjoin_f(map->map, gnl, 1);
			i++;
		}
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
	return (i);
}

static int	get_path_wall(t_map *map, char *type, int i)
{
	if (!strncmp(map->map + i, type, ft_strlen(type)))
	{
		i = i + 2;
		while (ft_isspace(map->map[i]))
			i++;
		if (!ft_strncmp(type, "NO", 2))
			map->w_no = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "SO", 2))
			map->w_so = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "WE", 2))
			map->w_we = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
		else if (!ft_strncmp(type, "EA", 2))
			map->w_ea = ft_substr(map->map, i, ft_strlen_c(map->map + i, '\n'));
	}
	return (i);
}

static void	get_texture(t_map *map)
{
	int	i;
	int	count_nl;

	i = -1;
	count_nl = 0;
	while (map->map[++i] && count_nl <= 6)
	{
		while (ft_isspace(map->map[i]))
			i++;
		if (map->map[i] == '\n')
			count_nl++;
		i = get_path_wall(map, "NO", i);
		i = get_path_wall(map, "SO", i);
		i = get_path_wall(map, "WE", i);
		i = get_path_wall(map, "EA", i);
	}
}

void	parse_map(t_map *map, char **av)
{
	int	fd;

	check_ext(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_msg(ERR_FD);
	get_map(map, fd);
	get_texture(map);
	printf("%s\n", map->map);
	//TODO CHECK value  bug print: printf("%s", map->w_no); printf("%s\n", map->w_no);
	printf("%s", map->w_no);
	printf("%s", map->w_so);
	printf("%s", map->w_we);
	printf("%s", map->w_ea);
}
