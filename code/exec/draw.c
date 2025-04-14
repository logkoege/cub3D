/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 18:38:15 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_player_loop(t_image *img, t_data *data, t_player *player)
{
	player_intructs(data, player);
	draw_player(10, 0X00FF00, img, player);
	//mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
	return (0);
}