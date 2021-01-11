/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yong-lee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:42:26 by yong-lee          #+#    #+#             */
/*   Updated: 2020/12/06 03:10:20 by yong-lee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*cur;

	if (lst == NULL || f == NULL)
		return (NULL);
	if (!(cur = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	head = cur;
	lst = lst->next;
	while (lst)
	{
		if (!(cur = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&head, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&head, cur);
	}
	return (head);
}
