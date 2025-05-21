/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:13:19 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 12:32:45 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

	element = ft_split(line, " \r\f\v\t\n");
	free(line);
	if (element == NULL)						// malloc failed
	{
		err(Z, (t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	return (element);
}


static void	parse_line(char *line, t_scene *scene, int	lineno)
{
	char **element;							// element attributes

	if (is_empty_line(line))				// skip empty line
		return ;
	element = get_element(line);			// split line to each attribute of the element
	parse_element(element, scene, lineno);
}

// get each line from file and parse to get element attributes filled
static void load_elements(t_scene *scene)
{
	char	*line;
	int		lineno;

	line = PTR_INIT;
	lineno = 0;
	while (line)
	{
		line = get_next_line(scene->file);	// "\n\0" -- for line which is only new line
		if (errno == ENOMEM)				// check for errno == ENOMEM if malloc failed
		{
			err(Z, (t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
		lineno++;
		if (line)
			parse_line(line, scene, lineno);
	}
	er_close(scene->file);					// close fd of file
}

void parse(int argc, char **argv, t_scene *scene)
{
	validate_argument(argc, argv);
	load_elements(scene);			// get each line, parse and load to corresponding struct
}
