/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 08:29:36 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:33:35 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	validate_camera(t_scene *scene)
{
	if (scene->camera.status == false)
	{
		err(Z, (t_m){"minirt: no camera found in a scene configuration"});
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
}

static void	validate_ambient(t_scene *scene)
{
	if (scene->ambient.status == false)
	{
		err(Z,
			(t_m){"minirt: no ambient light found in a scene configuration"});
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
}

static void	validate_light(t_scene *scene)
{
	if (scene->light.status == false)
	{
		err(Z, (t_m){"minirt: no light found in a scene configuration"});
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
}

static void	validate_obj_num(t_scene *scene)
{
	if (scene->obj_num == 0)
	{
		err(Z, (t_m){"minirt: no objects found in a scene configuration"});
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
}

void	validate_scene(t_scene *scene)
{
	validate_camera(scene);
	validate_light(scene);
	validate_ambient(scene);
	validate_obj_num(scene);
}
