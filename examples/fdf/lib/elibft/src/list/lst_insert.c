/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_insert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:52:56 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:24 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

static int	update_index(t_lst **lst, void *param)
{
	(void)param;
	if ((*lst)->next->i == 0)
		return (STOP);
	(*lst)->next->i = (*lst)->i + 1;
	return (CONTINUE);
}

/**
 * @brief Inserts a new element into a circular linked list
 * at a specified index.
 *
 * This function finds the element at the specified index
 *  and inserts the new element
 * after it, updating the indices of the subsequent elements.
 *
 * @param lst The list to insert the new element into.
 * @param new The new element to insert.
 * @param i The index at which to insert the new element.
 * @return t_lst* Pointer to the newly inserted element,
 * or NULL if insertion fails.
 */
void	*lst_insert(t_lst **lst, t_lst **new, int i)
{
	t_lst	*start;
	t_lst	*end;

	if (!lst || !new || !*new)
		return (NULL);
	if (!*lst)
	{
		*lst = *new;
		return (*lst);
	}
	*lst = lst_get(lst, i);
	if (!*lst)
		return (NULL);
	end = lst_get(new, -1);
	start = lst_get(new, 0);
	start->i = (*lst)->i + 1;
	end->next = (*lst)->next;
	(*lst)->next = start;
	lst_iter(lst, update_index, NULL);
	return (*lst);
}
