/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:44:19 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 11:38:28 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static uint32_t	get_raw(t_color color)
{
	return (((int)round(color.r * 255.0) << 24) | ((int)round(color.g
				* 255.0) << 16) | ((int)round(color.b * 255.0) << 8) | OPAQUE);
}

static void	put_pixel(t_scene *scene, int x, int y, t_color color)
{
	mlx_put_pixel(scene->gl.image, x, y, get_raw(color));
}

void	compute_image(t_scene *scene)
{
	t_color	color;
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = get_pixel_color(scene, x, y);
			put_pixel(scene, x, y, color);
			x++;
		}
		y++;
	}
}
