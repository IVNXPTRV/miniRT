/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:38:23 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/28 11:47:02 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "MLX42.h"					// graphic library
# include "elibft.h"				// utils library
# include <stdbool.h>				// true, false
# include <math.h>					// cos, tag etc
# include <errno.h>					// errno
# include <string.h>				// strerror
# include <float.h>					// DBL_MAX

# define EPSILON 1e-6

typedef char			*t_m[5];	// print error messages in a loop

// struct to keep connection to graphic library
typedef struct s_gl
{
	mlx_t		*window;
	mlx_image_t	*image;
}	t_gl;

// 3 doubles for 3 dimentions vector
typedef struct s_3d
{
	double	x;
	double	y;
	double	z;
}	t_3d;

// color in decimal notation from 0 to 1< not from 0 to 255
typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

# define t_point t_3d
# define t_vector t_3d
# define t_num double				// most used numebr type in the program
# define MAX_OBJ 42					// maximum objects to be proccessed
# define WIDTH 800					// screen width
# define HEIGHT 600					// screen height
# define ERROR -1					// general error code
# define SUCCESS 1					// general success code
# define BLACK (t_color){0, 0, 0}	// black color
# define OPAQUE 0x000000FF			// fully intransaprent alpha channel
# define OFFSET 0.01				// offset a bit from obj surace to rpevent self-intersections
# define t_file	int					// file descriptor, fd
# define t_raw_color	uint32_t	// color in form of int 0x000000FF
# define NOINTERSECTION	-1			// no intersection

typedef struct s_camera
{
	bool		status;				// true if set up
	t_point		position;			// coordinates of the camera in the world
	t_vector	forward;			// front direction unit vector
	t_vector	up;
	t_vector	right;
	t_num		scale;				// calculated from fov
	t_num		ratio;				// WIDTH / HEIGHT
}	t_camera;

// no posiiton because it is everywhere
typedef struct s_ambient
{
	bool		status;				// true if set up
	t_num		brightness;			// multiplayer for the final result
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	bool		status;				// true if set up
	t_point		position;			// coordinates of the light in the world
	t_num		brightness;			// multiplayer for the final result
	t_color		color;				// not used in the mandatory part
}	t_light;

// element type
typedef enum e_type
{
	PL,								// plane
	SP, 							// sphere
	CY,								// cylinder
	CM,								// camera
	AM,								// ambient
	LG,								// light
}	t_type;

// general obj struct for all type of objects
typedef struct s_obj
{
	t_type		type;				// type of the element: PL, SP, CY
	t_point		position;			// coordinates of the light in the world
	t_color		color;				// color of the object
	t_vector	normal;				// used for PL and CY only; normal of the plane or axis of the cylinder
	t_num		diameter;			// used for SP and CY only
	t_num		height;				// used for CY only
}	t_obj;

// main struct of the program
typedef struct s_scene
{
	t_file		file;				// fd of the file which contains scene
	t_gl		gl;					// struct to keep connection to the graphic library
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	int			obj_num;			// total number of objects
	t_obj		obj[MAX_OBJ];		// array of all objects on the scene
}	t_scene;

typedef struct s_ray
{
	t_point		position;
	t_vector	direction;
}	t_ray;

typedef struct s_hit
{
	t_point		position;			// world coordinates of hit point
	t_vector	normal;				// normal at hit point
	t_obj		*obj;				// hit object to get color of and object at a hit point, NULL if no hit
}	t_hit;

// parsing
void parse(int argc, char **argv, t_scene *scene);
void validate_argument(int argc, char **argv, t_scene *scene);
void parse_element(char **element, t_scene *scene, int	lineno);
void validate_scene(t_scene *scene);

char **get_numbers(char **element, int i, int lineno, size_t limit);

// verify
void verify_attrs_number(char **element, size_t num, int lineno);
void verify_uniqueness(char **element, bool *singleton, int lineno);
void verify_max_obj_num(char **element, t_scene *scene, int lineno);

// numbers
bool is_in_range(double num, double min, double max);
double get_double(char **element, char **numbers, int i, int lineno);
int get_int(char **element, char **numbers, int i, int lineno);

// objs
void	parse_camera(char **element, t_scene *scene, int lineno);
void parse_ambient(char **element, t_scene *scene, int lineno);
void parse_light(char **element, t_scene *scene, int lineno);
void	parse_plane(char **element, t_scene *scene, int lineno);
void	parse_sphere(char **element, t_scene *scene, int lineno);
void	parse_cylinder(char **element, t_scene *scene, int lineno);

// attrs
t_point get_point(char **element, int i, int lineno);
t_vector get_vector(char **element, int i, int lineno);
t_num	get_brightness(char **element, int i, int lineno);
t_color	get_color(char **element, int i, int lineno);
t_num	get_size(char **element, int i, int lineno);

// error
void err(int lineno, t_m msg);
void er_close(int fd);

// math one_vector
t_num magnitude(t_vector vector);
t_vector normalize(t_vector vector);
t_vector scale_vector(t_vector vector, t_num scale);
t_vector flip_vector(t_vector vector);

// math two_vectors
t_num dot(t_vector a, t_vector b);
t_vector cross(t_vector a, t_vector b);
t_vector add_vectors(t_vector a, t_vector b);
t_vector sub_vectors(t_vector a, t_vector b);

// gl
void init_graphic_library(t_scene *scene);
void display_image(t_scene *scene);

// execution
void execute(t_scene *scene);
void	compute_image(t_scene *scene);
t_color get_pixel_color(t_scene *scene, int x, int y);
t_ray get_ray(t_camera camera, int x, int y);
t_hit get_hit(t_scene *scene, t_ray ray);
t_num compute_plane_intersection(t_ray ray, t_obj obj);
t_num compute_sphere_intersection(t_ray ray, t_obj obj);
t_num compute_cylinder_intersection(t_ray ray, t_obj obj);
t_color add_light(t_scene *scene, t_hit hit);
bool is_shadowed(t_scene *scene, t_ray ray);

// debug
void dbg_print_camera(t_camera	camera);
void dbg_print_num(t_num	num);
void dbg_print_vector(t_3d	vector);
void dbg_print_color(t_color	color);
void dbg_print_ray(t_ray	ray);
void dbg_print_hit(t_hit	hit);

#endif
