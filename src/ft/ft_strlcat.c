/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 19:04:29 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/16 19:36:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char	*dst, const char	*src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	res;
	size_t	stop;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	stop = 0;
	if (!size && !dst)
		return (srclen);
	if (size > dstlen)
	{
		stop = size - dstlen - 1;
		res = dstlen + srclen;
	}
	else
		res = srclen + size;
	while (src[i] && i < stop)
		dst[dstlen++] = src[i++];
	if (stop)
		dst[dstlen] = '\0';
	return (res);
}
