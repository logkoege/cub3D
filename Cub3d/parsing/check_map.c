/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:28 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/14 15:31:10 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_replace_char(t_data *data, int i, int j)
{
	if (data->map2[i][j] != '1' && data->map2[i][j] != '0'
		&& data->map2[i][j] != '\0' && data->map2[i][j] != '\n'
		&& data->map2[i][j] != 'N' && data->map2[i][j] != 'S'
		&& data->map2[i][j] != 'E' && data->map2[i][j] != 'W')
		return (1);
	return (0);
}

void	player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'N' || data->map2[i][j] == 'S'
				|| data->map2[i][j] == 'E' || data->map2[i][j] == 'W')
			{
				data->player_y = i;
				data->player_x = j;
				data->player_spawn = data->map2[i][j];
				return ;
			}
			j++;
		}
		i++;
	}
}

void	check_player_count(t_data *data)
{
	int	i;
	int	j;
	int	cmpt;

	cmpt = 0;
	i = 0;
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == 'N' || data->map2[i][j] == 'S'
				|| data->map2[i][j] == 'E' || data->map2[i][j] == 'W')
				cmpt++;
			j++;
		}
		i++;
	}
	if (cmpt != 1)
		free_map_exit(data, "Error : player error");
	player_pos(data);
}

void	check_empty_line(t_data *data)
{
	int	i;
	int	j;
	int	has_content;

	i = 0;
	while (data->map2[i])
	{
		j = 0;
		has_content = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == '1' || data->map2[i][j] == '0'
				|| data->map2[i][j] == 'N' || data->map2[i][j] == 'S'
				|| data->map2[i][j] == 'E' || data->map2[i][j] == 'W')
				has_content = 1;
			j++;
		}
		if (has_content == 0)
			free_map_exit(data, "Error : empty line in map");
		i++;
	}
}

void	check_walls(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map2[0][j])
	{
		if (data->map2[0][j] != '1' && data->map2[0][j] != '\n')
			free_map_exit(data, "Error : first line not surrounded");
		j++;
	}
	j = 0;
	while (data->map2[i])
		i++;
	i--;
	if (ft_strlen(data->map2[i]) == 1)
		free_map_exit(data, "Error : last line not surrounded");
	while (data->map2[i][j])
	{
		if (data->map2[i][j] != '1' && data->map2[i][j] != '\n')
			free_map_exit(data, "Error : last line not surrounded");
		j++;
	}
}
