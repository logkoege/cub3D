/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/16 23:18:18 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_player_loop(t_data *data)
{
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img);
	draw_map(data);
	draw_player(data->player->pos_x, data->player->pos_y, 10, 0xFFFFFF, data);
	double	ray_x = data->player->pos_x;
	double	ray_y = data->player->pos_y;
	while(!line_to_wall(ray_x, ray_y, data))
	{
		mlx_pxl(data->img, ray_x, ray_y, 0xFF0000);
		ray_x += data->player->cos_angle;
		ray_y += data->player->sin_angle;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	clear_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while(j < WIDTH)
		{
			mlx_pxl(data->img, i, j, 0);
			j++;
		}
		i++;
	}
}

void	map(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000000000001";
	map[3] = "100000001000001";
	map[4] = "100000001000001";
	map[5] = "100000000100001";
	map[6] = "100000000000001";
	map[7] = "100000001110001";
	map[8] = "100000000000001";
	map[9] = "111111111111111";
	map[10] = NULL;
	data->map = map;
	while (data->map[i])
	{
		printf("map[%d] = %s\n", i, map[i]);
		i++;
	}

}
void	draw_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_player(j * S_SQUARE, i * S_SQUARE, S_SQUARE, 0x00FF00, data);
			j++;
		}
		i++;
	}
}
