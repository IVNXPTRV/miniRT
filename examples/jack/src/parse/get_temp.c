/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_temp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:50:34 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 16:51:20 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	assign_vec3_norm(t_temp *temp, char **line, t_type type)
{
	if (type == PL || type == CY || type == C)
	{
		temp->vec3_norm = ft_split(line[2], ",");
		if (!temp->vec3_norm)
		{
			free_temp(temp);
			return (0);
		}
	}
	else
		temp->vec3_norm = NULL;
	return (1);
}

static int	assign_vec3_color(t_temp *temp, char **line, t_type type)
{
	if (type == C)
	{
		temp->vec3_color = NULL;
		return (1);
	}
	temp->vec3_color = ft_split(line[arr_len(line) - 1], ",");
	if (!temp->vec3_color)
	{
		free_temp(temp);
		return (0);
	}
	return (1);
}

void	get_temp(char **line, t_type type, t_temp **temp)
{
	*temp = malloc(sizeof(t_temp));
	if (!*temp)
		return ;
	(*temp)->vec3_pos = ft_split(line[1], ",");
	if (!(*temp)->vec3_pos)
	{
		free_temp(*temp);
		return ;
	}
	if (!assign_vec3_norm(*temp, line, type)
		|| !assign_vec3_color(*temp, line, type))
	{
		free_temp(*temp);
		return ;
	}
}
