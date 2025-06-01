/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:38:23 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 19:57:15 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42.h"
# include "elibft.h"
# include <errno.h>
# include <float.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>

# define EPSILON 1e-6

typedef char		*t_m[5];

typedef struct s_gl
{
	mlx_t			*window;
	mlx_image_t		*image;
}					t_gl;

typedef struct s_3d
{
	double			x;
	double			y;
	double			z;
}					t_3d;

typedef struct s_color
{
	double			r;
	double			g;
	double			b;
}					t_color;

typedef t_3d		t_point;
typedef t_3d		t_vector;
typedef double		t_num;
typedef uint32_t	t_raw_color;

# define MAX_OBJ 100
# define WIDTH 800
# define HEIGHT 600
# define ERROR -1
# define SUCCESS 1
# define OPAQUE 0x000000FF
# define OFFSET 0.01
# define NOINTERSECTION INFINITY

typedef struct s_camera
{
	bool			status;
	t_point			position;
	t_vector		forward;
	t_vector		up;
	t_vector		right;
	t_num			scale;
	t_num			ratio;
}					t_camera;

typedef struct s_ambient
{
	bool			status;
	t_num			brightness;
	t_color			color;
}					t_ambient;

typedef struct s_light
{
	bool			status;
	t_point			position;
	t_num			brightness;
	t_color			color;
}					t_light;

typedef enum e_type
{
	PL,
	SP,
	CY,
	DS,
	CM,
	AM,
	LG,
}					t_type;

typedef struct s_obj
{
	t_type			type;
	t_point			position;
	t_color			color;
	t_vector		normal;
	t_num			diameter;
	t_num			height;
}					t_obj;

typedef struct s_scene
{
	int				file;
	t_gl			gl;
	t_camera		camera;
	t_ambient		ambient;
	t_light			light;
	int				obj_num;
	t_obj			obj[MAX_OBJ];
}					t_scene;

typedef struct s_ray
{
	t_point			position;
	t_vector		direction;
}					t_ray;

typedef struct s_hit
{
	t_point			position;
	t_vector		normal;
	t_obj			*obj;
}					t_hit;

void				parse(int argc, char **argv, t_scene *scene);
void				validate_argument(int argc, char **argv, t_scene *scene);
void				parse_element(char **element, t_scene *scene, int lineno);
void				validate_scene(t_scene *scene);

char				**get_numbers(char **element, int i, int lineno,
						size_t limit);

void				verify_attrs_number(char **element, size_t num, int lineno);
void				verify_uniqueness(char **element, bool *singleton,
						int lineno);
void				verify_max_obj_num(char **element, t_scene *scene,
						int lineno);

bool				is_in_range(double num, double min, double max);
double				get_double(char **element, char **numbers, int i,
						int lineno);
int					get_int(char **element, char **numbers, int i, int lineno);

void				parse_camera(char **element, t_scene *scene, int lineno);
void				parse_ambient(char **element, t_scene *scene, int lineno);
void				parse_light(char **element, t_scene *scene, int lineno);
void				parse_plane(char **element, t_scene *scene, int lineno);
void				parse_sphere(char **element, t_scene *scene, int lineno);
void				parse_cylinder(char **element, t_scene *scene, int lineno);

t_point				get_point(char **element, int i, int lineno);
t_vector			get_vector(char **element, int i, int lineno);
t_num				get_brightness(char **element, int i, int lineno);
t_color				get_color(char **element, int i, int lineno);
t_num				get_size(char **element, int i, int lineno);

void				err(int lineno, t_m msg);
void				er_close(int fd);

t_num				magnitude(t_vector vector);
t_vector			normalize(t_vector vector);
t_vector			scale_vector(t_vector vector, t_num scale);
t_vector			flip_vector(t_vector vector);

t_num				dot(t_vector a, t_vector b);
t_vector			cross(t_vector a, t_vector b);
t_vector			add_vectors(t_vector a, t_vector b);
t_vector			sub_vectors(t_vector a, t_vector b);

void				init_graphic_library(t_scene *scene);
void				display_image(t_scene *scene);

void				execute(t_scene *scene);
void				compute_image(t_scene *scene);
t_color				get_pixel_color(t_scene *scene, int x, int y);
t_ray				get_ray(t_camera camera, int x, int y);
t_hit				get_hit(t_scene *scene, t_ray ray);
t_num				compute_plane_intersection(t_ray ray, t_obj obj);
t_num				compute_sphere_intersection(t_ray ray, t_obj obj);
t_num				compute_cylinder_intersection(t_ray ray, t_obj obj);
t_num				compute_disk_intersection(t_ray ray, t_obj obj);
t_color				add_light(t_scene *scene, t_hit hit);
bool				is_shadowed(t_scene *scene, t_ray ray);

t_color				get_ambient(t_scene *scene, t_hit hit);
t_color				get_diffuse(t_scene *scene, t_hit hit);

t_vector			get_plane_normal(t_hit hit, t_ray ray);
t_vector			get_disk_normal(t_hit hit, t_ray ray);
t_vector			get_sphere_normal(t_hit hit, t_ray ray);
t_vector			get_cylinder_normal(t_hit hit, t_ray ray);
t_vector			get_normal(t_hit hit, t_ray ray);

#endif
