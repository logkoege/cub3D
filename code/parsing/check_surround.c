/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_surround.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:11:04 by lloginov          #+#    #+#             */
/*   Updated: 2025/07/02 13:25:24 by lloginov         ###   ########.fr       */
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
	if(x > data->line_len - 1 || x < 0)
		return ;
	if(y > data->true_map_len - 1 || y < 0)
		return ;
	if (data->map2[y][x] == '1' || data->map2[y][x] == 'X' || data->map2[y][x] == '\n' || data->map2[y][x] == '\0')
		return ;
	// print_map(data->map2);
	// printf("\nAAAAAAA Y %dET IKS %d\n", y, x);
	data->map2[y][x] = 'X';
	check_floodfill(data, y, x + 1);
	check_floodfill(data, y, x - 1);
	check_floodfill(data, y + 1, x);
	check_floodfill(data, y - 1, x);
}

// void	mapping_testing(t_data *data, int y, int x)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;

// 	while(data->map2[0][j])
// 	{
// 		if(data->map[0][j] == 'X')
// 			free_map_exit(data, "Error : first line not closed")
		

// 	}
// }

void	floodfill(t_data *data)
{

	printf(" i et h : %d %d\n", data->line_len, data->true_map_len);
	check_floodfill(data, data->player_y, data->player_x);
	print_map(data->map2);
	// printf("ASASASDSDSDSDSA\n\n\n\n");
	exit(1);
	// mapping_testing(data, i, h);
}
