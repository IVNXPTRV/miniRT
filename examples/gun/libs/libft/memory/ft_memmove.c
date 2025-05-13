/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:35:09 by nteechar          #+#    #+#             */
/*   Updated: 2024/07/27 14:11:08 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory.h"

void	*ft_memcpy(void *dest, const void *src, size_t n);

static void	copy_from_right_to_left(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dest = (unsigned char *) dest;
	ptr_src = (unsigned char *) src;
	i = n;
	while (i > 0)
	{
		i--;
		ptr_dest[i] = ptr_src[i];
	}
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	if (src < dest)
		copy_from_right_to_left(dest, src, n);
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
