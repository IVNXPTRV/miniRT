/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vector3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:41:09 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 16:40:13 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/parser.h"

// Do validation that it is "x,y,z";
// and not "x,,y,z" or any other weird inputs
static int	is_valid_triplet(char *str)
{
	int	i;

	if (*str == ',')
		return (FALSE);
	i = 2;
	while (i--)
	{
		str = ft_strchr(str, ',');
		if (str == NULL)
			return (FALSE);
		str++;
		if (*str == ',' || *str == '\0')
			return (FALSE);
	}
	str = ft_strchr(str, ',');
	return (str == NULL);
}

int	parse_int_vector3(char *str, int values[3])
{
	char	**arr;
	char	*end_ptr;
	int		i;

	if (!is_valid_triplet(str))
		return (ERROR);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		values[i] = ft_strtol(arr[i], &end_ptr);
		if (*end_ptr != '\0')
		{
			free_array(arr);
			return (ERROR);
		}
		i++;
	}
	free_array(arr);
	return (SUCCESS);
}

int	parse_vector3(char *str, double values[3])
{
	char	**arr;
	char	*end_ptr;
	int		i;

	if (!is_valid_triplet(str))
		return (ERROR);
	arr = ft_split(str, ',');
	if (arr == NULL)
		return (ERROR);
	i = 0;
	while (i < 3)
	{
		values[i] = ft_strtod(arr[i], &end_ptr);
		if (*end_ptr != '\0')
		{
			free_array(arr);
			return (ERROR);
		}
		i++;
	}
	free_array(arr);
	return (SUCCESS);
}
