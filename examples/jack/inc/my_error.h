/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:49:14 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 17:46:04 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_ERROR_H
# define MY_ERROR_H

# define ERR_ALLOC     1
# define ERR_CHECK     2
# define ERR_DUB       4
# define ERR_OOR       16
# define ERR_AMB       32
# define ERR_CAM       64
# define ERR_LIGHT     128
# define ERR_SP        256
# define ERR_PL        512
# define ERR_CY        1024
# define ERR_OAMB      2048
# define ERR_OCAM      4096
# define ERR_OLIGHT    8192
# define ERR_FERR      16384
# define ERR_NCAM      32768
# define ERR_NLIGHT    65536     

# define ALLOC_MSG "Memory allocation failed\n"
# define CHECK_MSG "Element validation failed\nElement may contain 'A',\
 'C', 'L', 'sp', 'pl', and 'cy' only.\n"
# define DUP_MSG " may only be declared once\n"
# define OOR_MSG "missing/too many field(s) or field is out of range\n"
# define FERR_MSG "Field error\n"
# define SP_MSG	"Sphere 'sp' "
# define PL_MSG "Plane 'pl' "
# define CY_MSG "Cylinder 'cy' "
# define AMB_MSG "Ambient 'A' "
# define CAM_MSG "Camera 'C' "
# define LIGHT_MSG "Light 'L' "

#endif