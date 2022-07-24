/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-m <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:06:29 by tpinto-m          #+#    #+#             */
/*   Updated: 2022/01/16 19:36:06 by tpinto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp)
			ft_lstadd_back(&res, tmp);
		else
			ft_lstclear(&tmp, del);
		lst = lst->next;
	}
	return (res);
}
