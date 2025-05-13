/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:51:17 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:19:38 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

bool	is_valid_file(char *filename, int *fd)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		perror("Invalid filename!");
		return (false);
	}
	if (!is_eqlstr(filename + (len - 4), ".fdf"))
	{
		perror("Invalid filename!");
		return (false);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		perror("File not exist!");
		return (false);
	}
	return (true);
}
