/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:36:08 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/07 14:23:47 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft.h"

int	get_more_memory(char **queue, size_t *capacity)
{
	char	*temp;
	size_t	length;

	*capacity *= 2;
	temp = malloc(*capacity * sizeof(char));
	if (temp == NULL)
		return (-1);
	length = ft_strlen(*queue);
	ft_memcpy(temp, *queue, length);
	temp[length] = '\0';
	free(*queue);
	*queue = temp;
	return (0);
}

void	cleanup(char **queue, size_t *capacity)
{
	if (*queue)
	{
		free(*queue);
		*queue = NULL;
	}
	*capacity = 0;
}
