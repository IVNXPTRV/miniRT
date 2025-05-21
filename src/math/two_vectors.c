/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_vectors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:09:19 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:40:19 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//returns how aligned 2 vectors -1 to +1 if vectors normilized
t_num dot(t_vector a, t_vector b)
{
    return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z);
}

// normalization embeded
t_vector cross(t_vector a, t_vector b)
{
    t_vector result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (normalize(result));
}
