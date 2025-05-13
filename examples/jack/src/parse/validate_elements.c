/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:49:01 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 15:35:14 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_amb(t_amb *amb)
{
	int	error;

	error = in_range(amb->ratio, 'r');
	error |= in_range(amb->color.x, 'c');
	error |= in_range(amb->color.y, 'c');
	error |= in_range(amb->color.z, 'c');
	if (error)
		return (ERR_OAMB | ERR_OOR);
	return (0);
}

int	validate_cam(t_cam *cam)
{
	int	error;

	error = in_range(cam->fov, 'f');
	error |= in_range(cam->norm.x, 'n');
	error |= in_range(cam->norm.y, 'n');
	error |= in_range(cam->norm.z, 'n');
	if (error)
		return (ERR_OCAM | ERR_OOR);
	return (0);
}

int	validate_light(t_light *light)
{
	int	error;

	error = in_range(light->ratio, 'r');
	error |= in_range(light->color.x, 'c');
	error |= in_range(light->color.y, 'c');
	error |= in_range(light->color.z, 'c');
	if (error)
		return (ERR_OLIGHT | ERR_OOR);
	return (0);
}

int	validate_elements(t_sc *sc)
{
	int	error;

	error = validate_amb(&(sc)->amb);
	error |= validate_cam(&(sc)->cam);
	error |= validate_light(&(sc)->light);
	error |= validate_objs(sc->head);
	return (error);
}
