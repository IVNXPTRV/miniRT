/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:13:19 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/27 11:45:40 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline bool	is_empty_line(char *line)
{
	if (!is_eqlstr(line, "\n") && !is_eqlchar(line[0], '#'))
		return (false);
	free(line);
	return (true);
}

static char	**get_element(char *line)
{
	char	**element;

	element = ft_split(line, " \t\n");
	free(line);
	if (element == NULL)
	{
		err(Z, (t_m){"malloc: fatal error"});
		er_close(scene->file);
		exit(EXIT_FAILURE);
	}
	return (element);
}

static void	parse_line(char *line, t_scene *scene, int lineno)
{
	char	**element;

	if (is_empty_line(line))
		return ;
	element = get_element(line);
	parse_element(element, scene, lineno);
}

static void	load_elements(t_scene *scene)
{
	char	*line;
	int		lineno;

	line = (void *)true;
	lineno = 0;
	while (line)
	{
		line = get_next_line(scene->file);
		if (errno == ENOMEM)
		{
			err(Z, (t_m){"malloc: fatal error"});
			er_close(scene->file);
			exit(EXIT_FAILURE);
		}
		if (line)
			parse_line(line, scene, ++lineno);
	}
	er_close(scene->file);
}

void	parse(int argc, char **argv, t_scene *scene)
{
	validate_argument(argc, argv, scene);
	load_elements(scene);
	validate_scene(scene);
}
