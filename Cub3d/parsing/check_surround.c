/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:11:04 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/19 20:26:29 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_player(char s)
{
	if (s == 'N' || s == 'E' || s == 'S' || s == 'W')
		return (1);
	return (0);
}

void	check_floodfill(t_data *data, int y, int x)
{
	if (x > data->line_len - 1 || x < 0)
		return ;
	if (y > data->true_map_len - 1 || y < 0)
		return ;
	if (data->map2[y][x] == '1' || data->map2[y][x] == 'X'
		|| data->map2[y][x] == '\n' || data->map2[y][x] == '\0')
		return ;
	data->map2[y][x] = 'X';
	check_floodfill(data, y, x + 1);
	check_floodfill(data, y, x - 1);
	check_floodfill(data, y + 1, x);
	check_floodfill(data, y - 1, x);
}

void	replace_flood_fill(t_data *data, int y, int x)
{
	if (x > data->line_len - 1 || x < 0)
		return ;
	if (y > data->true_map_len - 1 || y < 0)
		return ;
	if (data->map2[y][x] == '1' || data->map2[y][x] == '0'
		|| data->map2[y][x] == '\n' || data->map2[y][x] == '\0')
		return ;
	data->map2[y][x] = '0';
	replace_flood_fill(data, y, x + 1);
	replace_flood_fill(data, y, x - 1);
	replace_flood_fill(data, y + 1, x);
	replace_flood_fill(data, y - 1, x);
}

void	mapping_testing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map2[0][j])
	{
		if (data->map2[0][j] == 'X')
			free_map_exit(data, "Error : map is not closed");
		if (data->map2[data->true_map_len - 1][j] == 'X')
			free_map_exit(data, "Error : map is not closed");
		j++;
	}
	j = 0;
	while (data->map2[i])
	{
		if (data->map2[i][data->line_len - 1] == 'X'
			|| data->map2[i][0] == 'X')
			free_map_exit(data, "Error : map is not closed");
		i++;
	}
}

void	floodfill(t_data *data)
{
	char	player;

	player = data->map2[data->player_y][data->player_x];
	check_floodfill(data, data->player_y, data->player_x);
	mapping_testing(data);
	replace_flood_fill(data, data->player_y, data->player_x);
	data->map2[data->player_y][data->player_x] = player;
}
