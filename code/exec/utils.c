/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/02 15:52:40 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_player *player, t_data *data, char start_dir)
{
	player->pos_x = data->map_pos_x + 0.5;
	player->pos_y = data->map_pos_y + 0.5;
	if (start_dir == 'N')
		player->angle = 3 * PI / 2;
	else if (start_dir == 'S')
		player->angle = PI / 2;
	else if (start_dir == 'E')
		player->angle = 0;
	else if (start_dir == 'W')
		player->angle = PI;
}

void	init_var(t_data *data, t_image *img, t_player *player)
{
	char	start_dir;

	data->mlx = NULL;
	data->win = NULL;
	data->frame = 5;
	img->img = NULL;
	data->right = false;
	data->left = false;
	data->front = false;
	data->back = false;
	data->camera_right = false;
	data->camera_left = false;
	start_dir = 'N';
	printf("start_dir = %c\n", start_dir);
	init_player(player, data, start_dir);
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
