/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:50:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 18:37:42 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_intructs(t_data *data, t_player *player)
{
	printf("p\n");
	if (data->front)
	{
		player->pos_y -= 5;
		printf("Front Y = %f\n", player->pos_y);
	}
	else if (data->left)
	{
		player->pos_x -= 5;
		printf("Left X = %f\n", player->pos_x);
	}
	else if (data->right)
	{
		printf("Right X = %f\n", player->pos_x);
		player->pos_x += 5;
	}
	else if (data->back)
	{
		printf("Back Y = %f\n", player->pos_y);
		player->pos_y += 5;
	}
	printf("la\n");
}

void	easter_egg()
{
	printf("tp dans une piece ou il y a tourpal tt nue\n");
}
