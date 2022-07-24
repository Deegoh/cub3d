/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:04:08 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/16 19:36:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needlelen;

	i = 0;
	j = 0;
	needlelen = ft_strlen(needle);
	if (needlelen == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (j == needlelen - 1)
				return (&((char *)haystack)[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
