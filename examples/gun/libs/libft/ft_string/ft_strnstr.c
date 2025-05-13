/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:39:24 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/31 16:06:31 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_length;

	little_length = ft_strlen(little);
	if (little_length == 0)
		return ((char *) big);
	if (len < little_length)
		return (NULL);
	i = 0;
	while (little_length + i <= len && big[i] != '\0')
	{
		if (ft_memcmp(big + i, little, little_length) == 0)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
