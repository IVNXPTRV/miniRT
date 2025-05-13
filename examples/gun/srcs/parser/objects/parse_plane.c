/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:31:04 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 11:21:26 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

t_parse_result	validate_plane(char **line)
{
	if (array_length(line) != 4)
		return (BAD_NUMBER_OF_PARAMS);
	if (!is_valid_pos(line[1]))
		return (BAD_POSITION);
	if (!is_valid_normal(line[2]))
		return (BAD_NORMAL);
	if (!is_valid_color(line[3]))
		return (BAD_COLOR);
	return (PARSE_OK);
}

int	parse_plane(char **line, t_world *world)
{
	t_object	*object;

	object = malloc(sizeof(t_object));
	if (object == NULL)
		return (ERROR);
	object->type = PLANE;
	if (parse_vector(line[1], &object->point) < 0)
	{
		free(object);
		return (ERROR);
	}
	if (parse_normal_vector(line[2], &object->normal) < 0)
	{
		free(object);
		return (ERROR);
	}
	if (parse_color(line[3], &object->color) < 0)
	{
		free(object);
		return (ERROR);
	}
	world->objects[world->nb_objects++] = object;
	return (SUCCESS);
}
