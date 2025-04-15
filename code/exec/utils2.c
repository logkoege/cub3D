/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:11 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/15 19:22:23 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	press(int keycode, t_data *data)
{
	
	if (keycode == ESC)
		ft_freexit(data, "");
	else if (keycode == W)
		data->front = true;
	else if (keycode == A)
		data->left = true;
	else if (keycode == S)
		data->back = true;
	else if (keycode == D)
		data->right = true;
	else if (keycode == G)
		easter_egg();
	else if (keycode == W)
		data->front = true;
	else if (keycode == A)
		data->left = true;
	else if (keycode == S)
		data->back = true;
	else if (keycode == D)
		
	return (0);
}
int	release(int keycode, t_data *data)
{
	if (keycode == W)
		data->front = false;
	else if (keycode == A)
		data->left = false;
	else if (keycode == S)
		data->back = false;
	else if (keycode == D)
		data->right = false;
	return (0);
}