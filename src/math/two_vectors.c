/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:09:19 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 14:49:44 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_num	dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vector	cross(t_vector a, t_vector b)
{
	t_vector	result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (normalize(result));
}

t_vector	add_vectors(t_vector a, t_vector b)
{
	return ((t_vector){a.x + b.x, a.y + b.y, a.z + b.z});
}

t_vector	sub_vectors(t_vector a, t_vector b)
{
	return ((t_vector){a.x - b.x, a.y - b.y, a.z - b.z});
}
