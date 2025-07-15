/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:09:45 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/15 20:11:09 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_mlx(t_data *data, t_image *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->mlx = mlx_init();
	if (!data->mlx)
		ft_freexit(data, "Error : mlx initialisation");
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Cub3D");
	if (!data->win)
		ft_freexit(data, "Error : window initialisation");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_pxl, &img->line_len,
			&img->endian);
	img->pixels = (t_pixel *)mlx_get_data_addr(img->img, &img->bit_pxl, &img->line_len,
			&img->endian);
	mlx_draw(i, j, img);
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void	mlx_pxl_pixel(t_image *img, int x, int y, t_pixel color)
{
	t_pixel	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = img->pixels + (y * WIDTH + x);
	*dst = color;
}

void	mlx_pxl(t_image *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bit_pxl / 8));
	*(unsigned int *)dst = color;
}

void	mlx_draw(int i, int j, t_image *img)
{
	int	color1;
	int	color2;

	color1 = 0x77B5FE;
	color2 = 0x3A9D23;
	if (DD_MOD)
	{
		color1 = 0;
		color2 = 0;
	}
	while (i <= WIDTH)
	{
		j = 0;
		while (j <= HEIGHT)
		{
			if (j <= HEIGHT / 2)
				mlx_pxl(img, i, j, color1);
			else
				mlx_pxl(img, i, j, color2);
			j++;
		}
		i++;
	}
}
