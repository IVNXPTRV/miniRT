/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/20 15:34:41 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	puterr(char *str)
{
	if (write(STDERR_FILENO, str, ft_strlen(str)) == ERROR)
		exit(EXIT_FAILURE);
}

// print error and exit if finish_program is true
// (t_m){strerror(errno)}
void err(t_m msg)
{
	pterr("Error\n");
	pterr("minirt: ");
	while (*msg != NULL)
	{
		pterr(msg);
		msg++;
	}
	pterr("\n");
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
	{
		err((t_m){"close: fatal error"});
		exit(EXIT_FAILURE);
	}
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
	{
		err((t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	return (element);
}

void veriy_uniqueness(char **element, bool *singleton)
{
	if (*singleton == true)			// means we've already met this element in a file
	{
		err((t_m){"encountered more then one ", element[0]});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
	*singleton = true;
}

void verify_attrs_number(char **element, int num)
{
	if (ft_parrlen(element + 1) != num)
	{
		err((t_m){element[0], "has wrong number of attributes"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}


char **get_numbers(char **element, int i)
{
	char	**numbers;

	numbers = ft_split(element[i], ",");
	if (numbers == NULL)						// malloc failed
	{
		ft_parrclean(element);
		err((t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	if (ft_parrlen(numbers) != 3)				// if len of result != 3
	{
		err((t_m){"wrong number of parameters in an attribute -> ", element[i]});
		ft_parrclean(element);
		ft_parrclean(numbers);
		exit(EXIT_FAILURE);
	}
	return (numbers);
}

// i -- index of certain attribute of the element
void verify_point_correctness(char **element, int i)
{
	char	**numbers;

	numbers = get_numbers(element, i);


}

// max 3 attrs / we have only 3 attributes for the camera
//
void	parse_camera(char **element, t_scene *scene)
{
	static bool singleton;				// set to true when first time meet camera element, by desifn initially is false

	verify_uniqueness(element, &singleton);
	verify_attrs_number(element, 3);
	\
	verify_point_correctness(element, 1);
	verify_vector_correctness(element, 2);
	verify_fov_correctness(element, 3);
	// validate each attr and fill t_camera struct

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
		err((t_m){"wrong identifier -> ", element[0]});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
	ft_parrclean(element);
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
		{
			err((t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
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
