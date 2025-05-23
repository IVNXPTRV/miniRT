/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:11:55 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/23 15:25:47 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// use faster sqrt??
t_num magnitude(t_vector vector)
{
    return sqrt(vector.x * vector.x
            + vector.y * vector.y
            + vector.z * vector.z);
}

t_vector normalize(t_vector vector)
{
    double	mag;

	mag = magnitude(vector);
    return ((t_vector){vector.x / mag, vector.y / mag, vector.z / mag});
}

t_vector scale_vector(t_vector vector, t_num scale)
{
	return ((t_vector){vector.x * scale, vector.y * scale, vector.z * scale});
}

t_vector flip_vector(t_vector vector)
{
	return ((t_vector){vector.x * -1, vector.y * -1, vector.z * -1});
}
