/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:37:05 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 14:42:39 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_list.h"

t_list	*ft_lstfirst(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));

// remove first node of linked list
// if del function is NULL, do nothing with the lst->content
void	ft_lstdel_front(t_list **lst, void (*del)(void *))
{
	t_list	*first_node;

	first_node = ft_lstfirst(*lst);
	if (*lst == first_node)
		*lst = first_node->next;
	ft_lstdelone(first_node, del);
}
