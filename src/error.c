/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yacinebentayeb <yacinebentayeb@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 08:44:42 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/01 23:23:11 by yacinebenta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	err_msg(char *str)
{
	ft_putstr_fd(str, 2);
	exit (EXIT_FAILURE);
}

int	exit_cub(t_data *data)
{
	free_all(data);
	exit(EXIT_SUCCESS);
}
