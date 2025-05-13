/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:19:15 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/27 22:34:38 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#define COUNTS_BUFFER_SIZE 7

static t_parse_result	validate_line(char **line, t_scene_type type)
{
	if (type == SCENE_AMBIENT)
		return (validate_ambient(line));
	else if (type == SCENE_CAMERA)
		return (validate_camera(line));
	else if (type == SCENE_LIGHT)
		return (validate_light(line));
	else if (type == SCENE_SPHERE)
		return (validate_sphere(line));
	else if (type == SCENE_PLANE)
		return (validate_plane(line));
	else if (type == SCENE_CYLINDER)
		return (validate_cylinder(line));
	else
		return (INVALID_OBJECT);
}

static int	validate_individual_objects(int number_of_lines,
				char ***file_tokens)
{
	int				i;
	char			**line;
	t_parse_result	ret;
	t_scene_type	type;

	i = 0;
	while (i < number_of_lines)
	{
		line = file_tokens[i];
		type = identify_scene_type(line[0]);
		ret = validate_line(line, type);
		if (ret != PARSE_OK)
		{
			print_error(ret, type);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

static void	count_objects(int number_of_lines, char ***file_tokens,
				int *counts)
{
	int				i;
	char			**line;
	t_scene_type	type;

	i = 0;
	while (i < number_of_lines)
	{
		line = file_tokens[i];
		type = identify_scene_type(line[0]);
		counts[type]++;
		i++;
	}
}

static int	validate_uniqueness(int *counts)
{
	const t_scene_type	unique_types[] = {
		SCENE_AMBIENT, SCENE_CAMERA, SCENE_LIGHT
	};
	t_scene_type		type;
	int					num_unique;
	int					i;

	num_unique = sizeof(unique_types) / sizeof(unique_types[0]);
	i = 0;
	while (i < num_unique)
	{
		type = unique_types[i];
		if (counts[type] > 1)
		{
			print_error(MORE_THAN_ONE_OBJECT, type);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

int	validate_scene(int num_lines, char ***file_tokens)
{
	int	counts[COUNTS_BUFFER_SIZE];

	ft_bzero(counts, COUNTS_BUFFER_SIZE * sizeof(int));
	count_objects(num_lines, file_tokens, counts);
	if (counts[SCENE_INVALID] > 0)
	{
		print_error(INVALID_OBJECT, SCENE_INVALID);
		return (ERROR);
	}
	if (counts[SCENE_SPHERE] + counts[SCENE_PLANE] + counts[SCENE_CYLINDER]
		> MAX_OBJECTS)
	{
		print_error(TOO_MANY_OBJECTS, SCENE_INVALID);
		return (ERROR);
	}
	if (validate_uniqueness(counts) != SUCCESS
		|| validate_individual_objects(num_lines, file_tokens) != SUCCESS)
		return (ERROR);
	if (counts[SCENE_CAMERA] == 0)
	{
		print_error(NO_ITEM, SCENE_CAMERA);
		return (ERROR);
	}
	return (SUCCESS);
}
