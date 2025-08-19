/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 18:58:54 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/19 20:34:00 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_textures(t_tex *tex, t_data *data)
{
	int	i;

	i = 0;
	tex->textures[NORTH] = mlx_xpm_file_to_image(data->mlx,
			data->file_north, &tex->tex_width_n, &tex->tex_height_n);
	tex->textures[SOUTH] = mlx_xpm_file_to_image(data->mlx,
			data->file_south, &tex->tex_width_s, &tex->tex_height_s);
	tex->textures[WEST] = mlx_xpm_file_to_image(data->mlx,
			data->file_west, &tex->tex_width_w, &tex->tex_height_w);
	tex->textures[EAST] = mlx_xpm_file_to_image(data->mlx,
			data->file_east, &tex->tex_width_e, &tex->tex_height_e);
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
