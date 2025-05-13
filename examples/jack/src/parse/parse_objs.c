/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:51:18 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 17:52:43 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_amb(t_amb *amb, char **vec3_color)
{
	amb->color.x = ft_atod(vec3_color[0]);
	amb->color.y = ft_atod(vec3_color[1]);
	amb->color.z = ft_atod(vec3_color[2]);
}

int	parse_amb(char **line, t_sc *sc)
{
	char	**vec3_color;
	int		line_error;

	if (sc->amb.status == 1)
		return (ERR_AMB | ERR_DUB);
	sc->amb.status = 1;
	if (arr_len(line) != 3)
		return (ERR_OAMB | ERR_OOR);
	if (run_line(line[1]))
		return (ERR_OAMB | ERR_FERR);
	sc->amb.ratio = ft_atod(line[1]);
	vec3_color = ft_split(line[2], ",");
	if (!vec3_color)
		return (ERR_ALLOC);
	line_error = check_digit(vec3_color);
	if (arr_len(vec3_color) != 3 || line_error)
	{
		ft_free_split(vec3_color);
		if (line_error)
			return (ERR_OAMB | ERR_FERR);
		return (ERR_OAMB | ERR_OOR);
	}
	fill_amb(&(sc)->amb, vec3_color);
	ft_free_split(vec3_color);
	return (0);
}

int	parse_cam(char **line, t_sc *sc)
{
	t_temp	*temp;
	int		error;

	if (sc->cam.status == 1)
		return (ERR_CAM | ERR_DUB);
	sc->cam.status = 1;
	if (arr_len(line) != 4)
		return (ERR_OCAM | ERR_OOR);
	if (run_line(line[3]))
		return (ERR_OCAM | ERR_FERR);
	sc->cam.fov = ft_atod(line[3]);
	get_temp(line, C, &temp);
	if (!temp)
		return (ERR_ALLOC);
	error = check_digit(temp->vec3_norm) || check_digit(temp->vec3_pos);
	if (arr_len(temp->vec3_pos) != 3 || arr_len(temp->vec3_norm) != 3 || error)
	{
		free_temp(temp);
		if (error)
			return (ERR_OCAM | ERR_FERR);
		return (ERR_OCAM | ERR_OOR);
	}
	fill_cam(&(sc)->cam, temp);
	free_temp(temp);
	return (0);
}

void	fill_light(t_light *light, t_temp *temp)
{
	light->position.x = ft_atod(temp->vec3_pos[0]);
	light->position.y = ft_atod(temp->vec3_pos[1]);
	light->position.z = ft_atod(temp->vec3_pos[2]);
	light->color.x = ft_atod(temp->vec3_color[0]);
	light->color.y = ft_atod(temp->vec3_color[1]);
	light->color.z = ft_atod(temp->vec3_color[2]);
}

int	parse_light(char **line, t_sc *sc)
{
	t_temp	*temp;
	int		error;

	if (sc->light.status == 1)
		return (ERR_LIGHT | ERR_DUB);
	sc->light.status = 1;
	if (arr_len(line) != 4)
		return (ERR_OLIGHT | ERR_OOR);
	get_temp(line, L, &temp);
	if (!temp)
		return (ERR_ALLOC);
	error = check_digit(temp->vec3_color) || check_digit(temp->vec3_pos);
	if (arr_len(temp->vec3_pos) != 3 || arr_len(temp->vec3_color) != 3 || error)
	{
		free_temp(temp);
		if (error)
			return (ERR_OLIGHT | ERR_FERR);
		return (ERR_OLIGHT | ERR_OOR);
	}
	fill_light(&(sc)->light, temp);
	free_temp(temp);
	if (run_line(line[2]))
		return (ERR_OLIGHT | ERR_FERR);
	sc->light.ratio = ft_atod(line[2]);
	return (0);
}
