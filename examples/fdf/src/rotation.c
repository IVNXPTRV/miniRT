/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:44:35 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:27:50 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	rad(double degrees)
{
	return (degrees * M_PI / 180.0);
}

static t_rot_matrix	get_rot_matrix(double deg, char axis)
{
	deg = rad(deg);
	if (axis == 'x')
		return ((t_rot_matrix){
			(t_3d_vector){1, 0, 0},
			(t_3d_vector){0, cos(deg), -sin(deg)},
			(t_3d_vector){0, sin(deg), cos(deg)}});
	else if (axis == 'y')
		return ((t_rot_matrix){
			(t_3d_vector){cos(deg), 0, sin(deg)},
			(t_3d_vector){0, 1, 0},
			(t_3d_vector){-sin(deg), 0, cos(deg)}});
	else
		return ((t_rot_matrix){
			(t_3d_vector){cos(deg), -sin(deg), 0},
			(t_3d_vector){sin(deg), cos(deg), 0},
			(t_3d_vector){0, 0, 1}});
}

static t_node	rotate_axis(t_node n, double deg, char axis)
{
	t_rot_matrix	m;
	t_3d_vector		v;

	v = n.v.v3d;
	m = get_rot_matrix(deg, axis);
	n.v.v3d.z = (v.x * m.k.x) + (v.y * m.k.y) + (v.z * m.k.z);
	n.v.v3d.x = (v.x * m.i.x) + (v.y * m.i.y) + (v.z * m.i.z);
	n.v.v3d.y = (v.x * m.j.x) + (v.y * m.j.y) + (v.z * m.j.z);
	return (n);
}

t_node	rotate(t_node n, t_imginf *img)
{
	n = rotate_axis(n, img->rotation.z, 'z');
	n = rotate_axis(n, img->rotation.y, 'y');
	n = rotate_axis(n, img->rotation.x, 'x');
	return (n);
}
