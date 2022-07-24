/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 09:28:10 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/16 19:36:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	slen;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (slen < len)
		len = slen;
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (NULL);
	while (i < len && start < (unsigned int)ft_strlen(s))
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
