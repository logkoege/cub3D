/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 18:29:40 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_player *player)
{
		player->pos_x = WIDTH / 2;
		player->pos_y = HEIGHT / 2;
		player->dir_x = -1;
		player->dir_y = 0;
		player->cam_plane_x = 0;
		player->cam_plane_y = 0.66;
		player->oldtime = 0;
		player->time = 0;
		player->camera_x = 0;
		player->raydir_x = 0;
		player->raydir_y = 0;
}

void	init_var(t_data *data, t_image *img, t_player *player)
{
	data->mlx = NULL;
	data->win = NULL;
	data->frame = 5;
	img->img = NULL;
	data->right = false;
	data->left = false;
	data->front = false;
	data->back = false;
	init_player(player);
}

void	ft_freexit(t_data *data, char *msg)
{
	(void)data;
	printf("%s", msg);
	exit(0);
}

int	ft_close(t_data *data)
{
	ft_freexit(data, "");
	return (0);
}
