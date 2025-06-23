/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:50:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/06/24 00:15:46 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_intructs(t_data *data, t_player *player)
{
	player->speed = 3;
	player->angle_speed = 0.05;
	player->cos_angle = cos(player->angle);
	player->sin_angle = sin(player->angle);
	if (data->camera_left)
		player->angle -= player->angle_speed;
	if (data->camera_right)
		player->angle += player->angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	player_camera(data, player);
}

void	easter_egg(void)
{
	printf("tp dans une piece ou il y a tourpal tt nue\n");
}

void	player_camera(t_data *data, t_player *player)
{
	if (data->front)
	{
		if (!line_to_wall(player->pos_x + player->cos_angle * player->speed,
				player->pos_y + player->sin_angle * player->speed, data))
		{
			player->pos_x += player->cos_angle * player->speed;
			player->pos_y += player->sin_angle * player->speed;
		}
	}
	if (data->left)
	{
		if (!line_to_wall(player->pos_x + player->sin_angle * player->speed,
				player->pos_y - player->cos_angle * player->speed, data))
		{
			player->pos_x += player->sin_angle * player->speed;
			player->pos_y -= player->cos_angle * player->speed;
		}
	}
	player_camera_2(data, player);
}

void	player_camera_2(t_data *data, t_player *player)
{
	if (data->right)
	{
		if (!line_to_wall(player->pos_x - player->sin_angle * player->speed,
				player->pos_y + player->cos_angle * player->speed, data))
		{
			player->pos_x -= player->sin_angle * player->speed;
			player->pos_y += player->cos_angle * player->speed;
		}
	}
	if (data->back)
	{
		if (!line_to_wall(player->pos_x - player->cos_angle * player->speed,
				player->pos_y - player->sin_angle * player->speed, data))
		{
			player->pos_x -= player->cos_angle * player->speed;
			player->pos_y -= player->sin_angle * player->speed;
		}
	}
}
