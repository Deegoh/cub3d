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

static void	get_map(t_map map, int fd)
{
	char	*gnl;

	gnl = get_next_line(fd);
	map.map = NULL;
	while (gnl)
	{
		if (!map.map)
			map.map = ft_strdup(gnl);
		else
			map.map = ft_strjoin_f(map.map, gnl, 1);
		free(gnl);
		gnl = get_next_line(fd);
	}
	free(gnl);
}

void	parse_map(t_map map, char **av)
{
	int	fd;

	check_ext(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_msg(ERR_FD);
	get_map(map, fd);
}
