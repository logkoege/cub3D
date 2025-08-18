/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:46:48 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/18 13:08:54 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_texture_n(t_data *data, int start_y, int end_y, double percent_x)
{
	int		i;
	t_pixel	color;
	double	percent_y;
	int		tex_x;
	int		tex_y;

	data->wall_dir = get_wall_dir(data);
	data->tex->wall_height = end_y - start_y;
	tex_x = (int)(percent_x * data->tex->tex_width_N);
	if (tex_x >= data->tex->tex_width_N)
		tex_x = data->tex->tex_width_N - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_N);
		if (tex_y >= data->tex->tex_height_N)
			tex_y = data->tex->tex_height_N - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_N + tex_x];
		mlx_pxl_pixel(data->img, data->x, i, color);
		i++;
	}
}

void	draw_texture_s(t_data *data, int start_y, int end_y, double percent_x)
{
	int		i;
	t_pixel	color;
	double	percent_y;
	int		tex_x;
	int		tex_y;

	data->wall_dir = get_wall_dir(data);
	data->tex->wall_height = end_y - start_y;
	tex_x = (int)(percent_x * data->tex->tex_width_S);
	if (tex_x >= data->tex->tex_width_S)
		tex_x = data->tex->tex_width_S - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_S);
		if (tex_y >= data->tex->tex_height_S)
			tex_y = data->tex->tex_height_S - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_S + tex_x];
		mlx_pxl_pixel(data->img, data->x, i, color);
		i++;
	}
}

void	draw_texture_w(t_data *data, int start_y, int end_y, double percent_x)
{
	int		i;
	t_pixel	color;
	double	percent_y;
	int		tex_x;
	int		tex_y;

	data->wall_dir = get_wall_dir(data);
	data->tex->wall_height = end_y - start_y;
	tex_x = (int)(percent_x * data->tex->tex_width_W);
	if (tex_x >= data->tex->tex_width_W)
		tex_x = data->tex->tex_width_W - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_W);
		if (tex_y >= data->tex->tex_height_W)
			tex_y = data->tex->tex_height_W - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_W + tex_x];
		mlx_pxl_pixel(data->img, data->x, i, color);
		i++;
	}
}

void	draw_texture_e(t_data *data, int start_y, int end_y, double percent_x)
{
	int		i;
	t_pixel	color;
	double	percent_y;
	int		tex_x;
	int		tex_y;

	data->wall_dir = get_wall_dir(data);
	data->tex->wall_height = end_y - start_y;
	tex_x = (int)(percent_x * data->tex->tex_width_E);
	if (tex_x >= data->tex->tex_width_E)
		tex_x = data->tex->tex_width_E - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_E);
		if (tex_y >= data->tex->tex_height_E)
			tex_y = data->tex->tex_height_E - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_E + tex_x];
		mlx_pxl_pixel(data->img, data->x, i, color);
		i++;
	}
}

void	bonus(int keycode, t_data *data)
{
	if (keycode == G)
	{
		destroy_textures(data->tex, data);
		load_texture(data->tex, data);
	}
	else if (keycode == H)
	{
		destroy_textures(data->tex, data);
		load_textures(data->tex, data);
	}
}
