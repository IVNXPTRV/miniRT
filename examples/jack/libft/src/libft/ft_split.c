/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:22:56 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/03 22:00:02 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (c == '\0');
}

static int	ft_word_count(char *str, char *charset)
{
	int	word_count;
	int	in_word;

	word_count = 0;
	in_word = 0;
	while (*str)
	{
		if (ft_is_charset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			word_count++;
		}
		str++;
	}
	return (word_count);
}

static char	*ft_create_word(char *str, char *charset)
{
	int		len;
	int		i;
	char	*result;

	len = 0;
	while (str[len] && !ft_is_charset(str[len], charset))
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = str[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

static void	*ft_free_split_charset(char **result, int index)
{
	while (index > 0)
		free(result[--index]);
	free(result);
	return (NULL);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word_count;
	int		index;
	
	word_count = ft_word_count(str, charset);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
	return (NULL);
	index = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset))
			str++;
		if (*str && !ft_is_charset(*str, charset))
		{
			result[index] = ft_create_word(str, charset);
			if (!result[index])
				return (ft_free_split_charset(result, index));
			index++;
			while (*str && !ft_is_charset(*str, charset))
				str++;
		}
	}
	result[index] = NULL;
	return (result);
}
