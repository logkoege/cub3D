/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_tex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 18:46:48 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/19 20:35:13 by logkoege         ###   ########.fr       */
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
	tex_x = (int)(percent_x * data->tex->tex_width_n);
	if (tex_x >= data->tex->tex_width_n)
		tex_x = data->tex->tex_width_n - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_n);
		if (tex_y >= data->tex->tex_height_n)
			tex_y = data->tex->tex_height_n - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_n + tex_x];
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
	tex_x = (int)(percent_x * data->tex->tex_width_s);
	if (tex_x >= data->tex->tex_width_s)
		tex_x = data->tex->tex_width_s - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_s);
		if (tex_y >= data->tex->tex_height_s)
			tex_y = data->tex->tex_height_s - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_s + tex_x];
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
	tex_x = (int)(percent_x * data->tex->tex_width_w);
	if (tex_x >= data->tex->tex_width_w)
		tex_x = data->tex->tex_width_w - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_w);
		if (tex_y >= data->tex->tex_height_w)
			tex_y = data->tex->tex_height_w - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_w + tex_x];
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
	tex_x = (int)(percent_x * data->tex->tex_width_e);
	if (tex_x >= data->tex->tex_width_e)
		tex_x = data->tex->tex_width_e - 1;
	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height_e);
		if (tex_y >= data->tex->tex_height_e)
			tex_y = data->tex->tex_height_e - 1;
		color = data->tex->pixels[data->wall_dir][tex_y
			*data->tex->tex_width_e + tex_x];
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
