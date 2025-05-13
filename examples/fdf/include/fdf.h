/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 13:38:23 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/13 08:13:04 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "MLX42.h"
# include <fcntl.h>
# include <math.h>
# include "elibft.h"

# define WIDTH 1080
# define HEIGHT 720

typedef struct s_3d_vector
{
	double	x;
	double	y;
	double	z;
}	t_3d_vector;

typedef struct s_2d_vector
{
	int	x;
	int	y;
}	t_2d_vector;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
	bool			lock;
}	t_color;

typedef struct s_vector
{
	t_2d_vector		v2d;
	t_3d_vector		v3d;
}	t_vector;

typedef struct s_node
{
	t_vector	v;
	t_color		color;
}	t_node;

typedef struct s_plot
{
	t_node		n0;
	int			e2;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}	t_plot;

typedef struct s_offset
{
	double	x;
	double	y;
	double	z;
}	t_offset;

typedef struct s_rotation
{
	double	x;
	double	y;
	double	z;
}	t_rotation;

typedef struct s_imginf
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	t_node		**map;
	t_offset	offset;
	t_rotation	rotation;
	double		scale;
	int			width;
	int			height;

}	t_imginf;

typedef struct s_rot_matrix
{
	t_3d_vector	i;
	t_3d_vector	j;
	t_3d_vector	k;
}	t_rot_matrix;

//init
t_imginf	*get_img(char **argv);
int			node_clean(void *node_to_clean);
bool		is_valid_file(char *filename, int *fd);
int			add_map_height(int fd, t_lst **map, t_imginf *img);
int			add_map_width(t_lst **map, t_imginf *img);

//boot
int			boot(t_imginf	*img);

//display
void		update_image(void *img);

//line
void		put_line(t_node n0, t_node n1, t_imginf *img);

//offset
t_node		offset(t_node n, t_imginf *img);

//projecttion
t_node		project(t_node n);

//rotation
t_node		rotate(t_node n, t_imginf *img);

//scale
t_node		scale(t_node n, t_imginf *img);
void		get_scale(t_imginf *img);

//flip
t_node		flip(t_node n, t_imginf *img);

//hooks
void		keys(mlx_key_data_t k, void *param);
void		cross(void *param);

//
void		ft_exit(t_imginf *img, int code);

#endif
