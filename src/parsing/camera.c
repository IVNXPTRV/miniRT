/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:14:34 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 12:17:23 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void verify_fov(char **element, int i, int lineno, int fov)
{
	if (!is_in_range((double)fov, 0, 180))
	{
		err(lineno, (t_m){"fov is beyond 0 to 180 range -> ", element[i]});
		ft_parrclean(&element);
		exit(EXIT_FAILURE);
	}
}

static t_num get_scale(char **element, int i, int lineno)
{
	char		**numbers;
	int			fov;
	t_num		scale;

	numbers = get_numbers(element, i, lineno, 1);
	fov = get_int(element, numbers, 0, lineno);
	ft_parrclean(&numbers);
	verify_fov(element, i, lineno, fov);					// verify if in 0 to 180 range
	scale = tan(0.5 * (fov * M_PI / 180.0));				// convert degrees to rad (fov * M_PI / 180.0) and half ( * 0.5)??
	return (scale);
}

// get right vector for camera
static t_vector get_right(t_vector forward)
{
	t_vector	world_up;

	world_up = (t_vector){0, 1, 0};					// pick +Y as world up
	// if forward and wolrd_up to mach aligned choose another direction
	// for strong cross calculations (vectors should be close to perpendicular)
	// we do not chang global world_up it is stil +Y but here we change as hack
	if (fabs(dot(forward, world_up)) > 0.999)
		world_up = (t_point){0, 0, 1};
	return (cross(forward, world_up));
}

// get cross of right and forward
static t_vector get_up(t_vector right, t_vector forward)
{
	return (cross(right, forward));
}

// max 3 attrs / we have only 3 attributes for the camera
//
void	parse_camera(char **element, t_scene *scene, int lineno)
{
	verify_uniqueness(element, &scene->camera.status, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->camera.position = get_point(element, 1, lineno);
	scene->camera.forward = get_vector(element, 2, lineno);
	scene->camera.scale = get_scale(element, 3, lineno); 		// verify fov and convert to scale
	scene->camera.right = get_right(scene->camera.forward);
	scene->camera.up = get_up(scene->camera.right, scene->camera.forward);
	scene->camera.ratio = (double)WIDTH / (double)HEIGHT;
}
