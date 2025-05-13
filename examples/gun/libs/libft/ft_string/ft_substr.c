/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:15:06 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/27 14:16:07 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);

static char	*allocate_memory(size_t s_length, unsigned int start, size_t len)
{
	size_t	size;

	if (start >= s_length)
		size = 1;
	else if (start + len >= s_length)
		size = s_length - start + 1;
	else
		size = len + 1;
	return (malloc(size));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	s_length;
	size_t	i;
	size_t	j;

	s_length = ft_strlen(s);
	new_str = allocate_memory(s_length, start, len);
	if (new_str == NULL)
		return (NULL);
	if (start >= s_length)
	{
		new_str[0] = '\0';
		return (new_str);
	}
	i = 0;
	j = start;
	while (i < len && s[j] != '\0')
	{
		new_str[i] = s[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
