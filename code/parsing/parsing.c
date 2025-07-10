/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:57:53 by lloginov          #+#    #+#             */
/*   Updated: 2025/07/09 16:29:47 by lloginov         ###   ########.fr       */
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
	int		i;
	char	*map;
	int		fd;
	char	*line;

	map = av[1];
	i = 0;
	(void)ac;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		print_exit("Error : cannot open map (first pass)");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		i++;
	}
	data->file_size = i;
	data->map = malloc(sizeof(char *) * (data->file_size + 1));
	if (!data->map)
		print_exit("Error : malloc map failed");
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
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}

void	file_acces(t_data *data)
{
	if (open(data->file_south, O_RDONLY) == -1)
		free_exit(data, "Error : cannot access south texture");
	else if (open(data->file_west, O_RDONLY) == -1)
		free_exit(data, "Error : cannot access west texture");
	else if (open(data->file_north, O_RDONLY) == -1)
		free_exit(data, "Error : cannot access north texture");
	else if (open(data->file_east, O_RDONLY) == -1)
		free_exit(data, "Error : cannot access east texture");
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
	printf("north file : %s\n south : %s\n east : %s\n west : %s\n", data->file_north, data->file_south, data->file_east, data->file_west);
	printf("%d\n, %d\n", data->floor_color, data->roof_color);
	// file_acces(data);
	return (0);
}
