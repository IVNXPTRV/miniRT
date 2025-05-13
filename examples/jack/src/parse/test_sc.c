/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:58:32 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 17:58:33 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void	print_obj(void *content)
// {
// 	t_objs	*obj = (t_objs *)content;
// 	printf("------------------------------\n");	
// 	if (obj->type == SP)
// 	{
// 		printf("Type = SP\n");
// 		printf("Diameter = %f\n", obj->diameter);
// 	}
// 	else if (obj->type == PL)
// 	{
// 		printf("Type = PL\n");
// 		printf("Norm x, y, x = %f, %f, %f\n", obj->norm.x, obj->norm.y, obj->norm.z);
// 	}
// 	else if (obj->type == CY)
// 	{
// 		printf("Type = CY\n");
// 		printf("Norm x, y, x = %f, %f, %f\n", obj->norm.x, obj->norm.y, obj->norm.z);
// 		printf("Diameter = %f\n", obj->diameter);
// 		printf("Height = %f\n", obj->height);
// 	}
// 	printf("Postion x, y, z = %f, %f, %f\n", obj->position.x, obj->position.y, obj->position.z);
// 	printf("Color x,y,z = %f, %f, %f\n", obj->color.x, obj->color.y, obj->color.z);
// }

// void	test_sc(t_sc *sc)
// {
// 	printf("Scene Information:\n");
// 	printf("Ambient status = %d\n", sc->amb.status);
// 	printf("Ambient color = %f %f %f\n", sc->amb.color.x, sc->amb.color.y, sc->amb.color.z);
// 	printf("Ambient ratio = %f\n", sc->amb.ratio);
// 	printf("\nCamera Information:\n");
// 	printf("Camera status = %d\n", sc->cam.status);
// 	printf("Camera position = %f %f %f\n", sc->cam.position.x, sc->cam.position.y, sc->cam.position.z);
// 	printf("Camera norm vector = %f %f %f\n", sc->cam.norm.x, sc->cam.norm.y, sc->cam.norm.z);
// 	printf("Camera FOV = %f\n", sc->cam.fov);
// 	printf("\nLight Information:\n");
// 	printf("Light status = %d\n", sc->light.status);
// 	printf("Light position = %f %f %f\n", sc->light.position.x, sc->light.position.y, sc->light.position.z);
// 	printf("Light color = %f %f %f\n", sc->light.color.x, sc->light.color.y, sc->light.color.z);
// 	printf("Light ratio = %f\n", sc->light.ratio);
// 	printf("\nObject Information:\n");
// 	ft_lstiter(sc->head, print_obj);
// 	printf("Number of objects: %d\n", ft_lstsize(sc->head));
// }
