/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 09:52:56 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:46:39 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

/**
 * @brief Iterates over a circular linked list and applies
 * a function to each element.
 *
 * This function starts from the given list element
 * and applies the provided function
 * to each element in the list until it reaches the starting
 * element again or the function
 * returns 0.
 *
 * @param lst The list to iterate over.
 * @param f The function to apply to each element.
 * @param param Additional parameter to pass to the function.
 * @return t_lst* Pointer to the last element processed,
 * or NULL if iteration fails.
 */
t_lst	*lst_iter(t_lst **lst, int (*f)(t_lst **, void *), void *param)
{
	t_lst	*end;
	t_lst	*succeeding;
	int		status;

	if (!lst || !*lst || !f)
		return (NULL);
	*lst = lst_get(lst, 0);
	end = *lst;
	succeeding = (*lst)->next;
	status = f(lst, param);
	if (!status)
		return (*lst);
	else if (status == ERROR)
		return (NULL);
	while (succeeding != end)
	{
		*lst = succeeding;
		succeeding = succeeding->next;
		status = f(lst, param);
		if (!status)
			return (*lst);
		else if (status == ERROR)
			return (NULL);
	}
	return (*lst);
}
