/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:52:56 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:57 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Creates and initializes a new element
 * for a circular linked list.
 *
 * This function allocates memory for a new list element, initializes its
 * data with the provided item, sets up the circular link by pointing
 * the next pointer to itself, initializes the index field to 0, and assigns
 * the new element to the provided list pointer.
 *
 * @param lst Pointer to the list pointer to assign the new element.
 * @param item The data to store in the new element.
 * @return t_lst* Pointer to the newly created element,
 *  or NULL if allocation fails.
 */
t_lst	*lst_new(t_lst **lst, void *item)
{
	t_lst	*node;

	if (!item || !lst)
		return (NULL);
	node = (t_lst *)malloc(sizeof(t_lst));
	if (!node)
		return (NULL);
	node->item = item;
	node->next = node;
	node->i = 0;
	*lst = node;
	return (*lst);
}
