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

static void	verify_fov(char **element, int i, int lineno, int fov)
{
	if (!is_in_range((double)fov, 1, 179))
	{
		err(lineno, (t_m){"fov is beyond 0 to 180 range -> ", element[i]});
		ft_parrclean(&element);
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
}

static t_num	get_scale(char **element, int i, int lineno)
{
	char	**numbers;
	int		fov;
	t_num	scale;

	numbers = get_numbers(element, i, lineno, 1);
	fov = get_int(element, numbers, 0, lineno);
	ft_parrclean(&numbers);
	verify_fov(element, i, lineno, fov);
	scale = tan(0.5 * (fov * M_PI / 180.0));
	return (scale);
}

static t_vector	get_right(t_vector forward)
{
	t_vector	world_up;

	world_up = (t_vector){0, 1, 0};
	if (fabs(dot(forward, world_up)) > 0.999)
		world_up = (t_point){0, 0, 1};
	return (cross(forward, world_up));
}

static t_vector	get_up(t_vector right, t_vector forward)
{
	return (cross(right, forward));
}

void	parse_camera(char **element, t_scene *scene, int lineno)
{
	verify_uniqueness(element, &scene->camera.status, lineno);
	verify_attrs_number(element, 3, lineno);
	scene->camera.position = get_point(element, 1, lineno);
	scene->camera.forward = get_vector(element, 2, lineno);
	scene->camera.scale = get_scale(element, 3, lineno);
	scene->camera.right = get_right(scene->camera.forward);
	scene->camera.up = get_up(scene->camera.right, scene->camera.forward);
	scene->camera.ratio = (double)WIDTH / (double)HEIGHT;
}
