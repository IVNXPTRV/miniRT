/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:28:49 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/27 14:11:54 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_length;
	size_t	s2_length;
	size_t	new_str_length;
	char	*new_str;

	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	new_str_length = s1_length + s2_length;
	new_str = malloc(new_str_length + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, s1_length);
	ft_memcpy(new_str + s1_length, s2, s2_length);
	new_str[new_str_length] = '\0';
	return (new_str);
}
