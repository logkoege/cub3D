/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:19:22 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/17 19:29:51 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	part_1(t_data *data)
{
	if (data->ray_dir_x < 0)
	{
		data->step_x = -1;
		data->side_dist_x = (data->player->pos_x
				- data->map_x) * data->delta_dist_x;
	}
	else
	{
		data->step_x = 1;
		data->side_dist_x = (data->map_x + 1.0
				- data->player->pos_x) * data->delta_dist_x;
	}
	if (data->ray_dir_y < 0)
	{
		data->step_y = -1;
		data->side_dist_y = (data->player->pos_y
				- data->map_y) * data->delta_dist_y;
	}
	else
	{
		data->step_y = 1;
		data->side_dist_y = (data->map_y + 1.0
				- data->player->pos_y) * data->delta_dist_y;
	}
}

void	part_2(t_data *data)
{
	while (data->hit == 0)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_dist_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_dist_y;
			data->map_y += data->step_y;
			data->side = 1;
		}
		if (data->map_y < 0 || !data->map2[data->map_y] || data->map_x < 0
			|| data->map_x >= (int)ft_strlen(data->map2[data->map_y]))
			break ;
		if (data->map2[data->map_y][data->map_x] == '1')
			data->hit = 1;
	}
}

void	part_3(t_data *data)
{
	if (data->side == 0)
		data->perpwalldist = (data->map_x - data->player->pos_x
				+ (1 - data->step_x) / 2.0) / data->ray_dir_x;
	else
		data->perpwalldist = (data->map_y - data->player->pos_y
				+ (1 - data->step_y) / 2.0) / data->ray_dir_y;
	data->distance = data->perpwalldist;
	if (data->side == 0)
		data->wall_x = data->player->pos_y
			+ data->perpwalldist * data->ray_dir_y;
	else
		data->wall_x = data->player->pos_x
			+ data->perpwalldist * data->ray_dir_x;
	data->wall_x -= floor(data->wall_x);
	if (data->side == 0 && data->step_x < 0)
		data->wall_x = 1.0 - data->wall_x;
	if (data->side == 1 && data->step_y > 0)
		data->wall_x = 1.0 - data->wall_x;
	data->line_height = (int)((double)HEIGHT / data->perpwalldist);
	data->draw_start = -data->line_height / 2 + HEIGHT / 2;
	data->draw_end = data->line_height / 2 + HEIGHT / 2;
	data->wall_dir = get_wall_dir(data);
}

void	part_4(t_data *data)
{
	if (data->wall_dir == NORTH)
		draw_texture_n(data, data->draw_start, data->draw_end, data->wall_x);
	else if (data->wall_dir == SOUTH)
		draw_texture_s(data, data->draw_start, data->draw_end, data->wall_x);
	else if (data->wall_dir == WEST)
		draw_texture_w(data, data->draw_start, data->draw_end, data->wall_x);
	else
		draw_texture_e(data, data->draw_start, data->draw_end, data->wall_x);
}
