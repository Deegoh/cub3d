/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:43:56 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/08/26 15:43:58 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	rad_to_degree(double rad)
{
	return (180 / M_PI * rad);
}

double	degree_to_rad(double degree)
{
	return (M_PI / 180 * degree);
}

float	precision(double num, int digit)
{
	return (floor(digit * num) / digit);
}

int	ft_abs(int x)
{
	if (x < 0)
		x = -x;
	return (x);
}
