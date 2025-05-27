/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:30:40 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 10:54:37 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray get_ray(t_camera camera, int x, int y)
{
	// limit of variables in a function?
	t_num	u;
	t_num	v;
	t_num	px;
	t_num	py;
	t_num	half_width;
	t_num	half_height;
	t_vector right;
	t_vector up;
	t_ray	ray;

	half_width = camera.scale * 1;					// 1 -- Distance from camera to view plane (usually 1.0)
	half_height = camera.ratio;
	\
	// Normalize pixel coordinates to [0,1] from view plane center
    u = (x + 0.5) / (double)WIDTH;
    v = (y + 0.5) / (double)HEIGHT;
	\
	// Map normalized coords to view plane coordinates
	px = (2.0 * u - 1.0) * half_width;				// -1 -- shifts X from [0, 1] → [–1, +1]
	py = (1.0 - 2.0 * v) * half_height;				// 1 - -- flips Y and shifts it to [+1, –1]
	\
	ray.position = camera.position;
	right = scale_vector(camera.right, px);
	up = scale_vector(camera.up, py);
	ray.direction = add_vectors(camera.forward, add_vectors(right, up));
	return (ray);
}
