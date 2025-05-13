/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_to_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:48:00 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/26 16:12:26 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include "../../includes/parser.h"

static int	is_rt_file_extension(char *filename)
{
	char	*dot_ptr;
	char	*slash_ptr;
	int		name_len;

	dot_ptr = ft_strrchr(filename, '.');
	if (dot_ptr == NULL)
		return (FALSE);
	slash_ptr = ft_strrchr(filename, '/');
	if (slash_ptr)
		name_len = dot_ptr - (slash_ptr + 1);
	else
		name_len = dot_ptr - filename;
	if (name_len == 0)
		return (FALSE);
	return (ft_strcmp(dot_ptr, ".rt") == 0);
}

static int	open_file(char *filename)
{
	int	fd;

	if (!is_rt_file_extension(filename))
	{
		printf("Error\nNot a .rt file\n");
		return (ERROR);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		if (errno == ENOENT)
			printf("Error\nFile does not exist\n");
		else if (errno == EACCES)
			printf("Error\nPermission denied\n");
		else
			printf("Error\nCannot open file (%s)\n", strerror(errno));
		return (ERROR);
	}
	return (fd);
}

static char	***split_lines(char **lines)
{
	int		number_of_lines;
	char	***tokens;
	int		i;

	number_of_lines = array_length(lines);
	tokens = malloc((number_of_lines + 1) * sizeof(char **));
	if (tokens == NULL)
		return (NULL);
	i = 0;
	while (i < number_of_lines)
	{
		tokens[i] = ft_split(lines[i], ' ');
		if (tokens[i] == NULL)
			free_tokens(tokens);
		i++;
	}
	tokens[number_of_lines] = NULL;
	return (tokens);
}

int	read_file_to_world(char *filename, t_world *world)
{
	int		fd;
	char	**lines;
	int		number_of_lines;
	char	***file_tokens;

	fd = open_file(filename);
	if (fd < 0)
		return (ERROR);
	lines = load_file_into_memory(fd);
	if (lines == NULL)
		return (ERROR);
	number_of_lines = array_length(lines);
	file_tokens = split_lines(lines);
	free_array(lines);
	if (file_tokens == NULL)
		return (ERROR);
	if (validate_scene(number_of_lines, file_tokens) != SUCCESS
		|| parse_scene(number_of_lines, file_tokens, world) != SUCCESS)
	{
		free_tokens(file_tokens);
		return (ERROR);
	}
	free_tokens(file_tokens);
	return (SUCCESS);
}
