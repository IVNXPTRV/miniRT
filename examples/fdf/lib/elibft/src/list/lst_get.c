/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:03:26 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:07 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Retrieves an element from
 * a circular linked list at a specified index.
 *
 * This function finds and returns the element at the specified index, supporting
 * both positive and negative indices.
 *
 * @param lst The list to retrieve the element from.
 * @param i The index of the element to retrieve.
 * @return t_lst* Pointer to the retrieved element, or NULL if retrieval fails.
 */
t_lst	*lst_get(t_lst **lst, int i)
{
	int	max;

	if (!lst || !*lst)
		return (NULL);
	max = lst_len(lst) - 1;
	if (i > max)
		return (NULL);
	if (i < 0 && i + 1 < -max)
		return (NULL);
	if (i >= 0)
	{
		while ((*lst)->i != i)
			*lst = (*lst)->next;
	}
	else
	{
		while ((*lst)->i != max + (i + 1))
			*lst = (*lst)->next;
	}
	return (*lst);
}
