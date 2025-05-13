/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:28:26 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:45:38 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

static int	plug(void *param)
{
	(void)param;
	return (SUCCESS);
}

static int	clean(t_lst **lst, void *f)
{
	int	(*func)(void *);

	func = (int (*)(void *))f;
	func((*lst)->item);
	free(*lst);
	return (CONTINUE);
}

/**
 * @brief Cleans up a circular linked list by freeing all elements.
 *
 * This function iterates over the list and frees each element, optionally
 * applying a provided function to the item before freeing.
 *
 * @param lst The list to clean up.
 * @param f The function to apply to each element's data before freeing.
 * @return t_lst* Always returns NULL.
 */
void	*lst_clean(t_lst **lst, int (*f)(void *))
{
	if (!lst || !*lst)
		return (NULL);
	if (!f)
		f = plug;
	lst_iter(lst, clean, f);
	*lst = NULL;
	return (*lst);
}
