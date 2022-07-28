/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubreplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 10:27:17 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/07/25 10:27:37 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	result_len(const char *s, const char *set, int *cnt)
{
	int	i;
	int	set_len;

	i = -1;
	set_len = ft_strlen(set);
	while (s[++i] != '\0')
	{
		if (ft_strnstr(&s[i], set, ft_strlen(&s[i])) == &s[i])
		{
			(*cnt)++;
			i += set_len - 1;
		}
	}
	return (i);
}

char	*ft_strsubreplace(const char *s, const char *set, const char *sub)
{
	char	*result;
	int		i;
	int		cnt;
	int		sub_len;
	int		set_len;

	cnt = 0;
	sub_len = ft_strlen(sub);
	set_len = ft_strlen(set);
	i = result_len(s, set, &cnt);
	result = (char *)malloc(i + cnt * (sub_len - set_len) + 1);
	i = 0;
	while (*s)
	{
		if (ft_strnstr(s, set, ft_strlen(s)) == s)
		{
			s += set_len;
			while (*sub)
				result[i++] = *sub++;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}
