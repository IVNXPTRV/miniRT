/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:15:25 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/10 16:25:42 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

t_vector3	v_normalize(const t_vector3 *v)
{
	double	norm;

	norm = v_norm(v);
	return ((t_vector3){v->x / norm, v->y / norm, v->z / norm});
}

// can cause error if dest's norm is 0
t_vector3	*v_normalize_ip(t_vector3 *dest)
{
	v_scalar_mul_ip(dest, 1.0f / v_norm(dest));
	return (dest);
}
