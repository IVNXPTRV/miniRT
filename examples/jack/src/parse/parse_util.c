/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:49:06 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/05 14:11:16 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_obj(t_objs *obj)
{
	obj->color.x = 0;
	obj->color.y = 0;
	obj->color.z = 0;
	obj->norm.x = 0;
	obj->norm.y = 0;
	obj->norm.z = 0;
	obj->position.x = 0;
	obj->position.y = 0;
	obj->position.z = 0;
	obj->height = 0;
	obj->diameter = 0;
}

int	free_temp(t_temp *temp)
{
	if (temp->vec3_color)
		ft_free_split(temp->vec3_color);
	if (temp->vec3_norm)
		ft_free_split(temp->vec3_norm);
	if (temp->vec3_pos)
		ft_free_split(temp->vec3_pos);
	free(temp);
	return (1);
}

int	arr_len(char **line)
{
	int	i;

	i = 0;
	while (*line)
	{
		i++;
		line++;
	}
	return (i);
}

void	init_sc(t_sc *sc)
{
	sc->amb.status = 0;
	sc->amb.color.x = 0;
	sc->amb.color.y = 0;
	sc->amb.color.z = 0;
	sc->amb.ratio = 0;
	sc->cam.status = 0;
	sc->cam.fov = 0;
	sc->cam.position.x = 0;
	sc->cam.position.y = 0;
	sc->cam.position.z = 0;
	sc->cam.norm.x = 0;
	sc->cam.norm.y = 0;
	sc->cam.norm.z = 0;
	sc->light.status = 0;
	sc->light.color.x = 0;
	sc->light.color.y = 0;
	sc->light.color.z = 0;
	sc->light.position.x = 0;
	sc->light.position.y = 0;
	sc->light.position.z = 0;
	sc->light.ratio = 0;
	sc->head = NULL;
}

int	in_range(double x, int type)
{
	double	min;
	double	max;

	if (type == 'n')
		min = -1.0;
	else
		min = 0.0;
	if (type == 'r' || type == 'n')
		max = 1.0;
	else if (type == 'c')
		max = 255.0;
	else if (type == 'f')
		max = 180.0;
	if (x >= min && x <= max)
		return (0);
	return (1);
}
