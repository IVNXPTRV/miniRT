/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 15:23:00 by ruzhang           #+#    #+#             */
/*   Updated: 2025/04/11 18:45:08 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIDTH 1280
# define HEIGHT 720
# define FN_ERR "Filename must ends with .rt\n"

# include "include/MLX42/MLX42.h"
# include "libft.h"
# include "structure.h"
# include "my_error.h"
# include "operation.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_rt
{
	mlx_t		*mlx;
	mlx_image_t	*img;
}	t_rt;

int			init_rt(t_rt *rt);
int			validate(int argc, char **argv, t_sc *sc);
int			parse_amb(char **line, t_sc *sc);
int			parse_cam(char **line, t_sc *sc);
int			parse_light(char **line, t_sc *sc);
int			run_line(char *s);
int			check_digit(char **vec3);
int			parse_sp(char **line, t_sc *sc);
int			parse_pl(char **line, t_sc *sc);
int			parse_cy(char **line, t_sc *sc);
int			check_temp(t_temp *temp);
int			check_sp(char **line, t_temp **temp);
int			check_pl(char **line, t_temp **temp);
int			check_cy(char **line, t_temp **temp);
int			run_line(char *s);
int			check_digit(char **vec3);
int			validate_amount(t_sc *sc);
int			free_temp(t_temp *temp);
int			arr_len(char **line);
int			in_range(double x, int type);
int			validate_elements(t_sc *sc);
int			validate_objs(t_list *lst);
int			intersect_disk(t_ray *ray, t_cap *cap, double radius);
void		key_press(mlx_key_data_t keycode, void *param);
void		scale_color(t_sc *sc);
void		cam_setup(t_cam *cam);
void		fill_cam(t_cam *cam, t_temp *temp);
void		init_obj(t_objs *obj);
void		init_sc(t_sc *sc);
void		get_temp(char **line, t_type type, t_temp **temp);
void		ft_stderr(int error);
void		test_sc(t_sc *sc);
t_intersect	*get_closest(t_ray *ray);
void		render(t_rt *rt, t_sc *sc);
void		append_cylinder(t_objs *obj, t_ray *ray);
void		fill_intersect(t_objs *obj, t_ray *ray, double t, t_intersect *new);
void		get_rotation(t_point norm, t_rotation *rotation);
void		calculate_cylinder(t_objs *obj, t_ray ray, t_quadratic *q);
void		add_disk(t_ray transformed_ray, t_objs *obj, t_ray *ray);
t_color		calculate_lighting(t_intersect *intersect, t_sc *sc, t_ray ray);
double		calculate_angle(t_point axis);

#endif