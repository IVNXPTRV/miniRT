/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_str_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <techazuza@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:29:52 by nteechar          #+#    #+#             */
/*   Updated: 2024/11/26 12:00:46 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static void	free_n_items(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
}

static void	free_till_null(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
}

// - if n > 0: free n items in arr
// - if n == 0: free items until encounter NULL
void	ft_free_str_arr(char **arr, size_t n)
{
	if (n > 0)
		free_n_items(arr, n);
	else
		free_till_null(arr);
	free(arr);
}
