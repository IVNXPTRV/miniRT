/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 01:32:25 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 22:27:59 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vector3.h"

typedef struct s_camera
{
	t_vector3	point;
	double		deg_fov;
	t_vector3	normal;
	t_vector3	viewport_h;
	t_vector3	viewport_v;
	t_vector3	pixel_delta_h;
	t_vector3	pixel_delta_v;
	t_vector3	pixel00_loc;
}	t_camera;

void	configure_camera(t_camera *camera);

#endif
