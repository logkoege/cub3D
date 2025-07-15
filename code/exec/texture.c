/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/11 20:29:52 by logkoege         ###   ########.fr       */
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
		tex->addr[i] = mlx_get_data_addr(tex->textures[i],
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
				printf("south\n");
				return (SOUTH);
			}
			else
			{
				printf("east\n");
				return (EAST);
			}
		}
		else
		{
			if (ray_dir_y > -ray_dir_x)
			{
				printf("south\n");
				return (SOUTH);
			}
			else
			{
				printf("west\n");
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
				printf("north\n");
				return (NORTH);
			}
			else
			{
				printf("east\n");
				return (EAST);
			}
		}
		else
		{
			if (ray_dir_y < ray_dir_x)
			{
				printf("north\n");
				return (NORTH);
			}
			else
			{
				printf("west\n");
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

void	draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir)
{
	data->tex->wall_height = end_y - start_y;
	data->tex->tex_x = (int)(data->wall_x * (double)data->tex->tex_width);
	if (wall_dir == EAST || wall_dir == SOUTH)
		data->tex->tex_x = data->tex->tex_width - data->tex->tex_x - 1;
	data->tex->step = 1.0 * data->tex->tex_width / data->tex->wall_height;
	data->tex->tex_pos = 0; //(start_y - HEIGHT / 2 + data->tex->wall_height / 2);
	data->tex->y = start_y;
	while (data->tex->y < end_y)
	{
		data->tex->tex_y = (int)data->tex->tex_pos;
		data->tex->color = ((int *)data->tex->addr[wall_dir])[data->tex->tex_y * (data->tex->line_len / 4) + data->tex->tex_x];
		mlx_pxl(data->img, x, data->tex->y, data->tex->color);
		data->tex->tex_pos += data->tex->step;
		data->tex->y++;
	}
}
