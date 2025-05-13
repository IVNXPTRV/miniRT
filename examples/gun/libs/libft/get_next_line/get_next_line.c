/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 17:11:16 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 15:22:45 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../libft.h"
#include "get_next_line.h"

int		get_more_memory(char **queue, size_t *capacity);
void	cleanup(char **queue, size_t *capacity);

// return -1 if queue cannot be malloc'd
static int	append(char **queue, size_t *capacity,
	char buffer[BUFFER_SIZE], size_t chars_read)
{
	size_t	initial_length;

	if (*queue == NULL)
	{
		*capacity = BUFFER_SIZE;
		*queue = malloc(*capacity * sizeof(char));
		if (*queue == NULL)
			return (-1);
		(*queue)[0] = '\0';
	}
	initial_length = ft_strlen(*queue);
	while (initial_length + chars_read + 1 > *capacity)
	{
		if (get_more_memory(queue, capacity) != 0)
			return (-1);
	}
	ft_memcpy(*queue + initial_length, buffer, chars_read);
	(*queue)[initial_length + chars_read] = '\0';
	return (0);
}

// return last read's chars_read, -1 if error
static int	read_file(int fd, char **queue, size_t *capacity)
{
	char	*buffer;
	ssize_t	chars_read;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	if (buffer == NULL)
		return (-1);
	while (1)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE - 1);
		if (chars_read == -1 || chars_read == 0)
			break ;
		buffer[chars_read] = '\0';
		if (append(queue, capacity, buffer, chars_read) != 0)
		{
			chars_read = -1;
			break ;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (chars_read);
}

static char	*get_line(char **queue, size_t *capacity)
{
	char	*line;
	size_t	line_length;
	size_t	queue_new_length;

	line_length = 0;
	while ((*queue)[line_length] != '\0' && (*queue)[line_length] != '\n')
		line_length++;
	if ((*queue)[line_length] == '\n')
		line_length++;
	line = malloc((line_length + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_memcpy(line, *queue, line_length);
	line[line_length] = '\0';
	queue_new_length = ft_strlen(*queue + line_length);
	ft_memcpy(*queue, *queue + line_length, queue_new_length);
	(*queue)[queue_new_length] = '\0';
	if ((*queue)[0] == '\0')
		cleanup(queue, capacity);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*queue = NULL;
	static size_t	capacity = 0;
	ssize_t			chars_read;
	char			*line;

	if (queue == NULL || ft_strchr(queue, '\n') == NULL)
		chars_read = read_file(fd, &queue, &capacity);
	else
		chars_read = 0;
	if ((chars_read == 0 && (queue == NULL || queue[0] == '\0'))
		|| chars_read == -1)
	{
		cleanup(&queue, &capacity);
		return (NULL);
	}
	line = get_line(&queue, &capacity);
	if (line == NULL)
	{
		cleanup(&queue, &capacity);
		return (NULL);
	}
	return (line);
}
