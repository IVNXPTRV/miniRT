/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:52:56 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:45:01 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Adds a new element to a circular linked list at a specified index.
 *
 * it attaches item.
 * This function creates a new list element with the provided data and inserts it
 * into the list at the specified index.
 *
 * @param lst The list to add the new element to.
 * @param item The data to store in the new element.
 * @param i The index after which to add the new element.
 * @return t_lst* Pointer to the newely added item, or NULL if addition fails.
 */
t_lst	*lst_add(t_lst **lst, void *item, int i)
{
	t_lst	*node;

	if (!lst)
		return (NULL);
	node = lst_new(&node, item);
	if (!node)
		return (NULL);
	if (!lst_insert(lst, &node, i))
		return (NULL);
	return (node);
}
