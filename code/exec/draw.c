/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/18 19:26:56 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	draw_player_loop(t_data *data)
{
	double	fraction;
	double	start_x;
	int		i;

	i = 0;
	fraction = PI / 3 / WIDTH;
	start_x = data->player->angle - PI / 6;
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img);
	if (DD_MOD)
	{
		draw_player(data->player->pos_x, data->player->pos_y, 10, 0xFFFFFF, data);
		draw_map(data);
	}
	while (i < WIDTH)
	{
		draw_ray(data, data->player, start_x, i);
		i++;
		start_x += fraction;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	clear_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_pxl(data->img, i, j, 0);
			j++;
		}
		i++;
	}
}

void	map(t_data *data)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc(sizeof(char *) * 11);
	map[0] = "111111111111111";
	map[1] = "100000000000001";
	map[2] = "100000001000001";
	map[3] = "100000000000001";
	map[4] = "100001000000001";
	map[5] = "100000010000001";
	map[6] = "100000000100001";
	map[7] = "100000001110001";
	map[8] = "100000000100001";
	map[9] = "111111111111111";
	map[10] = NULL;
	data->map = map;
	while (data->map[i])
	{
		printf("map[%d] = %s\n", i, map[i]);
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_player(j * S_SQUARE, i * S_SQUARE, S_SQUARE, 0x00FF00, data);
			j++;
		}
		i++;
	}
}

void	draw_ray(t_data *data, t_player *player, double start_x, int i)
{
	int		end;
	int		start_y;
	double	ray_x;
	double	ray_y;
	double	cos2;
	double	sin2;
	double	size;
	double	distance;

	cos2 = cos(start_x);
	sin2 = sin(start_x);
	ray_x = player->pos_x;
	ray_y = player->pos_y;
	while(!line_to_wall(ray_x, ray_y, data))
	{
		if (DD_MOD)
			mlx_pxl(data->img, ray_x, ray_y, 0xFF0000);
		ray_x += cos2;
		ray_y += sin2;
	}
	if (!DD_MOD)
	{
		distance = squirt(ray_x, player->pos_x, ray_y, player->pos_y);
		size = ((WIDTH / 2) * (S_SQUARE / distance));
		start_y = (HEIGHT - size) / 2;
		end = start_y + size;
			while (start_y < end)
		{
			mlx_pxl(data->img, i, start_y, 0x0000FF);
			start_y++;
		}
	}
}
