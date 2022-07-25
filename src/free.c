/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:35:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/25 11:36:02 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_map(t_map *map)
{
	free(map->map);
	free(map->w_no);
	free(map->w_so);
	free(map->w_we);
	free(map->w_ea);
}

void	free_all(t_map *map)
{
	free_map(map);
}
