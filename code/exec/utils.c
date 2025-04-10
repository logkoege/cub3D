/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/10 14:32:17 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_var(t_data *data, t_image *img)
{
	data->mlx = NULL;
	data->win = NULL;
	img->img = NULL;
}
void	ft_freexit(t_data *data, char *msg)
{
	(void)data;
	printf("%s\n", msg);
	exit(0);
}

int	ft_close(t_data *data)
{
	ft_freexit(data, "x\n");
	return (0);
}

int	player_intructs(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_freexit(data, "Esc\n");
//	if (keycode == W)
//	if (keycode == A)
//	if (keycode == S)
//	if (keycode == D)
	return (0);
}