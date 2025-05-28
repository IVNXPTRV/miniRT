/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:30:40 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 13:11:33 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_ray get_ray(t_camera camera, int x, int y)
{
	// limit of variables in a function?
	t_num		u;
	t_num		v;
	t_num		px;
	t_num		py;
	t_num		half_width;
	t_num		half_height;
	t_vector	right;
	t_vector	up;
	t_ray		ray;

	// 1) image‐plane half‐sizes
	half_height = camera.scale;
	half_width = camera.scale * camera.ratio;					// 1 -- Distance from camera to view plane (usually 1.0)

	// 2) normalized [0,1] coords
	// Normalize pixel coordinates to [0,1] from view plane center
    u = (x + 0.5) / (double)WIDTH;
    v = (y + 0.5) / (double)HEIGHT;

	// 3) map to [-half_width, +half_width] & [+half_height, -half_height]
	// Map normalized coords to view plane coordinates
	px = (2.0 * u - 1.0) * half_width;				// -1  -- shifts X from [0, 1] → [–1, +1]
	py = (1.0 - 2.0 * v) * half_height;				// 1 - -- flips Y and shifts it to [+1, –1]

	// 4) build the ray
	ray.position = camera.position;
	right = scale_vector(camera.right, px);
	up = scale_vector(camera.up, py);
	ray.direction = normalize(add_vectors(camera.forward, add_vectors(right, up)));
	return (ray);
}
