/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/08 11:03:31 by lloginov         ###   ########.fr       */
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

int	get_wall_dir(int side, double ray_dir_x, double ray_dir_y)
{
	if (side == 0)
	{
		if (ray_dir_x > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray_dir_y > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
}

void draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir)
{
    int y;
    int tex_x;
    int tex_y;
    int color;
    double step;
    double tex_pos;
    int wall_height;

    wall_height = end_y - start_y;
    tex_x = (int)((double)x / WIDTH * data->tex->tex_width);
    if (tex_x < 0)
        tex_x = 0;
    if (tex_x >= data->tex->tex_width)
        tex_x = data->tex->tex_width - 1;

    if (wall_dir == WEST || wall_dir == SOUTH)
        tex_x = data->tex->tex_width - tex_x - 1;
    step = 1.0 * data->tex->tex_height / wall_height;
    tex_pos = (start_y - (HEIGHT / 2) + (wall_height / 2)) * step;
    y = start_y;
    while (y < end_y)
    {
        tex_y = (int)tex_pos;
        if (tex_y < 0)
            tex_y = 0;
        if (tex_y >= data->tex->tex_height)
            tex_y = data->tex->tex_height - 1;

        color = ((int *)data->tex->addr[wall_dir])[tex_y * (data->tex->line_len / 4) + tex_x];
        mlx_pxl(data->img, x, y, color);

        tex_pos += step;
        y++;
    }
}


