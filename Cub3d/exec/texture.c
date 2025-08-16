/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/16 19:01:51 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_tex *tex, t_data *data)
{
	int	i;

	i = 0;
	tex->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
			data->file_north, &tex->tex_width_N, &tex->tex_height_N);
	tex->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
			data->file_south, &tex->tex_width_S, &tex->tex_height_S);
	tex->textures[WEST] = mlx_xpm_file_to_image(data->mlx,
			data->file_west, &tex->tex_width_W, &tex->tex_height_W);
	tex->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
			data->file_east, &tex->tex_width_E, &tex->tex_height_E);
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

int	get_wall_dir(t_data *data)
{
	if (data->side == 0)
	{
		if (data->step_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (data->step_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void	draw_texture_column_N(t_data *data, int start_y, int end_y, double percent_x)
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
void	draw_texture_column_S(t_data *data, int start_y, int end_y, double percent_x)
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

void	draw_texture_column_W(t_data *data, int start_y, int end_y, double percent_x)
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

void	draw_texture_column_E(t_data *data, int start_y, int end_y, double percent_x)
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
