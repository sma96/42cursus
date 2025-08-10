/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sma <sma@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:05:47 by sma               #+#    #+#             */
/*   Updated: 2021/07/05 15:47:48 by sma              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*lst_clear(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newnode;

	if (!lst)
		return (NULL);
	newnode = ft_lstnew(f(lst->content));
	if (!(newnode))
		return (lst_clear(lst, del));
	lst = lst->next;
	newlst = newnode;
	while (lst)
	{
		newnode = ft_lstnew(f(lst->content));
		if (!(newnode))
		{
			ft_lstclear(&newlst, del);
			return (lst_clear(lst, del));
		}
		lst = lst->next;
		ft_lstadd_back(&newlst, newnode);
	}
	return (newlst);
}
