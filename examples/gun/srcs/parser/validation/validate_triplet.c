/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_triplet.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:42:59 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 11:10:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../../includes/parser.h"

int	is_valid_color(char *rgb_str)
{
	int	rgb[3];

	if (parse_int_vector3(rgb_str, rgb) != SUCCESS)
		return (FALSE);
	if (!is_in_range(0, 255, rgb[0])
		|| !is_in_range(0, 255, rgb[1])
		|| !is_in_range(0, 255, rgb[2]))
		return (FALSE);
	return (TRUE);
}

// TODO: Find DOUBLE_MIN instead of LONG_MIN???
int	is_valid_pos(char *pos_str)
{
	double	xyz[3];

	if (parse_vector3(pos_str, xyz) != SUCCESS)
		return (FALSE);
	return (TRUE);
}

int	is_valid_normal(char *normal_str)
{
	double	xyz[3];

	if (parse_vector3(normal_str, xyz) != SUCCESS)
		return (FALSE);
	if ((0 == xyz[0] && xyz[0] == xyz[1] && xyz[1] == xyz[2])
		|| !is_in_rangef(-1, 1, xyz[0])
		|| !is_in_rangef(-1, 1, xyz[1])
		|| !is_in_rangef(-1, 1, xyz[2]))
		return (FALSE);
	return (TRUE);
}
