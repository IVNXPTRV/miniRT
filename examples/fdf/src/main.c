/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2024/12/07 12:23:48 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int32_t	main(int argc, char **argv)
{
	t_imginf	*img;

	if (argc != 2)
	{
		perror("Usage: ./fdf <map_path>");
		return (EXIT_FAILURE);
	}
	img = get_img(argv);
	if (!img)
		return (EXIT_FAILURE);
	boot(img);
	return (EXIT_SUCCESS);
}
