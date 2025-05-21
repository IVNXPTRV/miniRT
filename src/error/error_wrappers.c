/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_wrappers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:03:37 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:06:40 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void er_close(int fd)
{
	if (close(fd) == ERROR)
	{
		err(Z, (t_m){"close: fatal error"});
		exit(EXIT_FAILURE);
	}
}

