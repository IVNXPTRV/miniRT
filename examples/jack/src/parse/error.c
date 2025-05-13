/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:50:19 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 16:28:08 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	display_msg(char *s1, char *s2)
{
	write (2, s1, ft_strlen(s1));
	write (2, s2, ft_strlen(s2));
}

static void	dup_message(int error, int type)
{
	if (type == 1)
	{
		if (error & ERR_AMB)
			display_msg(AMB_MSG, DUP_MSG);
		if (error & ERR_CAM)
			display_msg(CAM_MSG, DUP_MSG);
		if (error & ERR_LIGHT)
			display_msg(LIGHT_MSG, DUP_MSG);
	}
	if (type == 2)
	{
		if (error & ERR_OAMB)
			display_msg(AMB_MSG, OOR_MSG);
		if (error & ERR_OCAM)
			display_msg(CAM_MSG, OOR_MSG);
		if (error & ERR_OLIGHT)
			display_msg(LIGHT_MSG, OOR_MSG);
		if (error & ERR_SP)
			display_msg(SP_MSG, OOR_MSG);
		if (error & ERR_PL)
			display_msg(PL_MSG, OOR_MSG);
		if (error & ERR_CY)
			display_msg(CY_MSG, OOR_MSG);
	}
}

void	field_message(int error)
{
	if (error & ERR_OAMB)
		display_msg(AMB_MSG, FERR_MSG);
	if (error & ERR_OCAM)
		display_msg(CAM_MSG, FERR_MSG);
	if (error & ERR_OLIGHT)
		display_msg(LIGHT_MSG, FERR_MSG);
	if (error & ERR_SP)
		display_msg(SP_MSG, FERR_MSG);
	if (error & ERR_PL)
		display_msg(PL_MSG, FERR_MSG);
	if (error & ERR_CY)
		display_msg(CY_MSG, FERR_MSG);
}

void	ft_stderr(int error)
{
	write (2, "Error\n", 6);
	if (error & ERR_ALLOC)
		write (2, ALLOC_MSG, ft_strlen(ALLOC_MSG));
	if (error & ERR_CHECK)
		write (2, CHECK_MSG, ft_strlen(CHECK_MSG));
	if (error & ERR_NCAM)
		write (2, "No Camera founded\n", 19);
	if (error & ERR_NLIGHT)
		write (2, "No Light founded\n", 18);
	if (error & ERR_DUB)
		dup_message(error, 1);
	if (error & ERR_OOR)
		dup_message(error, 2);
	if (error & ERR_FERR)
		field_message(error);
}
