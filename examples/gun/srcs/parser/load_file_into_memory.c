/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_file_into_memory.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:50:24 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/25 11:22:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

#define KEEP_READING 1

static char	*sanitize_line(char *line)
{
	int		i;
	char	*old_line;

	i = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			line[i] = ' ';
		i++;
	}
	old_line = line;
	line = ft_strtrim(line, " ");
	free(old_line);
	if (line == NULL)
		return (NULL);
	return (line);
}

static int	read_one_line(int fd, t_list **node)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		return (SUCCESS);
	line = sanitize_line(line);
	if (line == NULL)
		return (ERROR);
	if (line[0] == '#' || ft_strlen(line) == 0)
	{
		free(line);
		return (KEEP_READING);
	}
	if (!ft_lstnew_add_back(node, line))
	{
		free(line);
		return (ERROR);
	}
	return (KEEP_READING);
}

static int	read_whole_file(int fd, t_list **node)
{
	int		ret;

	ret = KEEP_READING;
	while (ret == KEEP_READING)
	{
		ret = read_one_line(fd, node);
		if (ret == ERROR)
		{
			ft_lstclear(node, free);
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static char	**linked_list_to_array(t_list *node)
{
	size_t	i;
	size_t	len;
	char	**lines;

	len = ft_lstsize(node);
	lines = malloc((len + 1) * sizeof(char *));
	if (lines == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		lines[i] = node->content;
		i++;
		node = node->next;
	}
	lines[len] = NULL;
	return (lines);
}

char	**load_file_into_memory(int fd)
{
	t_list	*node;
	char	**lines;

	node = NULL;
	if (read_whole_file(fd, &node) != SUCCESS)
		return (NULL);
	lines = linked_list_to_array(node);
	ft_lstclear(&node, NULL);
	if (lines == NULL)
		return (NULL);
	return (lines);
}
