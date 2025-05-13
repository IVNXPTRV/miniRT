/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:49:04 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/03 22:55:19 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	validate_each(t_objs *obj)
{
	int	error;

	error = in_range(obj->color.x, 'c');
	error |= in_range(obj->color.y, 'c');
	error |= in_range(obj->color.z, 'c');
	if (obj->type != SP)
	{
		error |= in_range(obj->norm.x, 'n');
		error |= in_range(obj->norm.y, 'n');
		error |= in_range(obj->norm.z, 'n');
	}
	if (error)
	{
		if (obj->type == SP)
			return (ERR_SP | ERR_OOR);
		if (obj->type == PL)
			return (ERR_PL | ERR_OOR);
		if (obj->type == CY)
			return (ERR_CY | ERR_OOR);
	}
	return (0);
}

int	validate_objs(t_list *lst)
{
	int		error;
	t_objs	*obj;

	error = 0;
	while (lst && !error)
	{
		obj = (t_objs *)lst->content;
		error |= validate_each(obj);
		if (error)
			return (error);
		lst = lst->next;
	}
	return (0);
}
