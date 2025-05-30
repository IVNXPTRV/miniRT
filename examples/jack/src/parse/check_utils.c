/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:47:37 by jchompoo          #+#    #+#             */
/*   Updated: 2025/05/19 15:25:10 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// is_valid_decimal
// The run_line function checks whether a given string s represents a valid floating-point number with some restrictions
int	run_line(char *s)
{
	int	dot;

	if (!s || *s == '\0')
		return (1);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '\0')
		return (1);
	dot = 0;
	while (*s)
	{
		if ((*s < '0' || *s > '9') && *s != '.')
			return (1);
		if (*s == '.')
			dot += 1;
		s++;
	}
	if (dot > 1)
		return (1);
	return (0);
}

int	check_digit(char **vec3)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (vec3[i] && !error)
	{
		error = run_line(vec3[i]);
		i++;
	}
	return (error);
}

int	validate_amount(t_sc *sc)
{
	if (sc->cam.status != 1)
		return (ERR_NCAM);
	if (sc->light.status != 1)
		return (ERR_NLIGHT);
	return (0);
}
