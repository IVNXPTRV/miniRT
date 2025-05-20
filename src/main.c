/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/20 12:25:04 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void execute(t_scene *scene)
{
	init_graphic_library(scene);	// connect to gl and prepare an image
	compute_image(scene);			// fill all final pixels color
	display_image(scene);			// render an image in an OS window
}

void load_elements_to_scene(t_scene *scene)
{
	char *line;

	line = PTR_INIT;
	while (line)
	{
		line = get_next_line(scene->file);
		if (line)
			parse_element(line, scene);
	}

}

void parse(int argc, char **argv, t_scene *scene)
{
	validate_synopsis(argc);		// if only one arg
	validate_filename(argv[1]);		// ends with .rt
	validate_file(argv[1]);			// if correct rights and possible to open
	load_elements_to_scene(scene);	// get each line, parse and load to corresponding struct
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));	// init scene with zeroes
	\
	parse(argc, argv, &scene); 			// deserialize
	execute(&scene);					// render: init graphic library, get_image, display window with image
	\
	return (EXIT_SUCCESS);

	// validate

	// parse
	// execute

	// clean
	// exit
}
