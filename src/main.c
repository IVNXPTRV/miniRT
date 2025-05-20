/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/20 13:55:36 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// print error and exit if finish_program is true
void err(bool finish_program, char *str)
{
	if (write(STDERR_FILENO, str, ft_strlen(str)) == ERROR)
		finish_program = true;
	if (finish_program == true)
		exit(EXIT_FAILURE);
}

void execute(t_scene *scene)
{
	init_graphic_library(scene);	// connect to gl and prepare an image
	compute_image(scene);			// fill all final pixels color
	display_image(scene);			// render an image in an OS window
}

void er_close(int fd)
{
	if (close(fd) == ERROR)
		err(true, "close: fatal error\n");
}

void	parse_line(char *line, t_scene *scene)
{
	char **attrs;						// element attributes

	// free line if fail and exit
	if (is_eqlstr(line, "\n"))			// skip empty line
		return ;



}
// get each line from file and parse to get element attributes filled
void load_elements(t_scene *scene)
{
	char	*line;

	line = PTR_INIT;
	while (line)
	{
		line = get_next_line(scene->file);	// "\n\0" -- for line which is only new line
		if (errno == ENOMEM)				// check for errno == ENOMEM if malloc failed
			err(true, "malloc: fatal error\n");
		if (line)
			parse_line(line, scene);
		free(line);
	}
	er_close(scene->file);					// close fd of file
}

void parse(int argc, char **argv, t_scene *scene)
{
	validate_synopsis(argc);		// if only one arg
	validate_filename(argv[1]);		// ends with .rt
	validate_file(argv[1]);			// if correct rights and possible to open
	load_elements(scene);	// get each line, parse and load to corresponding struct
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
