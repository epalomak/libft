/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:10:13 by epalomak          #+#    #+#             */
/*   Updated: 2021/05/04 13:51:38 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*first;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	first = new;
	while (lst->next)
	{
		lst = lst->next;
		new->next = f(lst);
		if (!new->next)
			return (NULL);
		new = new->next;
	}
	return (first);
}
