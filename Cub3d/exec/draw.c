/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/17 19:28:50 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	map1[1] = "101000000000001";
	map1[2] = "100000001111111";
	map1[3] = "100000000000001";
	map1[4] = "100001000000001";
	map1[5] = "100000010000001";
	map1[6] = "100000000100001";
	map1[7] = "111000011110001";
	map1[8] = "100000000100001";
	map1[9] = "111111111111111";
	map1[10] = NULL;
	data->map2 = map1;
	data->map_pos_x = 6;
	data->map_pos_y = 6;
	while (data->map2[i])
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
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == '1')
				draw_player2(j * S_SQUARE, i
					* S_SQUARE, data);
			j++;
		}
		i++;
	}
}

int	draw_player_loop(t_data *data)
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	half_fov;
	double	plane_factor;

	data->x = 0;
	half_fov = PI / 6.0;
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img, data);
	while (data->x < WIDTH)
	{
		camera_x = 2.0 * data->x / (double)WIDTH - 1.0;
		plane_factor = tan(half_fov);
		ray_dir_x = data->player->cos_angle
			+ (-data->player->sin_angle) * plane_factor * camera_x;
		ray_dir_y = data->player->sin_angle
			+ data->player->cos_angle * plane_factor * camera_x;
		draw_ray(data, ray_dir_x, ray_dir_y);
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	draw_ray(t_data *data, double ray_dir_x, double ray_dir_y)
{
	data->map_x = (int)data->player->pos_x;
	data->map_y = (int)data->player->pos_y;
	data->hit = 0;
	data->delta_dist_x = fabs(1.0 / ray_dir_x);
	data->delta_dist_y = fabs(1.0 / ray_dir_y);
	data->ray_dir_x = ray_dir_x;
	data->ray_dir_y = ray_dir_y;
	part_1(data);
	part_2(data);
	part_3(data);
	part_4(data);
}
