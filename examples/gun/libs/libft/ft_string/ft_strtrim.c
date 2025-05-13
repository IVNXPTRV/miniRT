/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:29:55 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/27 14:15:55 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

// *will return 0 if trying to see if '\0' is in set
static int	is_in(char const c, char const *set)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	new_str_length;
	char	*left;
	char	*right;

	left = (char *) s1;
	right = (char *) s1 + ft_strlen(s1) - 1;
	while (is_in(*left, set))
		left++;
	while (is_in(*right, set) && right > left)
		right--;
	if (*left == '\0' && *left == *right)
		new_str_length = 0;
	else
		new_str_length = right - left + 1;
	new_str = malloc(new_str_length + 1);
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, left, new_str_length);
	new_str[new_str_length] = '\0';
	return (new_str);
}
