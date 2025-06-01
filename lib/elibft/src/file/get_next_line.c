/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:18:36 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 14:35:35 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "elibft.h"

char	*pop(t_file **flist, int fd)
{
	t_file	*file;
	t_file	*prev;
	char	*temp_line;

	file = *flist;
	prev = NULL;
	while (file)
	{
		if (file->fd == fd)
			break ;
		prev = file;
		file = file->next;
	}
	if (!file)
		return (NULL);
	temp_line = file->line;
	if (prev)
		prev->next = file->next;
	else
		*flist = file->next;
	file->line = NULL;
	free(file);
	return (temp_line);
}

t_file	*search_file(t_file **flist, int fd)
{
	t_file	*file;
	t_file	*prev;

	file = *flist;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		prev = file;
		file = file->next;
	}
	file = malloc(sizeof(t_file));
	if (!file)
		return (NULL);
	file->fd = fd;
	file->bytes = 0;
	file->blen = 0;
	file->line = NULL;
	file->llen = 0;
	file->next = NULL;
	if (!*flist)
		*flist = file;
	else
		prev->next = file;
	return (file);
}

char	*append_buffer_to_line(t_file *file)
{
	ssize_t	len;
	char	*old;
	int		j;

	len = 0;
	while (len < (file->bytes - file->blen) && file->buf[file->blen
			+ len++] != '\n')
		;
	old = file->line;
	file->line = (char *)malloc(sizeof(char) * (file->llen + len + 1));
	if (!file->line)
		return (free(old), NULL);
	j = -1;
	while (old && old[++j])
		file->line[j] = old[j];
	while (len--)
		file->line[file->llen++] = file->buf[file->blen++];
	free(old);
	file->line[file->llen] = '\0';
	return (file->line);
}

char	*get_next_line(int fd)
{
	static t_file	*flist;
	t_file			*file;
	char			*temp;

	file = search_file(&flist, fd);
	if (!file || fd < 0 || BUFFER_SIZE <= 0)
		return (pop(&flist, fd), NULL);
	while (1)
	{
		if (file->blen == file->bytes)
		{
			file->bytes = read(fd, file->buf, BUFFER_SIZE);
			file->blen = 0;
		}
		if (file->bytes == 0)
			return (pop(&flist, fd));
		else if (file->bytes < 0)
			return (pop(&flist, fd), NULL);
		if (!append_buffer_to_line(file))
			return (pop(&flist, fd), NULL);
		if (file->line[file->llen - 1] == '\n' || file->bytes < BUFFER_SIZE)
			return (file->llen = 0, temp = file->line, file->line = NULL, temp);
	}
	return (NULL);
}
