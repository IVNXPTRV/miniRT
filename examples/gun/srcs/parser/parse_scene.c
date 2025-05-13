/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:44:17 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/27 23:13:35 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

static t_parse_result	parse_line(char **line, t_scene_type type,
							t_world *world)
{
	if (type == SCENE_AMBIENT)
		return (parse_ambient(line, world));
	else if (type == SCENE_CAMERA)
		return (parse_camera(line, world));
	else if (type == SCENE_LIGHT)
		return (parse_light(line, world));
	else if (type == SCENE_SPHERE)
		return (parse_sphere(line, world));
	else if (type == SCENE_PLANE)
		return (parse_plane(line, world));
	else if (type == SCENE_CYLINDER)
		return (parse_cylinder(line, world));
	else
		return (ERROR);
}

int	parse_scene(int number_of_lines, char ***file_tokens, t_world *world)
{
	int				i;
	char			**line;
	t_scene_type	type;
	int				ret;

	i = 0;
	while (i < number_of_lines)
	{
		line = file_tokens[i];
		type = identify_scene_type(line[0]);
		ret = parse_line(line, type, world);
		if (ret != SUCCESS)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}
