/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@24lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:43:15 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/05/02 19:43:33 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_remove_str(char *str, const char *sub)
{
	int		len;
	char	*p;

	len = ft_strlen(sub);
	if (len > 0)
	{
		p = ft_strnstr(str, sub, ft_strlen(str));
		while (p)
		{
			ft_memmove(p, p + len, ft_strlen(p + len) + 1);
			p = ft_strnstr(str, sub, ft_strlen(str));
		}
	}
	return (str);
}
