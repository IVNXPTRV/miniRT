/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:19:02 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 09:27:27 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	verify_max_obj_num(char **element, t_scene *scene, int lineno)
{
	if (scene->obj_num >= MAX_OBJ)
	{
		err(lineno, (t_m){"reached maximum number of objects"});
		ft_parrclean(&element);
		exit(EXIT_FAILURE);
	}
}

void	verify_uniqueness(char **element, bool *singleton, int lineno)
{
	if (*singleton == true)
	{
		err(lineno, (t_m){"encountered more then one ", element[0]});
		ft_parrclean(&element);
		exit(EXIT_FAILURE);
	}
	*singleton = true;
}

void	verify_attrs_number(char **element, size_t num, int lineno)
{
	if (ft_parrlen(element + 1) != num)
	{
		err(lineno, (t_m){"wrong number of attributes"});
		ft_parrclean(&element);
		exit(EXIT_FAILURE);
	}
}

char	**get_numbers(char **element, int i, int lineno, size_t limit)
{
	char	**numbers;

	numbers = ft_split(element[i], ",");
	if (numbers == NULL)
	{
		ft_parrclean(&element);
		err(Z, (t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	if (ft_parrlen(numbers) != limit)
	{
		err(lineno, (t_m){"wrong number of parameters in an attribute -> ",
			element[i]});
		ft_parrclean(&element);
		ft_parrclean(&numbers);
		exit(EXIT_FAILURE);
	}
	return (numbers);
}

void	parse_element(char **element, t_scene *scene, int lineno)
{
	if (is_eqlstr(element[0], "C"))
		parse_camera(element, scene, lineno);
	else if (is_eqlstr(element[0], "A"))
		parse_ambient(element, scene, lineno);
	else if (is_eqlstr(element[0], "L"))
		parse_light(element, scene, lineno);
	else if (is_eqlstr(element[0], "pl"))
		parse_plane(element, scene, lineno);
	else if (is_eqlstr(element[0], "sp"))
		parse_sphere(element, scene, lineno);
	else if (is_eqlstr(element[0], "cy"))
		parse_cylinder(element, scene, lineno);
	else
	{
		err(lineno, (t_m){"wrong identifier -> ", element[0]});
		ft_parrclean(&element);
		exit(EXIT_FAILURE);
	}
	ft_parrclean(&element);
}
