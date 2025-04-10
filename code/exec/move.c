/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 23:50:43 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/11 00:15:27 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	player_intructs(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_freexit(data, "");
	else if (keycode == W)
		data->front++;
	else if (keycode == A)
		data->left++;
	else if (keycode == S)
		data->back++;
	else if (keycode == D)
		data->right++;
	return (0);
}
