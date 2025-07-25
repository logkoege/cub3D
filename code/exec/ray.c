/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:20:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/08 10:01:51 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	line_to_wall(double px, double py, t_data *data)
{
	int	x;
	int	y;

	x = px / S_SQUARE;
	y = py / S_SQUARE;
	if (y < 0 || y >= HEIGHT || x < 0 || x >= WIDTH || data->mapo[y][x] == '\0')
		return (true);
	if (data->mapo[y][x] == '1')
		return (true);
	return (false);
}

double	sqr(double a)
{
	return (a * a);
}

double	squirt(double x1, double x2, double y1, double y2)
{
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}
