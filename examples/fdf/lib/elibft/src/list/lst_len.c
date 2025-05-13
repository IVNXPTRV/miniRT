/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 08:11:29 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:43 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Calculates the length of a doubly circular linked list.
 *
 * This function iterates through the list until it reaches the starting element
 * again, counting the number of elements in the list.
 *
 * @param lst The list to calculate the length of.
 * @return int The length of the list.
 */
size_t	lst_len(t_lst **lst)
{
	if (!lst || !*lst)
		return (0);
	while ((*lst)->next->i != 0)
		(*lst) = (*lst)->next;
	return ((*lst)->i + 1);
}
