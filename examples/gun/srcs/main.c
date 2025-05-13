/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykai-yua <ykai-yua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:49:26 by nteechar          #+#    #+#             */
/*   Updated: 2025/04/01 12:01:42 by ykai-yua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini_rt.h"

static int	parse_arguments(int argc, char **argv, t_data *data)
{
	if (argc == 2)
		return (SUCCESS);
	if (argc != 3)
	{
		printf("Error\nWrong arguments format\n");
		printf("Usage: ./miniRT *.rt [--default, --parse-only, --debug]\n");
		return (ERROR);
	}
	data->mode = MODE_DEFAULT;
	if (ft_strcmp(argv[2], "--default") == 0)
		data->mode = MODE_DEFAULT;
	else if (ft_strcmp(argv[2], "--parse-only") == 0)
		data->mode = MODE_PARSE_ONLY;
	else if (ft_strcmp(argv[2], "--debug") == 0)
		data->mode = MODE_DEBUG;
	else
	{
		printf("Error\nMode not recognized\n");
		printf("Usage: ./miniRT *.rt [--default, --parse-only, --debug]\n");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	process_input(int argc, char **argv, t_data *data)
{
	if (parse_arguments(argc, argv, data) != SUCCESS)
		return (ERROR);
	if (read_file_to_world(argv[1], &data->world) != SUCCESS)
		return (ERROR);
	if (data->mode == MODE_PARSE_ONLY)
	{
		printf("Parse OK\n");
		free_world(&data->world);
		exit(EXIT_SUCCESS);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (process_input(argc, argv, &data) != SUCCESS)
		return (EXIT_FAILURE);
	if (init_display(&data) != SUCCESS)
		return (EXIT_FAILURE);
	render_image(&data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (EXIT_SUCCESS);
}
