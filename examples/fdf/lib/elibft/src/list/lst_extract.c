/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_extract.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:45:11 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:45:55 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Updates the index of the list nodes.
 *
 * This function updates the index of the list nodes by decrementing the index
 * of the next node by 1. If the next node's index is 0, it stops the iteration.
 *
 * @param lst A pointer to the list.
 * @param param An additional parameter (unused).
 * @return int Returns STOP if the next node's index is 0, otherwise CONTINUE.
 */
static int	update_index(t_lst **lst, void *param)
{
	(void)param;
	if ((*lst)->next->i == 0)
		return (STOP);
	(*lst)->next->i = (*lst)->next->i - 1;
	return (CONTINUE);
}

/**
 * @brief Extracts an item from the list at a given index.
 *
 * This function extracts an item from the list at the specified index. It also
 * updates the indices of the remaining nodes and frees the extracted node.
 *
 * @param lst A double pointer to the list.
 * @param i The index of the item to extract.
 * @return void* The extracted item.
 */
void	*lst_extract(t_lst **lst, int i)
{
	t_lst	*node;
	t_lst	*tmp;
	void	*item;

	node = lst_get(lst, i - 1);
	if (!node)
		return (NULL);
	item = node->next->item;
	if (node->i == node->next->i)
	{
		*lst = NULL;
		free(node->next);
		return (item);
	}
	else
	{
		tmp = node->next;
		node->next = node->next->next;
		free(tmp);
		lst_iter(lst, update_index, NULL);
		return (item);
	}
}
