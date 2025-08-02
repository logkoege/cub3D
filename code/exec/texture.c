/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/02 15:49:11 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_tex *tex, t_data *data)
{
	int	i;

	i = 0;
	tex->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
			"texture/north.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
			"texture/south.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[WEST] = mlx_xpm_file_to_image(data->mlx, \
			"texture/west.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
			"texture/east.xpm", &tex->tex_width, &tex->tex_height);
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

void draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir, double percent_x)
{
	int i;
	t_pixel color;
	double percent_y;
	int tex_x;
	int tex_y;

	wall_dir = get_wall_dir(data);

	data->tex->wall_height = end_y - start_y;
	tex_x = (int)(percent_x * data->tex->tex_width);
	if (tex_x >= data->tex->tex_width)
		tex_x = data->tex->tex_width - 1;

	i = start_y;
	while (i < end_y)
	{
		percent_y = ((double)(i - start_y)) / (double)data->tex->wall_height;
		tex_y = (int)(percent_y * data->tex->tex_height);
		if (tex_y >= data->tex->tex_height)
			tex_y = data->tex->tex_height - 1;
		color = data->tex->pixels[wall_dir][tex_y * data->tex->tex_width + tex_x];

		mlx_pxl_pixel(data->img, x, i, color);
		i++;
	}
}
