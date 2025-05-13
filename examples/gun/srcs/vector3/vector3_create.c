/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:04:08 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/10 16:56:59 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

t_vector3	v_create(double x, double y, double z)
{
	return ((t_vector3){x, y, z});
}

t_vector3	*v_set_ip(t_vector3 *dest, double x, double y, double z)
{
	dest->x = x;
	dest->y = y;
	dest->z = z;
	return (dest);
}

t_vector3	v_copy(const t_vector3 *other)
{
	return ((t_vector3){other->x, other->y, other->z});
}

t_vector3	*v_copy_ip(t_vector3 *dest, const t_vector3 *other)
{
	dest->x = other->x;
	dest->y = other->y;
	dest->z = other->z;
	return (dest);
}
