/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:22:48 by ruzhang           #+#    #+#             */
/*   Updated: 2025/05/13 08:19:30 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt	rt;
	t_sc	sc;

	if (validate(argc, argv, &sc))
		return (1);
	if (init_rt(&rt) < 0)
		return (EXIT_FAILURE);
	render(&rt, &sc);
	mlx_key_hook(rt.mlx, &key_press, &rt);
	mlx_loop(rt.mlx);
	mlx_terminate(rt.mlx);
	ft_lstclear(&(sc).head, free);
	return (0);
}
