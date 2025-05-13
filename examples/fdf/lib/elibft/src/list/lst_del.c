/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 11:36:16 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:45:46 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Deletes an element from a circular linked list.
 *
 * This function extracts the element at the specified index from the list,
 * applies the provided function to free the element's data, and returns NULL.
 *
 * @param lst The list from which to delete the element.
 * @param i The index of the element to delete.
 * @param f The function to apply to the element's data.
 * @return t_lst* Always returns NULL.
 */
t_lst	*lst_del(t_lst **lst, int i, int (*f)(void *))
{
	void	*item;

	item = lst_extract(lst, i);
	f(item);
	return (NULL);
}
