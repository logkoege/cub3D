/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/08 10:19:22 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_player_loop(t_data *data)
{
	double	fraction;
	double	start_x;
	int		i;

	i = 0;
	fraction = PI / 3 / WIDTH;
	start_x = data->player->angle - PI / 6;
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img);
	if (DD_MOD)
	{
		draw_player(data->player->pos_x, data->player->pos_y, data);
		draw_map(data);
	}
	while (i < WIDTH)
	{
		draw_ray(data, start_x, i);
		i++;
		start_x += fraction;
	}
	if (!DD_MOD)
		draw_minimap(data);
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
		while (j < WIDTH)
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
	char	**map1;

	i = 0;
	map1 = malloc(sizeof(char *) * 11);
	map1[0] = "111111111111111";
	map1[1] = "100000000000001";
	map1[2] = "100000001000001";
	map1[3] = "100000000000001";
	map1[4] = "100001000000001";
	map1[5] = "100000010000001";
	map1[6] = "100000000100001";
	map1[7] = "100000001110001";
	map1[8] = "100000000100001";
	map1[9] = "111111111111111";
	map1[10] = NULL;
	data->mapo = map1;
	while (data->mapo[i])
	{
		printf("map[%d] = %s\n", i, map1[i]);
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapo[i])
	{
		j = 0;
		while (data->mapo[i][j])
		{
			if (data->mapo[i][j] == '1')
				draw_player2(j * S_SQUARE, i
					* S_SQUARE, data);
			j++;
		}
		i++;
	}
}

void	draw_ray(t_data *data, double start_x, int i)
{
	double	ray_x;
	double	ray_y;
	double	cos2;
	double	sin2;
	double	size;
	double	dist;

	cos2 = cos(start_x);
	sin2 = sin(start_x);
	ray_x = data->player->pos_x;
	ray_y = data->player->pos_y;
	while (!line_to_wall(ray_x, ray_y, data))
	{
		if (DD_MOD)
			mlx_pxl(data->img, ray_x, ray_y, 0xFF0000);
		ray_x += cos2;
		ray_y += sin2;
	}
	data->ray_dir_x = cos2;
	data->ray_dir_y = sin2;
	dist = squirt(ray_x, data->player->pos_x, ray_y, data->player->pos_y);
	data->distance = dist * cos(start_x - data->player->angle);
	if (data->side == 0)
		data->wall_x = data->player->pos_y + data->distance * sin(start_x);
	else
		data->wall_x = data->player->pos_x + data->distance * cos(start_x);
	data->wall_x -= floor(data->wall_x);
	data->wall_dir = get_wall_dir(data->side, data->ray_dir_x, data->ray_dir_y);
	size = ((WIDTH / 2) * (S_SQUARE / data->distance));
	if (!DD_MOD)
		ray(data, i, size);
}
