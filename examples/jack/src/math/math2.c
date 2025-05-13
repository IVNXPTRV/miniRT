/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:29:34 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/08 13:57:30 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "operation.h"

// magnitude = 1: unit vector
double	magnitude(t_point a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_point	normalize(t_point a)
{
	double	mag;

	mag = magnitude(a);
	return ((t_point){a.x / mag, a.y / mag, a.z / mag});
}

/*
the smaller the doct product, the larger angle between the vectors
given two unit vectors:
		dot_procuct: cosine of the angle between them
		dot-product = 1: two vectors are identical
		dot-product = -1: two vectors vect in opposite directons
*/
double	dot_product(t_point a, t_point b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

/*
unit vectors X, Y Z
cross(X, Y) -> Z
cross(Y, Z) -> X
cross(Z, X) -> Y
cross(Y, X) -> -Z
*/
t_point	cross_product(t_point a, t_point b)
{
	return ((t_point){
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x});
}
