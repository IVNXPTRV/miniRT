/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:04:04 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/22 11:34:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

t_vector3	v_add(const t_vector3 *a, const t_vector3 *b)
{
	return ((t_vector3){a->x + b->x, a->y + b->y, a->z + b->z});
}

t_vector3	*v_add_ip(t_vector3 *dest, const t_vector3 *src)
{
	dest->x += src->x;
	dest->y += src->y;
	dest->z += src->z;
	return (dest);
}

t_vector3	v_sub(const t_vector3 *a, const t_vector3 *b)
{
	return ((t_vector3){a->x - b->x, a->y - b->y, a->z - b->z});
}

t_vector3	*v_sub_ip(t_vector3 *dest, const t_vector3 *src)
{
	dest->x -= src->x;
	dest->y -= src->y;
	dest->z -= src->z;
	return (dest);
}
