/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify_scene_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:46:13 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/25 22:27:16 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

t_scene_type	identify_scene_type(char *id)
{
	if (ft_strcmp(id, "A") == 0)
		return (SCENE_AMBIENT);
	if (ft_strcmp(id, "C") == 0)
		return (SCENE_CAMERA);
	if (ft_strcmp(id, "L") == 0)
		return (SCENE_LIGHT);
	if (ft_strcmp(id, "sp") == 0)
		return (SCENE_SPHERE);
	if (ft_strcmp(id, "pl") == 0)
		return (SCENE_PLANE);
	if (ft_strcmp(id, "cy") == 0)
		return (SCENE_CYLINDER);
	return (SCENE_INVALID);
}
