/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:52:46 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/15 18:31:09 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


void color_check(t_data *data)
{
	int i;
	int cmpt;

	i = 0;
	cmpt = 0;
	while (data->map[i])
	{
		if (ft_strcmp_clor(data->map[i], "F") == 0)
		{
			cmpt++;
			floor_color_arg(data, data->map[i]);
		}
		else if (ft_strcmp_clor(data->map[i], "C") == 0)
		{
			cmpt++;
			roof_color_arg(data, data->map[i]);
		}
		i++;
	}
	if(cmpt > 2)
		free_exit(data, "Error : too much colors");
	else if(cmpt < 2)
		free_exit(data, "Error : too much colors");
}
