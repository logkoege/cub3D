/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:28:53 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/15 20:49:07 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray(t_data *data, int i, int size, double p_x, double p_y)
{
	p_x -= floor(p_x);
	p_y -= floor(p_y);
	double ntm = p_x;
	if (p_y > ntm) {
		ntm = p_y;
	}
	if ((int)(p_x * 100) >= 90)
		ntm = p_y;
	if ((int)(p_y * 100) >= 90)
		ntm = p_x;
	data->start_y = (HEIGHT - size) / 2;
	data->end = data->start_y + size;
	draw_texture_column(data, i, data->start_y, data->end, data->wall_dir, ntm);
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;
	int	scale;

	scale = S_SQUARE / 4;
	x = WIDTH - (15 * scale) - 10;
	y = 10;
	data->minimap_w = 15 * scale;
	data->minimap_h = 10 * scale;
	draw_minimap_end(data, x, y);
	draw_player4(data->player->pos_x / 4 + x,
		data->player->pos_y / 4 + y, data);
}

void	draw_minimap_end(t_data *data, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->minimap_h)
	{
		j = -1;
		while (++j < data->minimap_w)
			mlx_pxl(data->img, x + j, y + i, 0x111111);
		i++;
	}
	i = 0;
	while (data->mapo[i])
	{
		j = 0;
		while (data->mapo[i][j])
		{
			if (data->mapo[i][j] == '1')
				draw_player3(j * (S_SQUARE / 4) + x,
					i * (S_SQUARE / 4) + y, data);
			j++;
		}
		i++;
	}
}
