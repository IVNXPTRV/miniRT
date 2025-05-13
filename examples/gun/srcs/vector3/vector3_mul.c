/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mul.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:07:36 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/10 16:07:36 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

t_vector3	v_scalar_mul(const t_vector3 *v, double scalar)
{
	return ((t_vector3){v->x * scalar, v->y * scalar, v->z * scalar});
}

t_vector3	*v_scalar_mul_ip(t_vector3 *dest, double scalar)
{
	dest->x *= scalar;
	dest->y *= scalar;
	dest->z *= scalar;
	return (dest);
}
