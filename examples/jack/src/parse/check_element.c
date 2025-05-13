/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:29:55 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 17:55:52 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_temp(t_temp *temp)
{
	int	error;

	error = 0;
	if (!error && temp->vec3_pos)
		error = check_digit(temp->vec3_pos);
	if (!error && temp->vec3_color)
		error = check_digit(temp->vec3_color);
	if (!error && temp->vec3_norm)
		error = check_digit(temp->vec3_norm);
	return (error);
}

int	check_sp(char **line, t_temp **temp)
{
	if (arr_len(line) != 4)
		return (ERR_SP | ERR_OOR);
	get_temp(line, SP, temp);
	if (!*temp)
		return (ERR_ALLOC);
	if (check_temp(*temp) || run_line(line[2]))
	{
		free_temp(*temp);
		return (ERR_SP | ERR_FERR);
	}
	return (0);
}

int	check_pl(char **line, t_temp **temp)
{
	if (arr_len(line) != 4)
		return (ERR_PL | ERR_OOR);
	get_temp(line, PL, temp);
	if (!*temp)
		return (ERR_ALLOC);
	if (check_temp(*temp))
	{
		free_temp(*temp);
		return (ERR_PL | ERR_FERR);
	}
	return (0);
}

int	check_cy(char **line, t_temp **temp)
{
	if (arr_len(line) != 6)
		return (ERR_CY | ERR_OOR);
	get_temp(line, CY, temp);
	if (!*temp)
		return (ERR_ALLOC);
	if (check_temp(*temp) || run_line(line[3]) || run_line(line[4]))
	{
		free_temp(*temp);
		return (ERR_CY | ERR_FERR);
	}
	return (0);
}
