/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:21:06 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/16 21:30:20 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free_str_arr(char **arr, size_t n);

// count words to malloc char pointers
static size_t	count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (1)
	{
		while (*s == c && *s != '\0')
			s++;
		if (*s == '\0')
			break ;
		words++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (words);
}

// get the word up to (not including) c
static char	*get_word(char const *s, char c)
{
	size_t	length;
	char	*word;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	word = malloc(sizeof(char) * (length + 1));
	if (word == NULL)
		return (NULL);
	ft_strlcpy(word, s, length + 1);
	return (word);
}

// fill every malloc'd entry with a word in s, clean up memory if malloc error
static void	fill_arr(char **arr, size_t words, char const *s, char c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (i < words)
	{
		while (*s == c && *s != '\0')
			s++;
		word = get_word(s, c);
		if (word == NULL)
		{
			ft_free_str_arr(arr, i);
			return ;
		}
		arr[i] = word;
		i++;
		while (*s != c && *s != '\0')
			s++;
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	number_of_words;

	number_of_words = count_words(s, c);
	arr = malloc(sizeof(char *) * (number_of_words + 1));
	if (arr == NULL)
		return (NULL);
	fill_arr(arr, number_of_words, s, c);
	return (arr);
}
