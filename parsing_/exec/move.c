/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:50:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/11 16:22:47 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	can_move(t_data *data, double next_x, double next_y)
{
	int	map_x;
	int	map_y;

	map_x = (int)next_x;
	map_y = (int)next_y;
	if (map_y < 0 || !data->map2[map_y])
		return (false);
	if (map_x < 0 || map_x >= (int)strlen(data->map2[map_y]))
		return (false);
	if (data->map2[map_y][map_x] == '1')
		return (false);
	return (true);
}

void	player_intructs(t_data *data, t_player *player)
{
	player->speed = 0.08;
	player->angle_speed = 0.05;
	if (data->camera_left)
		player->angle -= player->angle_speed;
	if (data->camera_right)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle -= 2 * PI;
	if (player->angle < 0)
		player->angle += 2 * PI;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	player_camera(data, player);
}

void	player_camera(t_data *data, t_player *player)
{
	double	nx;
	double	ny;

	if (data->front)
	{
		nx = player->pos_x + player->cos_angle * 0.08;
		ny = player->pos_y + player->sin_angle * 0.08;
		if (can_move(data, nx, ny))
		{
			player->pos_x = nx;
			player->pos_y = ny;
		}
	}
	if (data->left)
	{
		nx = player->pos_x + player->sin_angle * 0.08;
		ny = player->pos_y - player->cos_angle * 0.08;
		if (can_move(data, nx, ny))
		{
			player->pos_x = nx;
			player->pos_y = ny;
		}
	}
	player_camera_2(data, player);
}

void	player_camera_2(t_data *data, t_player *player)
{
	double	nx;
	double	ny;

	if (data->right)
	{
		nx = player->pos_x - player->sin_angle * 0.08;
		ny = player->pos_y + player->cos_angle * 0.08;
		if (can_move(data, nx, ny))
		{
			player->pos_x = nx;
			player->pos_y = ny;
		}
	}
	if (data->back)
	{
		nx = player->pos_x - player->cos_angle * 0.08;
		ny = player->pos_y - player->sin_angle * 0.08;
		if (can_move(data, nx, ny))
		{
			player->pos_x = nx;
			player->pos_y = ny;
		}
	}
}
