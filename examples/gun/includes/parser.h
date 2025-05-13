/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nteechar <nteechar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 09:48:54 by nteechar          #+#    #+#             */
/*   Updated: 2025/03/27 22:34:35 by nteechar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <fcntl.h>

# include "../libs/libft/libft.h"
# include "world.h"

typedef enum e_scene_type
{
	SCENE_AMBIENT,
	SCENE_CAMERA,
	SCENE_LIGHT,
	SCENE_SPHERE,
	SCENE_PLANE,
	SCENE_CYLINDER,
	SCENE_INVALID
}	t_scene_type;

typedef enum e_parse_result
{
	PARSE_OK,
	INVALID_OBJECT,
	TOO_MANY_OBJECTS,
	MORE_THAN_ONE_OBJECT,
	NO_ITEM,
	BAD_NUMBER_OF_PARAMS,
	BAD_RATIO,
	BAD_COLOR,
	BAD_POSITION,
	BAD_NORMAL,
	BAD_FOV,
	BAD_DIAMETER,
	BAD_HEIGHT,
}	t_parse_result;

typedef struct e_parse_status
{
	t_parse_result	result;
	t_scene_type	error_object;
}	t_parse_status;

int				read_file_to_world(char *filename, t_world *world);

char			**load_file_into_memory(int fd);

// utils
t_scene_type	identify_scene_type(char *id);
void			free_array(char **arr);
void			free_tokens(char ***tokens);
int				array_length(char **arr);
void			print_error(t_parse_result ret, t_scene_type type);

// validation
int				validate_scene(int number_of_lines, char ***tokens);

t_parse_result	validate_ambient(char **line);
t_parse_result	validate_camera(char **line);
t_parse_result	validate_light(char **line);
t_parse_result	validate_sphere(char **line);
t_parse_result	validate_plane(char **line);
t_parse_result	validate_cylinder(char **line);

int				is_in_range(int min, int max, int x);
int				is_in_rangef(double min, double max, double x);
int				is_valid_ratio(char *ratio);
int				is_valid_color(char *rgb_str);
int				is_valid_pos(char *pos_str);
int				is_valid_normal(char *normal_str);
int				is_valid_length(char *length_str);
int				is_valid_fov(char *fov_str);

int				parse_int_vector3(char *str, int values[3]);
int				parse_vector3(char *str, double values[3]);

// parsing
int				parse_scene(int number_of_lines, char ***tokens,
					t_world *world);

int				parse_ambient(char **line, t_world *world);
int				parse_camera(char **line, t_world *world);
int				parse_light(char **line, t_world *world);
int				parse_sphere(char **line, t_world *world);
int				parse_plane(char **line, t_world *world);
int				parse_cylinder(char **line, t_world *world);

double			parse_ratio(char *ratio_str);
int				parse_color(char *rgb_str, int *color);
int				parse_vector(char *xyz_str, t_vector3 *dest);
int				parse_normal_vector(char *normal_str, t_vector3 *dest);
int				parse_fov(char *fov_str);

#endif
