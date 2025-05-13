/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:53:16 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 22:25:29 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/data.h"

static void	init_ray(t_ray *ray, t_camera *camera)
{
	ray->origin = v_copy(&camera->point);
	ray->direction = v_sub(&camera->pixel00_loc, &ray->origin);
}

static void	render_row(t_data *data, t_ray *ray, int y)
{
	int	x;
	int	pixel_color;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		pixel_color = ray_color(ray, &data->world);
		mlx_put_pixel(data->img, x, y, pixel_color);
		x++;
		v_add_ip(&ray->direction, &data->world.camera.pixel_delta_h);
	}
}

void	render_image(t_data *data)
{
	t_ray	ray;
	int		y;

	configure_camera(&data->world.camera);
	init_ray(&ray, &data->world.camera);
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		render_row(data, &ray, y);
		y++;
		v_sub_ip(&ray.direction, &data->world.camera.viewport_h);
		v_add_ip(&ray.direction, &data->world.camera.pixel_delta_v);
		if (data->mode == MODE_DEBUG)
			ft_printf("\rRendering y=%i", y);
	}
	if (data->mode == MODE_DEBUG)
		ft_printf("\rFinish rendering!\n");
}
