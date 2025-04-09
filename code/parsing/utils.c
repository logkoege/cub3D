/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/09 15:28:43 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_var(t_data *data)
{
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
}
void	ft_freexit(t_data *data, char *msg)
{
	(void)data;
	printf("%s\n", msg);
	exit(1);
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
	return (0);
}