/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:11 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/17 18:39:54 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	press(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == W)
		data->front = true;
	else if (keycode == A)
		data->left = true;
	else if (keycode == S)
		data->back = true;
	else if (keycode == D)
		data->right = true;
	else if (keycode == RIGHT)
		data->camera_right = true;
	else if (keycode == LEFT)
		data->camera_left = true;
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
	else if (keycode == RIGHT)
		data->camera_right = false;
	else if (keycode == LEFT)
		data->camera_left = false;
	return (0);
}

void	free_mlx(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img->img);
	data->img->img = NULL;
	mlx_destroy_window(data->mlx, data->win);
	data->win = NULL;
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	data->mlx = NULL;
}

void	init_var3(t_tex *tex)
{
	tex->tex_width_N = 0;
	tex->tex_width_S = 0;
	tex->tex_width_W = 0;
	tex->tex_width_E = 0;
	tex->tex_height_N = 0;
	tex->tex_height_S = 0;
	tex->tex_height_W = 0;
	tex->tex_height_E = 0;
}
