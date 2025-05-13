/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_camera.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:38:00 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 22:39:10 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/world.h"

static void	configure_viewport_v_and_h(t_camera *camera)
{
	t_vector3	world_up;
	double		vp_width;
	double		vp_height;
	double		aspect_ratio;
	double		rad_fov;

	world_up = v_create(0, 1, 0);
	if (fabs(camera->normal.x) < 1e-6 && fabs(camera->normal.z) < 1e-6)
		world_up = v_create(0, 0, 1);
	\
	aspect_ratio = ((double) SCREEN_WIDTH) / SCREEN_HEIGHT;
	rad_fov = (camera->deg_fov * PI) / 180;
	vp_height = 2 * tan(rad_fov / 2);
	vp_width = vp_height * aspect_ratio;
	\
	camera->viewport_h = v_cross(&camera->normal, &world_up);
	camera->viewport_v = v_cross(&camera->normal, &camera->viewport_h);
	v_scalar_mul_ip(&camera->viewport_h, vp_width);
	v_scalar_mul_ip(&camera->viewport_v, vp_height);
}

static void	configure_pixel_delta_v_and_h(t_camera *camera)
{
	camera->pixel_delta_h = \
		v_scalar_mul(&camera->viewport_h, 1.0 / SCREEN_WIDTH);
	camera->pixel_delta_v = \
		v_scalar_mul(&camera->viewport_v, 1.0 / SCREEN_HEIGHT);
}

static void	configure_pixel00_loc(t_camera *camera)
{
	t_vector3	viewport_upper_left;
	t_vector3	temp;

	viewport_upper_left = v_copy(&camera->point);
	temp = v_normalize(&camera->normal);
	v_add_ip(&viewport_upper_left, &temp);
	temp = v_scalar_mul(&camera->viewport_h, 0.5);
	v_sub_ip(&viewport_upper_left, &temp);
	temp = v_scalar_mul(&camera->viewport_v, 0.5);
	v_sub_ip(&viewport_upper_left, &temp);
	\
	camera->pixel00_loc = v_copy(&viewport_upper_left);
	temp = v_scalar_mul(&camera->pixel_delta_h, 0.5);
	v_add_ip(&camera->pixel00_loc, &temp);
	temp = v_scalar_mul(&camera->pixel_delta_v, 0.5);
	v_add_ip(&camera->pixel00_loc, &temp);
}

// assume camera.{center,deg_fov,normal} has already been set correctly
void	configure_camera(t_camera *camera)
{
	configure_viewport_v_and_h(camera);
	configure_pixel_delta_v_and_h(camera);
	configure_pixel00_loc(camera);
}
