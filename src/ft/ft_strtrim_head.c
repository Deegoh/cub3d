/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_head.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:17:05 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/26 17:17:16 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_head(char *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	res = ft_substr(s1, i, j - i + 1);
	free(s1);
	return (res);
}

char	*ft_strtrim_tail(char *s1, char const *set)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i < j && ft_strchr(set, s1[j]))
		j--;
	res = ft_substr(s1, i, j - i + 1);
	free(s1);
	return (res);
}
