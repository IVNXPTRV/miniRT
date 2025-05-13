/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 16:18:07 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/08 14:00:39 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	identity_matrix(void)
{
	t_matrix	m;

	m.m[0][0] = 1;
	m.m[0][1] = 0;
	m.m[0][2] = 0;
	m.m[1][0] = 0;
	m.m[1][1] = 1;
	m.m[1][2] = 0;
	m.m[2][0] = 0;
	m.m[2][1] = 0;
	m.m[2][2] = 1;
	return (m);
}

t_matrix	generate_rotation_matrix(t_point axis, double angle)
{
	t_matrix	matrix;
	t_point		u;
	double		cos_theta;
	double		sin_theta;

	u = normalize(axis);
	cos_theta = cos(angle);
	sin_theta = sin(angle);
	matrix.m[0][0] = cos_theta + u.x * u.x * (1 - cos_theta);
	matrix.m[0][1] = u.x * u.y * (1 - cos_theta) - u.z * sin_theta;
	matrix.m[0][2] = u.x * u.z * (1 - cos_theta) + u.y * sin_theta;
	matrix.m[1][0] = u.y * u.x * (1 - cos_theta) + u.z * sin_theta;
	matrix.m[1][1] = cos_theta + u.y * u.y * (1 - cos_theta);
	matrix.m[1][2] = u.y * u.z * (1 - cos_theta) - u.x * sin_theta;
	matrix.m[2][0] = u.z * u.x * (1 - cos_theta) - u.y * sin_theta;
	matrix.m[2][1] = u.z * u.y * (1 - cos_theta) + u.x * sin_theta;
	matrix.m[2][2] = cos_theta + u.z * u.z * (1 - cos_theta);
	return (matrix);
}

t_matrix	generate_rotation_to_z(t_point norm)
{
	t_rotation	rotation;
	t_point		u;
	t_matrix	m;

	get_rotation(norm, &rotation);
	u = normalize(rotation.axis);
	if (fabs(rotation.angle) < EPSILON || magnitude(rotation.axis) < EPSILON)
		return (identity_matrix());
	m.m[0][0] = rotation.cos + u.x * u.x * rotation.one_minus_c;
	m.m[0][1] = u.x * u.y * rotation.one_minus_c - u.z * rotation.sin;
	m.m[0][2] = u.x * u.z * rotation.one_minus_c + u.y * rotation.sin;
	m.m[1][0] = u.y * u.x * rotation.one_minus_c + u.z * rotation.sin;
	m.m[1][1] = rotation.cos + u.y * u.y * rotation.one_minus_c;
	m.m[1][2] = u.y * u.z * rotation.one_minus_c - u.x * rotation.sin;
	m.m[2][0] = u.z * u.x * rotation.one_minus_c - u.y * rotation.sin;
	m.m[2][1] = u.z * u.y * rotation.one_minus_c + u.x * rotation.sin;
	m.m[2][2] = rotation.cos + u.z * u.z * rotation.one_minus_c;
	return (m);
}

t_matrix	transpose_matrix(t_matrix m)
{
	t_matrix	t;

	t.m[0][0] = m.m[0][0];
	t.m[0][1] = m.m[1][0];
	t.m[0][2] = m.m[2][0];
	t.m[1][0] = m.m[0][1];
	t.m[1][1] = m.m[1][1];
	t.m[1][2] = m.m[2][1];
	t.m[2][0] = m.m[0][2];
	t.m[2][1] = m.m[1][2];
	t.m[2][2] = m.m[2][2];
	return (t);
}

t_point	apply_rotation(t_matrix matrix, t_point point)
{
	t_point	result;

	result.x = (matrix.m[0][0]
			* point.x + matrix.m[0][1]
			* point.y + matrix.m[0][2]
			* point.z);
	result.y = (matrix.m[1][0]
			* point.x + matrix.m[1][1]
			* point.y + matrix.m[1][2]
			* point.z);
	result.z = (matrix.m[2][0]
			* point.x + matrix.m[2][1]
			* point.y + matrix.m[2][2]
			* point.z);
	return (result);
}
