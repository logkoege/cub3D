/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 23:28:53 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/30 20:31:46 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray(t_data *data, int i, int size, double p_x, double p_y)
{
	double ntm;

	p_x -= floor(p_x);
	p_y -= floor(p_y);
	ntm = p_x;
	if (p_y > ntm)
		ntm = p_y;
	data->start_y = (HEIGHT - size) / 2;
	data->end = data->start_y + size;
	draw_texture_column(data, i, data->start_y, data->end, data->wall_dir, ntm);
}
