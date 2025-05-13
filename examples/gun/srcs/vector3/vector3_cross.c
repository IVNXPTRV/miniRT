/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_cross.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:05:40 by nteechar          #+#    #+#             */
/*   Updated: 2025/02/22 11:35:07 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vector3.h"

t_vector3	v_cross(const t_vector3 *a, const t_vector3 *b)
{
	return ((t_vector3){
		(a->y * b->z) - (a->z * b->y),
		(a->z * b->x) - (a->x * b->z),
		(a->x * b->y) - (a->y * b->x)
	});
}
