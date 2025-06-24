/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:11:04 by lloginov          #+#    #+#             */
/*   Updated: 2025/06/24 23:53:36 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int is_player(char s)
{
	if(s == 'N' || s == 'E' || s == 'S' || s == 'W')
		return (1);
	return (0);
}

void	check_floodfill(t_data *data, int y, int x)
{
	if (data->map2[y][x] == '1' || data->map2[y][x] == 'X')
		return ;
	data->map2[y][x] = 'X';
	check_floodfill(data, y, x + 1);
	check_floodfill(data, y, x - 1);
	check_floodfill(data, y + 1, x);
	check_floodfill(data, y - 1, x);
}

void	mapping_testing(t_data *data)
{
	
}


void	floodfill(t_data *data)
{
	int i;
	int h;

	i = 0;
	h = 0;
	while(data->map2[i])
	{
		h = 0;
		while(data->map2[i][h])
		{
			if(is_player(data->map2[i][h]) == 1)
				break ;
			h++;
		}
		i++;
	}
	check_floodfill(data, i, h);
	
}
