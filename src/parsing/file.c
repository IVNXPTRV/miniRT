/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:13:52 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 14:36:42 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void validate_synopsis(int argc)
{
	if (argc != 2)
	{
		err(Z, (t_m){"minirt: wrong number of arguments; program accepts exactly 1 argument"});
		exit(EXIT_FAILURE);
	}
}

static void validate_filename(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);

	if (len < 4 || !is_eqlstr(".rt", filename + (len - 3)))
	{
		err(Z, (t_m){"minirt: wrong filename; file should end with .rt extention"});
		exit(EXIT_FAILURE);
	}
}

// open automaticaly check read permissions
// open automaticaly checks if file exist
// read checks if path is not directory
static void validate_file(char *filename, t_scene *scene)
{
	char buf[1];

	scene->file = open(filename, O_RDONLY);
	if (scene->file == ERROR)									// check if file exist and has read permissions
	{
		err(Z, (t_m){"open: ", strerror(errno)});
		exit(EXIT_FAILURE);
	}
    if (read(scene->file, buf, 1) == ERROR)						// check if opened file is directory
	{
		err(Z, (t_m){"open: ", strerror(errno)});
        close(scene->file);
        exit(EXIT_FAILURE);
    }
	er_close(scene->file);
	scene->file = open(filename, O_RDONLY);						// open again to move offset back to 0 to read from begining
	if (scene->file == ERROR)
	{
		err(Z, (t_m){"open: ", strerror(errno)});
		exit(EXIT_FAILURE);
	}
}

void validate_argument(int argc, char **argv, t_scene *scene)
{
	validate_synopsis(argc);		// if only one arg
	validate_file(argv[1], scene);			// if correct rights and possible to open
	validate_filename(argv[1]);		// ends with .rt
}
