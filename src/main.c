/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/20 14:37:42 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// print error and exit if finish_program is true
// (t_m){strerror(errno)}
void err(bool finish_program, t_m msg)
{
	while (*msg != NULL)
	{
		if (write(STDERR_FILENO, *msg, ft_strlen(msg)) == ERROR)
			finish_program = true;
		msg++;
	}
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
		err(true, (t_m){"close: fatal error\n"});
}

static inline bool is_empty_line(char *line)
{
	if (!is_eqlstr(line, "\n"))
		return (false);
	free(line);
	return (true);
}

static char **get_element(char *line)
{
	char **element;

	element = ft_split(line, " \t\n");
	free(line);
	if (element == NULL)						// malloc failed
		err(true, (t_m){"malloc: fatal error\n"});
	return (element);
}

void	parse_camera(char **element, t_scene *scene)
{
	static bool singleton;			// set to true when first time meet camera element, by desifn initially is false

	if (singleton == true)			// means we've already met camera element
		err(true, (t_m){"minirt: more then one camera element\n"});
	singleton = true;


}
void parse_element(char **element, t_scene *scene)
{
	if (is_eqlstr(element[0], "C"))
		parse_camera(element, scene);
	else if (is_eqlstr(element[0], "A"))
		parse_ambient(element, scene);
	else if (is_eqlstr(element[0], "L"))
		parse_light(element, scene);
	else if (is_eqlstr(element[0], "pl"))
		parse_plane(element, scene);
	else if (is_eqlstr(element[0], "sp"))
		parse_sphere(element, scene);
	else if (is_eqlstr(element[0], "cy"))
		parse_cylinder(element, scene);
	else										// wrong identifier
	{
		ft_parrclean(element);
		err(true, (t_m){"minirt: wrong identifier: ", element[0], "\n"});
	}
}

void	parse_line(char *line, t_scene *scene)
{
	char **element;							// element attributes

	if (is_empty_line(line))				// skip empty line
		return ;
	element = get_element(line);			// split line to each attribute of the element
	parse_element(element, scene);
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
			err(true, (t_m){"malloc: fatal error\n"});
		if (line)
			parse_line(line, scene);
	}
	er_close(scene->file);					// close fd of file
}

void parse(int argc, char **argv, t_scene *scene)
{
	validate_synopsis(argc);		// if only one arg
	validate_filename(argv[1]);		// ends with .rt
	validate_file(argv[1]);			// if correct rights and possible to open
	load_elements(scene);			// get each line, parse and load to corresponding struct
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
