/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:20:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/16 23:02:43 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	line_to_wall(double px, double py, t_data *data)
{
	int	x;
	int	y;

	x = px / S_SQUARE;
	y = py / S_SQUARE;
	if (data->map[y][x] == '1')
		return (true);
	return (false);
}