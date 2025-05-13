/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:00:38 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/12 12:39:15 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_list.h"

t_list	*ft_lstnew(void *content);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstadd_back(t_list **lst, t_list *new);

static t_list	*create_new_node(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new_node;
	void	*new_content;

	new_content = f(lst->content);
	if (new_content == NULL)
		return (NULL);
	new_node = ft_lstnew(new_content);
	if (new_node == NULL)
	{
		if (del)
			del(new_content);
		return (NULL);
	}
	return (new_node);
}

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’.
// - del function is for deleting incomplete created list
// - if del function is NULL, do nothing with the lst->content
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*last_node;
	t_list	*new_node;

	new_lst = NULL;
	while (lst)
	{
		new_node = create_new_node(lst, f, del);
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (new_lst == NULL)
			new_lst = new_node;
		else
			ft_lstadd_back(&last_node, new_node);
		last_node = new_node;
		lst = lst->next;
	}
	return (new_lst);
}
