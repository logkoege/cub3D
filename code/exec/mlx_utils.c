/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:09:45 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 18:08:52 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data, t_image *img)
{
	//int	i;
	//int	j;

	//i = 0;
	//j = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_freexit(data, "Error : mlx initialisation");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "LevPD");
	if (!data->win)
		ft_freexit(data, "Error : window initialisation");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_pxl, &img->line_len,
			&img->endian);
	//mlx_draw(i, j, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void	mlx_pxl(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bit_pxl / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw(int i, int j, t_image *img)
{
	while (i <= WIDTH)
	{
		j = 0;
		while (j <= HEIGHT)
		{
			if (j <= HEIGHT / 2)
				mlx_pxl(img, i, j, 0x77B5FE);
			else
				mlx_pxl(img, i, j, 0x3A9D23);
			j++;
		}
		i++;
	}
}

void	twod_map(t_image *img, t_player *player)
{
	draw_player(10, 0X00FF00, img, player);
}

void	draw_player(int p_size, int color, t_image *img, t_player *player)
{
	int	i;

	i = 0;
	while(i <= p_size)
	{
		mlx_pxl(img, player->pos_x + i, player->pos_y, color);
		i++;
	}
	i = 0;
	while(i <= p_size)
	{
		mlx_pxl(img, player->pos_x, player->pos_y + i, color);
		i++;
	}
	i = 0;
	while(i <= p_size)
	{
		mlx_pxl(img, player->pos_x + p_size, player->pos_y + i, color);
		i++;
	}
	i = 0;
	while(i <= p_size)
	{
		mlx_pxl(img, player->pos_x + i, player->pos_y + p_size, color);
		i++;
	}
}
