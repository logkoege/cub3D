/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:57:53 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/19 20:41:45 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	map_name(char *map)
{
	int	i;

	i = ft_strlen(map);
	if (i < 5)
		print_exit("Error : map name too short");
	i--;
	if (map[i] == 'b' && map[i - 1] == 'u'
		&& map[i - 2] == 'c' && map[i - 3] == '.')
		return ;
	else
		print_exit("Error : map should end with \'.cub\'");
}

void	map_size(t_data *data, int ac, char **av)
{
	char	*map;
	int		fd;

	map = av[1];
	data->ii = 0;
	(void)ac;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_exit("Error : cannot open map (first pass)");
	while (1)
	{
		data->line = get_next_line(fd);
		if (!data->line)
			break ;
		free(data->line);
		data->ii++;
	}
	data->file_size = data->ii;
	data->map = malloc(sizeof(char *) * (data->file_size + 1));
	if (!data->map)
	{
		close(fd);
		print_exit("Error : malloc map failed");
	}
	close(fd);
}

void	map_dup(t_data *data, char *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_exit("Error : cannot open map (second pass)");
	while (i < data->file_size)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		data->map[i] = ft_dup(line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

void	file_acces(t_data *data)
{
	data->south_fd = open(data->file_south, O_RDONLY);
	if (data->south_fd == -1)
		free_map_exit(data, "Error : cannot access texture");
	data->west_fd = open(data->file_west, O_RDONLY);
	if (data->west_fd == -1)
	{
		close(data->south_fd);
		free_map_exit(data, "Error : cannot access texture");
	}
	data->north_fd = open(data->file_north, O_RDONLY);
	if (data->north_fd == -1)
	{
		close(data->south_fd);
		close(data->west_fd);
		free_map_exit(data, "Error : cannot access texture");
	}
	data->east_fd = open(data->file_east, O_RDONLY);
	if (data->east_fd == -1)
	{
		close(data->west_fd);
		close(data->north_fd);
		close(data->south_fd);
		free_map_exit(data, "Error : cannot access texture");
	}
}

int	parsing(t_data *data, int ac, char **av)
{
	int	i;

	(void)ac;
	i = 1;
	map_name(av[i]);
	map_size(data, ac, av);
	map_dup(data, av[1]);
	wall_files_check(data);
	color_check(data);
	i = 0;
	assign_map(data);
	file_acces(data);
	return (0);
}
