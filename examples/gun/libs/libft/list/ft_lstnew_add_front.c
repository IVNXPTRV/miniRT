/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_add_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:58:25 by nteechar          #+#    #+#             */
/*   Updated: 2024/10/25 11:22:06 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "t_list.h"

t_list	*ft_lstnew(void *content);

void	ft_lstadd_front(t_list **lst, t_list *new);

// return address of created node enveloping the content
// return NULL if cannot malloc new node
t_list	*ft_lstnew_add_front(t_list **lst, void *content)
{
	t_list	*node;

	node = ft_lstnew(content);
	if (node == NULL)
		return (NULL);
	ft_lstadd_front(lst, node);
	return (node);
}
