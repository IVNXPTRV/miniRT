/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:54:32 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/11 16:20:14 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_list.h"

// - if del function is NULL, do nothing with the lst->content
// - connects the previous node to next node and vice versa, before deleting
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst->prev)
		(lst->prev)->next = lst->next;
	if (lst->next)
		(lst->next)->prev = lst->prev;
	if (del)
		del(lst->content);
	free(lst);
}
