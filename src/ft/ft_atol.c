/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:42:04 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/02 19:42:32 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	long	res;
	int		sign;
	int		count;

	i = 0;
	res = 0;
	sign = 1;
	count = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - '0';
		count++;
	}
	if (count > 19 && sign == 1)
		return (sign * -1);
	if (count > 19 && sign == -1)
		return (0);
	return (res * sign);
}
