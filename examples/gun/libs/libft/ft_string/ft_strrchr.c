/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:29:57 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/27 13:41:04 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	char	c_;
	char	*ptr;

	c_ = (char) c;
	ptr = NULL;
	while (1)
	{
		if (*s == c_)
			ptr = (char *) s;
		if (*s == '\0')
			break ;
		s++;
	}
	return (ptr);
}
