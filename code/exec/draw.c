/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/11 14:45:05 by logkoege         ###   ########.fr       */
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
	data->mapo = map1;
	data->map_pos_x = 6;
	data->map_pos_y = 6;
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

int	draw_player_loop(t_data *data)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	half_fov;
	double	plane_factor;

	x = 0;
	half_fov = PI / 6.0;
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img);
	if (DD_MOD)
	{
		draw_player(data->player->pos_x, data->player->pos_y, data);
		draw_map(data);
	}
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		plane_factor = tan(half_fov);
		ray_dir_x = data->player->cos_angle + (-data->player->sin_angle) * plane_factor * camera_x;
		ray_dir_y = data->player->sin_angle + data->player->cos_angle * plane_factor * camera_x;

		draw_ray(data, ray_dir_x, ray_dir_y, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	draw_ray(t_data *data, double ray_dir_x, double ray_dir_y, int x)
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perpwalldist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;

	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	map_x = (int)pos_x;
	map_y = (int)pos_y;
	hit = 0;
	delta_dist_x = fabs(1.0 / ray_dir_x);
	delta_dist_y = fabs(1.0 / ray_dir_y);
	data->ray_dir_x = ray_dir_x;
	data->ray_dir_y = ray_dir_y;
	if (data->ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
	}
	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_y < 0 || !data->mapo[map_y] || map_x < 0
			|| map_x >= (int)ft_strlen(data->mapo[map_y]))
			break ;
		if (data->mapo[map_y][map_x] == '1')
			hit = 1;
	}
	if (side == 0)
		perpwalldist = (map_x - pos_x + (1 - step_x) / 2.0) / ray_dir_x;
	else
		perpwalldist = (map_y - pos_y + (1 - step_y) / 2.0) / ray_dir_y;
	data->side = side;
	data->step_x = step_x;
	data->step_y = step_y;
	data->distance = perpwalldist;
	if (side == 0)
		wall_x = pos_y + perpwalldist * data->ray_dir_y;
	else
		wall_x = pos_x + perpwalldist * data->ray_dir_x;
	wall_x -= floor(wall_x);
	if (side == 0 && step_x < 0)
		wall_x = 1.0 - wall_x;
	if (side == 1 && step_y > 0)
		wall_x = 1.0 - wall_x;
	data->wall_x = wall_x;
	data->wall_dir = get_wall_dir(data);
	line_height = (int)((double)HEIGHT / perpwalldist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (!DD_MOD)
		draw_texture_column(data, x,
			draw_start, draw_end, data->wall_dir, wall_x);
}
