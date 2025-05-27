/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:49:57 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 11:57:13 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void dbg_print_elements(t_scene scene)
{

}

int	main(int argc, char **argv)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));	// init scene with zeroes
	\
	parse(argc, argv, &scene); 			// deserialize
	dbg_print_elements(scene);
	execute(&scene);					// render: init graphic library, get_image, display window with image

	// (void)argc;
	// int fd = open(argv[1], O_RDONLY);
	// printf("line: %s\n", get_next_line(fd));
	return (EXIT_SUCCESS);
	// validate

	// parse
	// execute

	// clean
	// exit
}
