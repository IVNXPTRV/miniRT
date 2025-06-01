/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:49:57 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 13:46:38 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));
	parse(argc, argv, &scene);
	execute(&scene);
	return (EXIT_SUCCESS);
}
