/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:52 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 22:33:03 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

double	parse_ratio(char *ratio_str)
{
	return (ft_atof(ratio_str));
}

int	parse_color(char *rgb_str, int *color)
{
	char	**rgb;

	rgb = ft_split(rgb_str, ',');
	if (rgb == NULL)
		return (ERROR);
	*color = get_rgba(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), 255);
	free_array(rgb);
	return (SUCCESS);
}

int	parse_vector(char *xyz_str, t_vector3 *dest)
{
	char	**xyz;

	xyz = ft_split(xyz_str, ',');
	if (xyz == NULL)
		return (ERROR);
	dest->x = ft_atof(xyz[0]);
	dest->y = ft_atof(xyz[1]);
	dest->z = ft_atof(xyz[2]);
	free_array(xyz);
	return (SUCCESS);
}

int	parse_normal_vector(char *normal_str, t_vector3 *dest)
{
	if (parse_vector(normal_str, dest) != SUCCESS)
		return (ERROR);
	v_normalize_ip(dest);
	return (SUCCESS);
}

int	parse_fov(char *fov_str)
{
	return (ft_atof(fov_str));
}
