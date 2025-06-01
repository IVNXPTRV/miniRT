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

t_ray	get_ray(t_camera camera, int x, int y)
{
	t_num		px;
	t_num		py;
	t_vector	right;
	t_vector	up;
	t_ray		ray;

	px = (2.0 * (x + 0.5) / (double)WIDTH - 1.0) * camera.scale * camera.ratio;
	py = (1.0 - 2.0 * (y + 0.5) / (double)HEIGHT) * camera.scale;
	ray.position = camera.position;
	right = scale_vector(camera.right, px);
	up = scale_vector(camera.up, py);
	ray.direction = normalize(add_vectors(camera.forward, add_vectors(right,
					up)));
	return (ray);
}
