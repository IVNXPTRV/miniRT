/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetrov <ipetrov@student.42bangkok.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:55:54 by ipetrov           #+#    #+#             */
/*   Updated: 2025/05/21 11:22:32 by ipetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	puterr(char *str)
{
	if (write(STDERR_FILENO, str, ft_strlen(str)) == ERROR)
		exit(EXIT_FAILURE);
}

// print error and exit if finish_program is true
// (t_m){strerror(errno)}
void err(int lineno, t_m msg)
{
	char *str;

	pterr("Error\n");
	if (lineno > 0)
	{
		str = ft_itoa(lineno);
		if (str == NULL)
		{
			err(Z, (t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
		pterr(str);
		pterr(": ");
		free(str);
	}
	while (*msg != NULL)
	{
		pterr(msg);
		msg++;
	}
	pterr("\n");
}

void execute(t_scene *scene)
{
	init_graphic_library(scene);	// connect to gl and prepare an image
	compute_image(scene);			// fill all final pixels color
	display_image(scene);			// render an image in an OS window
}

void er_close(int fd)
{
	if (close(fd) == ERROR)
	{
		err(Z, (t_m){"close: fatal error"});
		exit(EXIT_FAILURE);
	}
}

static inline bool is_empty_line(char *line)
{
	if (!is_eqlstr(line, "\n"))
		return (false);
	free(line);
	return (true);
}

static char **get_element(char *line)
{
	char **element;

	element = ft_split(line, " \r\f\v\t\n");
	free(line);
	if (element == NULL)						// malloc failed
	{
		err(Z, (t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	return (element);
}

void veriy_uniqueness(char **element, bool *singleton, int lineno)
{
	if (*singleton == true)			// means we've already met this element in a file
	{
		err(lineno, (t_m){"encountered more then one ", element[0]});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
	*singleton = true;
}

void verify_attrs_number(char **element, int num, int lineno)
{
	if (ft_parrlen(element + 1) != num)
	{
		err(lineno, (t_m){"wrong number of attributes"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

// get number and check how many we have
// limit how many numbers should be
char **get_numbers(char **element, int i, int lineno, int limit)
{
	char	**numbers;

	numbers = ft_split(element[i], ",");
	if (numbers == NULL)						// malloc failed
	{
		ft_parrclean(element);
		err(Z, (t_m){"malloc: fatal error"});
		exit(EXIT_FAILURE);
	}
	if (ft_parrlen(numbers) != limit)				// if len of result != 3
	{
		err(lineno, (t_m){"wrong number of parameters in an attribute -> ", element[i]});
		ft_parrclean(element);
		ft_parrclean(numbers);
		exit(EXIT_FAILURE);
	}
	return (numbers);
}

// indx of number
double get_double(char **element, char **numbers, int i, int lineno)
{
	double result;

	result = 0;
	if (ft_atod(numbers[i], &result) == FAIL)
	{
		err(lineno, (t_m){numbers[i], "incorrect double"});
		ft_parrclean(element);
		ft_parrclean(numbers);
		exit(EXIT_SUCCESS);
	}
	return (result);
}

int get_int(char **element, char *numbers, int i, int lineno)
{
	int result;

	result = 0;
	if (ft_atoi(numbers[i], &result, sizeof(int), 10) == FAIL)
	{
		err(lineno, (t_m){numbers[i], "incorrect integer"});
		ft_parrclean(element);
		ft_parrclean(numbers);
		exit(EXIT_SUCCESS);
	}
	return (result);
}

// element -- whole line
// i -- index of certain attribute of the element
t_point get_point(char **element, int i, int lineno)
{
	char	**numbers;
	t_point	point;

	numbers = get_numbers(element, i, lineno);
	point.x = get_double(element, numbers, 0, lineno);
	point.y = get_double(element, numbers, 1, lineno);
	point.z = get_double(element, numbers, 2, lineno);
	ft_parrclean(numbers);
	return (point);
}

inline bool is_in_range(double num, double min, double max)
{
	return (num >= min && num <= max);
}

// use faster sqrt??
t_num get_magnitude(t_vector vector)
{
    return sqrt(vector.x * vector.x
            + vector.y * vector.y
            + vector.z * vector.z);
}

//returns how aligned 2 vectors -1 to +1 if vectors normilized
t_num get_dot(t_vector a, t_vector b)
{
    return (a.x * b.x
		+ a.y * b.y
		+ a.z * b.z);
}

// normalization embeded
t_vector get_cross(t_vector a, t_vector b)
{
    t_vector result;

    result.x = a.y * b.z - a.z * b.y;
    result.y = a.z * b.x - a.x * b.z;
    result.z = a.x * b.y - a.y * b.x;
    return (normalize(result));
}

t_vector normalize(t_vector vector)
{
    double	mag;

	mag = get_magnitude(vector);
    return ((t_vector){vector.x / mag, vector.y / mag, vector.z / mag});
}

void verify_vector(char **element, int i, int lineno, t_vector vector)
{
	if (get_magnitude(vector) != 1.0)
	{
		err(lineno, (t_m){element[i], "is not normalized, magnitude should be 1"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

void verify_fov(char **element, int i, int lineno, int fov)
{
	if (!is_in_range((double)fov, 0, 180))
	{
		err(lineno, (t_m){element[i], "is beyond 0 to 180 range"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

t_vector get_vector(char **element, int i, int lineno)
{
	char		**numbers;
	t_vector	vector;

	numbers = get_numbers(element, i, lineno, 3);
	vector.x = get_double(element, numbers, 0, lineno);
	vector.y = get_double(element, numbers, 1, lineno);
	vector.z = get_double(element, numbers, 2, lineno);
	ft_parrclean(numbers);
	verify_vector(element, i, lineno, vector);
	return (vector);
}

t_num get_scale(char **element, int i, int lineno)
{
	char		**numbers;
	int			fov;
	t_num		scale;

	numbers = get_numbers(element, i, lineno, 1);
	fov = get_int(element, numbers, 0, lineno);
	ft_parrclean(numbers);
	verify_fov(element, i, lineno, fov);					// verify if in 0 to 180 range
	scale = tan(fov * 0.5 * PI / 180.0);					// is it correct?
	return (scale);
}

// get right vector for camera
t_vector get_right(t_vector forward)
{
	t_vector	world_up;

	world_up = (t_vector){0, 1, 0};					// pick +Y as world up
	// if forward and wolrd_up to mach aligned choose another direction
	// for strong cross calculations (vectors should be close to perpendicular)
	// we do not chang global world_up it is stiil +Y but here we change as hack
	if (fabs(get_dot(forward, world_up)) > 0.999)
		world_up = (t_point){0, 0, 1};
	return (get_cross(forward, world_up));
}

t_vector get_up(t_vector right, t_vector forward)
{
	return (get_cross(right, forward));
}

// max 3 attrs / we have only 3 attributes for the camera
//
void	parse_camera(char **element, t_scene *scene, int lineno)
{
	static bool singleton;										// set to true when first time meet camera element, by desifn initially is false

	verify_uniqueness(element, &singleton, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->camera.position = get_point(element, 1, lineno);
	scene->camera.forward = get_vector(element, 2, lineno);
	scene->camera.scale = get_scale(element, 3, lineno); 		// verify fov and convert to scale
	scene->camera.right = get_right(scene->camera.forward);
	scene->camera.up = get_up(scene->camera.right, scene->camera.forward);
	scene->camera.ratio = (double)WIDTH / (double)HEIGHT;
}

void verify_brightness(char **element, int i, int lineno, t_num brightness)
{
	if (!is_in_range(brightness, 0, 1))
	{
		err(lineno, (t_m){element[i], "is beyond 0 to 1 range"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

t_num	get_brightness(char **element, int i, int lineno)
{
	char		**numbers;
	t_num		brightness;

	numbers = get_numbers(element, i, lineno, 1);
	brightness = get_double(element, numbers, 0, lineno);
	ft_parrclean(numbers);
	verify_brightness(element, i, lineno, brightness);
	return (brightness);
}

void verify_color(char **element, int i, int lineno, t_color color)
{
	if (!is_in_range(color.r, 0, 1) || \
		!is_in_range(color.g, 0, 1) || \
		!is_in_range(color.b, 0, 1))
	{
		err(lineno, (t_m){element[i], "is beyond 0 to 255 range"});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
}

t_color	get_color(char **element, int i, int lineno)
{
	char		**numbers;
	t_color		color;

	numbers = get_numbers(element, i, lineno, 3);
	color.r = get_int(element, numbers, 0, lineno) / 255.0;				// converted to 0.0 to 1.0 representation
	color.g = get_int(element, numbers, 1, lineno) / 255.0;
	color.b = get_int(element, numbers, 2, lineno) / 255.0;
	ft_parrclean(numbers);
	verify_color(element, i, lineno, color);
}

void parse_ambient(char **element, t_scene *scene, int lineno)
{
	static bool singleton;

	verify_uniqueness(element, &singleton, lineno);
	verify_attrs_number(element, 2, lineno);
	\
	scene->ambient.brightness = get_brightness(element, 1, lineno);
	scene->ambient.color = get_color(element, 2, lineno);
}

void parse_light(char **element, t_scene *scene, int lineno)
{
	static bool singleton;

	verify_uniqueness(element, &singleton, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->light.position = get_point(element, 1, lineno);
	scene->light.brightness = get_brightness(element, 2, lineno);
	scene->light.color = get_color(element, 3, lineno);
}

void verify_max_obj_num(char **element, t_scene *scene, int lineno)
{
	if (scene->obj_num >= MAX_OBJ)
	{
		err(lineno, (t_m){"reached maximum number of objects"});
		ft_parrclean(element);
	}
}

void	parse_plane(char **element, t_scene *scene, int lineno)
{
	verify_max_obj_num(element, scene, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->obj[scene->obj_num].position = get_point(element, 1, lineno);
	scene->obj[scene->obj_num].normal = get_vector(element, 2, lineno);
	scene->obj[scene->obj_num].color = get_color(element, 3, lineno);
	scene->obj[scene->obj_num].type = PL;
	scene->obj_num++;
}

t_num	get_size(char **element, int i, int lineno)
{
	char		**numbers;
	t_num		diameter;

	numbers = get_numbers(element, i, lineno, 1);
	diameter = get_double(element, numbers, 0, lineno);
	ft_parrclean(numbers);
	return (diameter);
}

void	parse_sphere(char **element, t_scene *scene, int lineno)
{
	verify_max_obj_num(element, scene, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->obj[scene->obj_num].position = get_point(element, 1, lineno);
	scene->obj[scene->obj_num].diameter = get_size(element, 2, lineno);
	scene->obj[scene->obj_num].color = get_color(element, 3, lineno);
	scene->obj[scene->obj_num].type = SP;
	scene->obj_num++;
}

void	parse_cylinder(char **element, t_scene *scene, int lineno)
{
	verify_max_obj_num(element, scene, lineno);
	verify_attrs_number(element, 3, lineno);
	\
	scene->obj[scene->obj_num].position = get_point(element, 1, lineno);
	scene->obj[scene->obj_num].diameter = get_size(element, 2, lineno);
	scene->obj[scene->obj_num].height = get_size(element, 3, lineno);
	scene->obj[scene->obj_num].color = get_color(element, 4, lineno);
	scene->obj[scene->obj_num].type = CY;
	scene->obj_num++;
}

void parse_element(char **element, t_scene *scene, int	lineno)
{
	if (is_eqlstr(element[0], "C"))
		parse_camera(element, scene, lineno);
	else if (is_eqlstr(element[0], "A"))
		parse_ambient(element, scene, lineno);
	else if (is_eqlstr(element[0], "L"))
		parse_light(element, scene, lineno);
	else if (is_eqlstr(element[0], "pl"))
		parse_plane(element, scene, lineno);
	else if (is_eqlstr(element[0], "sp"))
		parse_sphere(element, scene, lineno);
	else if (is_eqlstr(element[0], "cy"))
		parse_cylinder(element, scene, lineno);
	else										// wrong identifier
	{
		err(lineno, (t_m){"wrong identifier -> ", element[0]});
		ft_parrclean(element);
		exit(EXIT_FAILURE);
	}
	ft_parrclean(element);
}

void	parse_line(char *line, t_scene *scene, int	lineno)
{
	char **element;							// element attributes

	if (is_empty_line(line))				// skip empty line
		return ;
	element = get_element(line);			// split line to each attribute of the element
	parse_element(element, scene, lineno);
}

// get each line from file and parse to get element attributes filled
void load_elements(t_scene *scene)
{
	char	*line;
	int		lineno;

	line = PTR_INIT;
	lineno = 0;
	while (line)
	{
		line = get_next_line(scene->file);	// "\n\0" -- for line which is only new line
		if (errno == ENOMEM)				// check for errno == ENOMEM if malloc failed
		{
			err(Z, (t_m){"malloc: fatal error"});
			exit(EXIT_FAILURE);
		}
		lineno++;
		if (line)
			parse_line(line, scene, lineno);
	}
	er_close(scene->file);					// close fd of file
}

void parse(int argc, char **argv, t_scene *scene)
{
	validate_synopsis(argc);		// if only one arg
	validate_filename(argv[1]);		// ends with .rt
	validate_file(argv[1]);			// if correct rights and possible to open
	load_elements(scene);			// get each line, parse and load to corresponding struct
}

int	main(int argc, char **argv)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(t_scene));	// init scene with zeroes
	\
	parse(argc, argv, &scene); 			// deserialize
	execute(&scene);					// render: init graphic library, get_image, display window with image
	\
	return (EXIT_SUCCESS);
	// validate

	// parse
	// execute

	// clean
	// exit
}
