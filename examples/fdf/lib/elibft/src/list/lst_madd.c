/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_madd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:07:49 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:48 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Adds a new element to a circular linked list with memory allocation.
 *
 * size_of ony size of data types not len of string.
 * This function allocates memory for the new item, copies the data into it,
 * and then adds the new element to the list at the specified index.
 *
 * @param lst The list to add the new element to.
 * @param item The data to store in the new element.
 * @param size_of The size of the data to be copied.
 * @param i The index at which to add the new element.
 * @return t_lst* Pointer to the newly added element, or NULL if addition fails.
 */
t_lst	*lst_madd(t_lst **lst, void *item, int i, size_t size_of)
{
	t_lst	*node;
	void	*result;

	if (!lst || !item || size_of == 0)
		return (NULL);
	result = malloc(size_of);
	if (!result)
		return (NULL);
	ft_memcpy(result, item, size_of);
	node = lst_add(lst, result, i);
	if (!node)
	{
		free(result);
		return (NULL);
	}
	return (node);
}
