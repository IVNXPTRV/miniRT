/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objs2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:51:32 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 16:32:59 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	fill_field(t_objs *obj, t_temp *temp)
{
	if (arr_len(temp->vec3_pos) != 3 || arr_len(temp->vec3_color) != 3)
		return (free_temp(temp));
	obj->position.x = ft_atod(temp->vec3_pos[0]);
	obj->position.y = ft_atod(temp->vec3_pos[1]);
	obj->position.z = ft_atod(temp->vec3_pos[2]);
	obj->color.x = ft_atod(temp->vec3_color[0]);
	obj->color.y = ft_atod(temp->vec3_color[1]);
	obj->color.z = ft_atod(temp->vec3_color[2]);
	if (obj->type == SP)
	{
		free_temp(temp);
		return (0);
	}
	if (arr_len(temp->vec3_norm) != 3)
		return (free_temp(temp));
	obj->norm.x = ft_atod(temp->vec3_norm[0]);
	obj->norm.y = ft_atod(temp->vec3_norm[1]);
	obj->norm.z = ft_atod(temp->vec3_norm[2]);
	free_temp(temp);
	return (0);
}

int	parse_sp(char **line, t_sc *sc)
{
	t_objs	*obj;
	t_temp	*temp;
	int		error;

	error = check_sp(line, &temp);
	if (error)
		return (error);
	obj = malloc(sizeof(t_objs));
	if (!obj)
	{
		free_temp(temp);
		return (ERR_ALLOC);
	}
	init_obj(obj);
	obj->type = SP;
	obj->diameter = ft_atod(line[2]);
	ft_lstadd_back(&(sc)->head, ft_lstnew((void *)obj));
	if (fill_field(obj, temp))
		return (ERR_SP | ERR_OOR);
	return (0);
}

int	parse_pl(char **line, t_sc *sc)
{
	t_objs	*obj;
	t_temp	*temp;
	int		error;

	error = check_pl(line, &temp);
	if (error)
		return (error);
	obj = malloc(sizeof(t_objs));
	if (!obj)
	{
		free_temp(temp);
		return (ERR_ALLOC);
	}
	init_obj(obj);
	obj->type = PL;
	ft_lstadd_back(&(sc)->head, ft_lstnew((void *)obj));
	if (fill_field(obj, temp))
		return (ERR_PL | ERR_OOR);
	return (0);
}

int	parse_cy(char **line, t_sc *sc)
{
	t_objs	*obj;
	t_temp	*temp;
	int		error;

	error = check_cy(line, &temp);
	if (error)
		return (error);
	obj = malloc(sizeof(t_objs));
	if (!obj)
	{
		free_temp(temp);
		return (ERR_ALLOC);
	}
	init_obj(obj);
	obj->type = CY;
	ft_lstadd_back(&(sc)->head, ft_lstnew((void *)obj));
	obj->height = ft_atod(line[4]);
	obj->diameter = ft_atod(line[3]);
	if (fill_field(obj, temp))
		return (ERR_CY | ERR_OOR);
	return (0);
}
