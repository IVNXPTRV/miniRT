/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruzhang <ruzhang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:48:58 by jchompoo          #+#    #+#             */
/*   Updated: 2025/04/10 20:43:20 by ruzhang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	check_element(char *s)
{
	if (!ft_strcmp(s, "A") || !ft_strcmp(s, "L") || !ft_strcmp(s, "C")
		|| !ft_strcmp(s, "sp") || !ft_strcmp(s, "pl") || !ft_strcmp(s, "cy")
		|| !ft_strcmp(s, "\n"))
		return (0);
	return (1);
}

static int	parse_line(char *line, t_sc *sc)
{
	int		error;
	char	**l;

	error = 0;
	l = ft_split(line, " \t\n");
	if (!l)
		return (ERR_ALLOC);
	if (l[0] && check_element(l[0]))
		error |= ERR_CHECK;
	else if (l[0] && !ft_strcmp(l[0], "A"))
		error |= parse_amb(l, sc);
	else if (l[0] && !ft_strcmp(l[0], "C"))
		error |= parse_cam(l, sc);
	else if (l[0] && !ft_strcmp(l[0], "L"))
		error |= parse_light(l, sc);
	else if (l[0] && !ft_strcmp(l[0], "sp"))
		error |= parse_sp(l, sc);
	else if (l[0] && !ft_strcmp(l[0], "pl"))
		error |= parse_pl(l, sc);
	else if (l[0] && !ft_strcmp(l[0], "cy"))
		error |= parse_cy(l, sc);
	ft_free_split(l);
	return (error);
}

static int	parse(char *filename, t_sc *sc)
{
	int		fd;
	int		error;
	char	*line;

	error = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	while (line)
	{
		error |= parse_line(line, sc);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (error);
}

static void	validate_filename(int argc, char **argv)
{
	char	*filename;
	int		fd;

	filename = argv[1];
	if (argc != 2)
	{
		write(2, "Error\n", 7);
		write(2, "Too many/not enough arguments\n", 31);
		exit(1);
	}
	if (ft_strlen(argv[1]) < 4
		|| ft_strcmp(".rt", &filename[ft_strlen(filename) - 3]))
	{
		write(2, "Error\n", 7);
		write(STDERR_FILENO, FN_ERR, ft_strlen(FN_ERR));
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("File open failed");
		close(fd);
		exit(1);
	}
	close(fd);
}

int	validate(int argc, char **argv, t_sc *sc)
{
	int		error;
	char	*filename;

	error = 0;
	validate_filename(argc, argv);
	filename = argv[1];
	init_sc(sc);
	error |= parse(filename, sc);
	error |= validate_elements(sc);
	error |= validate_amount(sc);
	if (error)
	{
		ft_lstclear(&(sc)->head, free);
		ft_stderr(error);
		return (1);
	}
	scale_color(sc);
	return (0);
}
