/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:40:47 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/31 14:46:15 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);

static int	char_is_in_set(char c, const char *set)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	replace_all_delims_with_first_delim(
	char *copied_str, const char *delims)
{
	while (*copied_str != '\0')
	{
		if (char_is_in_set(*copied_str, delims))
			*copied_str = delims[0];
		copied_str++;
	}
}

// make a copy of str (so we don't modify the original str), then
//   replace delims[1 ... n - 1] with delims[0]
//   apply ft_split(copied_str, delims[0]) to get the splited words
char	**ft_strtok(char *str, const char *delims)
{
	char	**arr;
	char	*copied_str;

	if (delims == NULL || ft_strlen(delims) == 0)
		return (NULL);
	copied_str = ft_strdup(str);
	if (copied_str == NULL)
		return (NULL);
	replace_all_delims_with_first_delim(copied_str, delims);
	arr = ft_split(copied_str, delims[0]);
	free(copied_str);
	if (arr == NULL)
		return (NULL);
	return (arr);
}
