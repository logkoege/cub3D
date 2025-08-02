/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 00:07:49 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/02 14:40:25 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (i <= 10)
	{
		mlx_pxl(data->img, x + i, y, 0xFFFFFF);
		i++;
	}
	i = 0;
	while (i <= 10)
	{
		mlx_pxl(data->img, x, y + i, 0xFFFFFF);
		i++;
	}
	i = 0;
	while (i <= 10)
	{
		mlx_pxl(data->img, x + 10, y + i, 0xFFFFFF);
		i++;
	}
	i = -1;
	while (++i <= 10)
	{
		mlx_pxl(data->img, x + i, y + 10, 0xFFFFFF);
	}
}

void	draw_player2(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (i <= S_SQUARE)
	{
		mlx_pxl(data->img, x + i, y, 0x00FF00);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE)
	{
		mlx_pxl(data->img, x, y + i, 0x00FF00);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE)
	{
		mlx_pxl(data->img, x + S_SQUARE, y + i, 0x00FF00);
		i++;
	}
	i = -1;
	while (++i <= S_SQUARE)
	{
		mlx_pxl(data->img, x + i, y + S_SQUARE, 0x00FF00);
	}
}

void	draw_player3(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (i <= S_SQUARE / 4)
	{
		mlx_pxl(data->img, x + i, y, 0x00FF00);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE / 4)
	{
		mlx_pxl(data->img, x, y + i, 0x00FF00);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE / 4)
	{
		mlx_pxl(data->img, x + S_SQUARE / 4, y + i, 0x00FF00);
		i++;
	}
	i = -1;
	while (++i <= S_SQUARE / 4)
	{
		mlx_pxl(data->img, x + i, y + S_SQUARE / 4, 0x00FF00);
	}
}

void	draw_player4(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (i <= S_SQUARE / 8)
	{
		mlx_pxl(data->img, x + i, y, 0xFF0000);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE / 8)
	{
		mlx_pxl(data->img, x, y + i, 0xFF0000);
		i++;
	}
	i = 0;
	while (i <= S_SQUARE / 8)
	{
		mlx_pxl(data->img, x + S_SQUARE / 8, y + i, 0xFF0000);
		i++;
	}
	i = -1;
	while (++i <= S_SQUARE / 8)
	{
		mlx_pxl(data->img, x + i, y + S_SQUARE / 8, 0xFF0000);
	}
}
