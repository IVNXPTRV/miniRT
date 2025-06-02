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

static char	**get_element(char *line, t_scene *s)
{
	char	**element;

	element = ft_split(line, " \t\n");
	free(line);
	if (element == NULL)
	{
		err(Z, (t_m){"malloc: fatal error"});
		er_close(s->file);
		exit(EXIT_FAILURE);
	}
	return (element);
}

static void	parse_line(char *line, t_scene *scene)
{
	char	**element;

	if (is_empty_line(line))
		return ;
	element = get_element(line, scene);
	parse_element(element, scene);
}

static void	load_elements(t_scene *scene)
{
	char	*line;

	line = (void *)true;
	scene->lineno = 0;
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
		{
			scene->lineno++;
			parse_line(line, scene);
		}
	}
	er_close(scene->file);
}

void	parse(int argc, char **argv, t_scene *scene)
{
	validate_argument(argc, argv, scene);
	load_elements(scene);
	validate_scene(scene);
}
