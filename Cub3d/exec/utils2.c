/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:49:11 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/19 20:33:27 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_texture(t_tex *tex, t_data *data)
{
	int	i;

	i = 0;
	tex->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
			"textures/north.xpm", &tex->tex_width_n, &tex->tex_height_n);
	tex->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
			"textures/south.xpm", &tex->tex_width_s, &tex->tex_height_s);
	tex->textures[WEST] = mlx_xpm_file_to_image(data->mlx,
			"textures/west.xpm", &tex->tex_width_w, &tex->tex_height_w);
	tex->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
			"textures/east.xpm", &tex->tex_width_e, &tex->tex_height_e);
	if (!tex->textures[NORTH] || !tex->textures[SOUTH]
		|| !tex->textures[WEST] || !tex->textures[EAST])
	{
		printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	while (i < 4)
	{
		tex->pixels[i] = (t_pixel *)mlx_get_data_addr(tex->textures[i],
				&tex->bpp, &tex->line_len, &tex->endian);
		i++;
	}
}

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
	else if ((keycode == G || keycode == H) && BONUS)
		bonus(keycode, data);
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
	tex->tex_width_n = 0;
	tex->tex_width_s = 0;
	tex->tex_width_w = 0;
	tex->tex_width_e = 0;
	tex->tex_height_n = 0;
	tex->tex_height_s = 0;
	tex->tex_height_w = 0;
	tex->tex_height_e = 0;
}
