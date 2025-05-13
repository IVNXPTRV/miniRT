/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:38:18 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/31 14:29:37 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);

static size_t	count_total_length(int n, va_list original_args)
{
	va_list	args;
	size_t	length;
	int		i;
	char	*string;

	va_copy(args, original_args);
	length = 0;
	i = 0;
	while (i < n)
	{
		string = va_arg(args, char *);
		length += ft_strlen(string);
		i++;
	}
	va_end(args);
	return (length);
}

static void	copy_to_string(int n, va_list args, char *joined_string)
{
	int		i;
	size_t	j;
	char	*string;
	size_t	length;

	i = 0;
	j = 0;
	while (i < n)
	{
		string = va_arg(args, char *);
		length = ft_strlen(string);
		ft_memcpy(joined_string + j * sizeof(char), string, length);
		i++;
		j += length;
	}
	joined_string[j] = '\0';
	va_end(args);
}

// takes n char *, and join all of them into a single string (must free)
char	*ft_strjoin_all(int n, ...)
{
	va_list	args;
	size_t	length;
	char	*joined_string;

	va_start(args, n);
	length = count_total_length(n, args);
	joined_string = malloc((length + 1) * sizeof(char));
	if (joined_string == NULL)
	{
		va_end(args);
		return (NULL);
	}
	copy_to_string(n, args, joined_string);
	return (joined_string);
}
