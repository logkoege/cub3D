/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/15 20:42:52 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_tex *tex, t_data *data)
{
	int	i;

	i = 0;
	tex->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
			"texture/test.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
			"texture/test.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[WEST] = mlx_xpm_file_to_image(data->mlx, \
			"texture/test.xpm", &tex->tex_width, &tex->tex_height);
	tex->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
			"texture/test.xpm", &tex->tex_width, &tex->tex_height);
	if (!tex->textures[NORTH] || !tex->textures[SOUTH]
		|| !tex->textures[WEST] || !tex->textures[EAST])
	{
		printf("Error loading textures\n");
		exit(EXIT_FAILURE);
	}
	while (i < 4)
	{
		/*tex->addr[i] = mlx_get_data_addr(tex->textures[i],
				&tex->bpp, &tex->line_len, &tex->endian);*/
		tex->pixels[i] = (t_pixel *)mlx_get_data_addr(tex->textures[i],
				&tex->bpp, &tex->line_len, &tex->endian);
		i++;
	}
}

int	get_wall_dir(double ray_dir_x, double ray_dir_y)
{
	if (ray_dir_y > 0)
	{
		if (ray_dir_x > 0)
		{
			if (ray_dir_y > ray_dir_x)
			{
				return (SOUTH);
			}
			else
			{
				return (EAST);
			}
		}
		else
		{
			if (ray_dir_y > -ray_dir_x)
			{
				return (SOUTH);
			}
			else
			{
				return (WEST);
			}
		}
	}
	else
	{
		if (ray_dir_x > 0)
		{
			if (-ray_dir_y > ray_dir_x)
			{
				return (NORTH);
			}
			else
			{
				return (EAST);
			}
		}
		else
		{
			if (ray_dir_y < ray_dir_x)
			{
				return (NORTH);
			}
			else
			{
				return (WEST);
			}
		}
	}
}

int	get_tex_color(t_tex *tex, int dir, int x, int y)
{
	char	*pixel;
	int		color;
	int		offset;

	if (dir == NORTH)
		pixel = tex->addr[NORTH];
	else if (dir == SOUTH)
		pixel = tex->addr[SOUTH];
	else if (dir == WEST)
		pixel = tex->addr[WEST];
	else
		pixel = tex->addr[EAST];
	offset = (y * tex->line_len) + (x * (tex->bpp / 8));
	color = *(int *)(pixel + offset);
	return (color);
}

void	draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir, double percent_x)
{
	int		i;
	t_pixel color;
	double percent_y;

	(void)x;

	wall_dir = NORTH;

	i = start_y;
	data->tex->wall_height = end_y - start_y;
	while (i < end_y)
	{
		percent_y = ((double)i - (double)start_y) / (double)data->tex->wall_height;
		int index = (percent_y * (double)data->tex->tex_height);
		color = (data->tex->pixels[wall_dir])[index * data->tex->tex_height + (int)(percent_x * data->tex->tex_width)];
		mlx_pxl_pixel(data->img, x, i, color);
		i++;
	}
}
