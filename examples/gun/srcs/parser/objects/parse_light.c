/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 11:30:57 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 11:20:26 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

t_parse_result	validate_light(char **line)
{
	if (array_length(line) != 4)
		return (BAD_NUMBER_OF_PARAMS);
	if (!is_valid_pos(line[1]))
		return (BAD_POSITION);
	if (!is_valid_ratio(line[2]))
		return (BAD_RATIO);
	if (!is_valid_color(line[3]))
		return (BAD_COLOR);
	return (PARSE_OK);
}

int	parse_light(char **line, t_world *world)
{
	int		ret;
	int		color;
	double	ratio;

	ret = parse_vector(line[1], &world->light.point);
	if (ret != SUCCESS)
		return (ERROR);
	ratio = parse_ratio(line[2]);
	if (parse_color(line[3], &color) != SUCCESS)
		return (ERROR);
	world->light.color = scale_color(color, ratio);
	return (SUCCESS);
}
