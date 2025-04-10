/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:09:45 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/11 00:05:15 by logkoege         ###   ########.fr       */
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
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "LevPD");
	if (!data->win)
		ft_freexit(data, "Error : window initialisation");
	img->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bit_pxl, &img->line_len,
			&img->endian);
	while (i * 2 <= WIDTH)
	{
		j = 0;
		while (j <= HEIGHT)
		{
			mlx_pxl(img, i, j, 0x00000FF);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img->img, 0, 0);
}

void	mlx_pxl(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bit_pxl / 8));
	*(unsigned int *)dst = color;
}
