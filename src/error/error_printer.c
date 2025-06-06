/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:03:37 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 07:53:36 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	puterr(char *str)
{
	if (write(STDERR_FILENO, str, ft_strlen(str)) == ERROR)
		exit(EXIT_FAILURE);
}

void	err(int lineno, t_m msg)
{
	char	*str;

	puterr("Error\n");
	if (lineno > 0)
	{
		str = ft_itoa(lineno);
		if (str == NULL)
		{
			err(Z, (t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
		puterr("line ");
		puterr(str);
		puterr(": ");
		free(str);
	}
	while (*msg != NULL)
	{
		puterr(*msg);
		msg++;
	}
	puterr("\n");
	return ;
}
