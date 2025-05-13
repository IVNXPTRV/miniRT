/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:30:53 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 22:25:31 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

t_parse_result	validate_camera(char **line)
{
	if (array_length(line) != 4)
		return (BAD_NUMBER_OF_PARAMS);
	if (!is_valid_pos(line[1]))
		return (BAD_POSITION);
	if (!is_valid_normal(line[2]))
		return (BAD_NORMAL);
	if (!is_valid_fov(line[3]))
		return (BAD_FOV);
	return (PARSE_OK);
}

int	parse_camera(char **line, t_world *world)
{
	int	ret;

	ret = parse_vector(line[1], &world->camera.point);
	if (ret < 0)
		return (ERROR);
	ret = parse_normal_vector(line[2], &world->camera.normal);
	if (ret < 0)
		return (ERROR);
	world->camera.deg_fov = parse_fov(line[3]);
	return (SUCCESS);
}
