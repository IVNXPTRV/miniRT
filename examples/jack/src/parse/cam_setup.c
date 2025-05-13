/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:48:17 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/11 00:14:36 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	cam_setup(t_cam *cam)
{
	t_point	temp;

	cam->ratio = (double) WIDTH / (double)HEIGHT;
	cam->scale = tan(cam->fov * 0.5 * PI / 180.0);
	temp = (t_point){0, 1, 0};
	cam->forward = cam->norm;
	if (fabs(dot_product(cam->forward, temp)) > 0.999)
		temp = (t_point){0, 0, 1};
	cam->right = normalize(cross_product(cam->forward, temp));
	cam->up = cross_product(cam->right, cam->forward);
}

void	fill_cam(t_cam *cam, t_temp *temp)
{
	cam->position.x = ft_atod(temp->vec3_pos[0]);
	cam->position.y = ft_atod(temp->vec3_pos[1]);
	cam->position.z = ft_atod(temp->vec3_pos[2]);
	cam->norm.x = ft_atod(temp->vec3_norm[0]);
	cam->norm.y = ft_atod(temp->vec3_norm[1]);
	cam->norm.z = ft_atod(temp->vec3_norm[2]);
	cam_setup(cam);
}
