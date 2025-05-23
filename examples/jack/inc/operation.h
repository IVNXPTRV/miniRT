/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 12:42:01 by ruzhang           #+#    #+#             */
/*   Updated: 2025/05/21 18:22:55 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# define EPSILON 1e-6
# define SHADOW 1e-7

# ifndef PI
#  define PI 3.14159265358979323846
# endif

typedef struct s_ray
{
	t_point	origin;
	t_point	direction;
	t_list	*intersect;
}	t_ray;

typedef struct s_quadratic
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
}	t_quadratic;

/*
point:
	coordinates of the intersection point
normal:
	surface normal at the point of intersection.
	vector that is perpendicular to the surface of
	the object at the point of intersection.
distance:
	represent the distance from the ray’s origin to the intersection point.
solid:
	a pointer to the actual object that the ray intersects
*/
typedef struct s_intersect
{
	t_point				point; // coordinates of hit_point
	t_point				normal; // normal of hit_point
	double				distance; // distance to get from ray origin to hit_point
	void				*solid; // object
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_hit
{
	t_point	eye_vector;
	t_point	light_vector;
	t_point	surface_normal;
	t_point	reflection_vector;
	double	ratio;
}	t_hit;

// math.c
bool		equal(double a, double b);
t_point		add_vectors(t_point a, t_point b);
t_point		subtract_vectors(t_point a, t_point b);
t_point		negate_vect(t_point a);
t_point		scale_vector(t_point a, double t);

// math2.c
double		magnitude(t_point a);
t_point		normalize(t_point a);
double		dot_product(t_point a, t_point b);
t_point		cross_product(t_point a, t_point b);

//matrix.c
t_matrix	identity_matrix(void);
t_matrix	generate_rotation_matrix(t_point axis, double angle);
t_matrix	generate_rotation_to_z(t_point norm);
t_matrix	transpose_matrix(t_matrix m);
t_point		apply_rotation(t_matrix matrix, t_point point);

// intersect.c
void		append_intersect(t_objs *obj, t_ray *ray);

// sphere.c
void		calculate_quadratic(t_objs *obj, t_ray ray, t_quadratic *q);
void		append_sphere(t_objs *obj, t_ray *ray);

// plane.c
void		append_plane(t_objs *obj, t_ray *ray);

// light.c
t_color		calculate_lighting(t_intersect *intersect, t_sc *sc, t_ray ray);
t_hit		calculate_hit_vects(t_intersect *intersect, t_sc *sc, t_ray ray);
t_color		calculate_color(t_colors colors);

// color.c
t_color		calculate_ambient_color(t_amb *light, t_objs *obj);
t_color		calculate_diffuse_color(t_light *light, t_objs *obj, t_hit hit);

// shadow.c
int			is_shadowed(t_sc *sc, t_intersect *hit);
int			get_intersects(t_sc *sc, t_ray *ray, double t);

#endif