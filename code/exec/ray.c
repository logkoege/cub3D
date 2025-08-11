/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:20:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/09 14:32:18 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

double	sqr(double a)
{
	return (a * a);
}

double	squirt(double x1, double x2, double y1, double y2)
{
	return (sqrt(sqr(y2 - y1) + sqr(x2 - x1)));
}
