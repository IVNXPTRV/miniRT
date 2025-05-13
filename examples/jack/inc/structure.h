/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:49:10 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 17:05:29 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_matrix
{
	double	m[4][4];
}	t_matrix;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef enum e_type
{
	SP,
	PL,
	CY,
	L,
	C,
	A
}	t_type;

typedef struct s_vec3	t_point;
typedef struct s_vec3	t_color;

typedef struct s_amb
{
	int		status;
	double	ratio;
	t_color	color;
}	t_amb;

typedef struct s_cam
{
	int		status;
	t_point	position;
	t_point	norm;
	t_point	forward;
	t_point	right;
	t_point	up;
	double	fov;
	double	ratio;
	double	scale;
}	t_cam;

typedef struct s_light
{
	int		status;
	double	ratio;
	t_point	position;
	t_color	color;
}	t_light;

typedef struct s_colors
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	int		shadow;
}	t_colors;

typedef struct s_objs
{
	t_type	type;
	double	diameter;
	double	height;
	t_point	position;
	t_point	norm;
	t_color	color;
}	t_objs;

typedef struct s_parse_temp
{
	char	**vec3_pos;
	char	**vec3_norm;
	char	**vec3_color;
}	t_temp;

typedef struct s_rotation
{
	t_point	target;
	t_point	axis;
	double	angle;
	double	sin;
	double	cos;
	double	one_minus_c;
}	t_rotation;

typedef struct s_cap
{
	double	cap;
	t_point	cap_center;
	t_point	cap_normal;
}	t_cap;

typedef struct t_scence
{
	t_amb	amb;
	t_cam	cam;
	t_light	light;
	t_list	*head;
}	t_sc;

#endif