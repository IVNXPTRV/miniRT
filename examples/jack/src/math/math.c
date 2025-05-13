/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:34 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/08 13:56:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

/*
comapre doubleing vect numbers
if equal(< EPSILON), return true
else, return false
*/
bool	equal(double a, double b)
{
	if (fabs(a - b) < EPSILON)
		return (true);
	return (false);
}

t_point	add_vectors(t_point a, t_point b)
{
	return ((t_point){a.x + b.x, a.y + b.y, a.z + b.z});
}

// point1 - point2: pointing from p2 to p1
// vector1 - vector2: change in direction between the two
t_point	subtract_vectors(t_point a, t_point b)
{
	return ((t_point){a.x - b.x, a.y - b.y, a.z - b.z});
}

t_point	negate_vect(t_point a)
{
	return ((t_point){-a.x, -a.y, -a.z});
}

t_point	scale_vector(t_point a, double t)
{
	return ((t_point){a.x * t, a.y * t, a.z * t});
}
