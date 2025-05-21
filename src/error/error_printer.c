/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:03:37 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:39:18 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	puterr(char *str)
{
	if (write(STDERR_FILENO, str, ft_strlen(str)) == ERROR)
		exit(EXIT_FAILURE);
}

// print error and exit if finish_program is true
// (t_m){strerror(errno)}
void err(int lineno, t_m msg)
{
	char *str;

	pterr("Error\n");
	if (lineno > 0)
	{
		str = ft_itoa(lineno);
		if (str == NULL)
		{
			err(Z, (t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
		pterr(str);
		pterr(": ");
		free(str);
	}
	while (*msg != NULL)
	{
		pterr(msg);
		msg++;
	}
	pterr("\n");
}
