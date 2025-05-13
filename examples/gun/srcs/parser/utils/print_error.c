/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:16:20 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/27 22:35:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

static char	*get_object_str(t_scene_type type)
{
	const t_scene_type	types[] = {
		SCENE_AMBIENT, SCENE_CAMERA, SCENE_LIGHT,
		SCENE_SPHERE, SCENE_PLANE, SCENE_CYLINDER
	};
	const char			*strings[] = {
		"Ambient light", "Camera", "Light",
		"Sphere", "Plane", "Cylinder"
	};
	int					i;
	int					len;

	i = 0;
	len = sizeof(types) / sizeof(types[0]);
	while (i < len)
	{
		if (type == types[i])
			return ((char *) strings[i]);
		i++;
	}
	return ("");
}

static char	*get_issue_str(t_parse_result ret)
{
	const t_parse_result	res[] = {
		INVALID_OBJECT, TOO_MANY_OBJECTS, MORE_THAN_ONE_OBJECT, NO_ITEM,
		BAD_NUMBER_OF_PARAMS, BAD_RATIO, BAD_COLOR, BAD_POSITION, BAD_NORMAL,
		BAD_FOV, BAD_DIAMETER, BAD_HEIGHT
	};
	const char				*strings[] = {
		"Invalid object id", "Too many objects", "Unique object more than one",
		"Not given when needed", "Invalid number of parameters",
		"Invalid brightness", "Invalid color format", "Invalid position",
		"Invalid normal vector", "Invalid field of view",
		"Invalid diameter", "Invalid height"
	};
	int						i;
	int						len;

	i = 0;
	len = sizeof(res) / sizeof(res[0]);
	while (i < len)
	{
		if (ret == res[i])
			return ((char *) strings[i]);
		i++;
	}
	return ("");
}

void	print_error(t_parse_result ret, t_scene_type type)
{
	char	*object;
	char	*issue;

	object = get_object_str(type);
	issue = get_issue_str(ret);
	printf("Error\n");
	if (ft_strlen(object) > 0)
		printf("%s: ", object);
	printf("%s\n", issue);
}
