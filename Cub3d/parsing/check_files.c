/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 12:02:43 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/19 20:25:02 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	north_check(t_data *data, int i, int counter)
{
	int	pos;
	int	pos2;

	pos = check_arg(data->map[i], 'N', 'O');
	pos2 = check_ws(data->map[i], pos);
	if (pos == pos2)
		free_exit(data, "Error : north texture not working");
	if (data->file_north)
		free_exit(data, "Error : north texture not working");
	data->file_north = ft_sub(data->map[i], pos, pos2 + 1);
	counter++;
	return (counter);
}

int	south_check(t_data *data, int i, int counter)
{
	int	pos;
	int	pos2;

	pos = check_arg(data->map[i], 'S', 'O');
	pos2 = check_ws(data->map[i], pos);
	if (pos == pos2)
		free_exit(data, "Error : south texture not working");
	if (data->file_south)
		free_exit(data, "Error : south texture not working");
	data->file_south = ft_sub(data->map[i], pos, pos2 + 1);
	counter++;
	return (counter);
}

int	east_check(t_data *data, int i, int counter)
{
	int	pos;
	int	pos2;

	pos = check_arg(data->map[i], 'E', 'A');
	pos2 = check_ws(data->map[i], pos);
	if (pos == pos2)
		free_exit(data, "Error : east texture not working");
	if (data->file_east)
		free_exit(data, "Error : east texture not working");
	data->file_east = ft_sub(data->map[i], pos, pos2 + 1);
	counter++;
	return (counter);
}

int	west_check(t_data *data, int i, int counter)
{
	int	pos;
	int	pos2;

	pos = check_arg(data->map[i], 'W', 'E');
	pos2 = check_ws(data->map[i], pos);
	if (pos == pos2)
		free_exit(data, "Error : west texture not working");
	if (data->file_west)
		free_exit(data, "Error : west texture not working");
	data->file_west = ft_sub(data->map[i], pos, pos2 + 1);
	counter++;
	return (counter);
}

void	wall_files_check(t_data *data)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (data->map[i])
	{
		if (ft_strcmp_pos(data->map[i], "SO") == 0 && counter != 4)
			counter = south_check(data, i, counter);
		else if (ft_strcmp_pos(data->map[i], "NO") == 0 && counter != 4)
			counter = north_check(data, i, counter);
		else if (ft_strcmp_pos(data->map[i], "WE") == 0 && counter != 4)
			counter = west_check(data, i, counter);
		else if (ft_strcmp_pos(data->map[i], "EA") == 0 && counter != 4)
			counter = east_check(data, i, counter);
		i++;
	}
	if (counter > 4)
		free_exit(data, "Error : too many texture files");
	if (counter < 4)
		free_exit(data, "Error : missing texture files");
	check_xpm(data);
}
