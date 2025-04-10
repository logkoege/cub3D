/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/11 00:15:54 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_var(t_data *data, t_image *img)
{
	data->mlx = NULL;
	data->win = NULL;
	img->img = NULL;
	data->right = 0;
	data->left = 0;
	data->front = 0;
	data->back = 0;
}

void	ft_freexit(t_data *data, char *msg)
{
	(void)data;
	printf("%s", msg);
	printf("W -> %d\n", data->front);
	printf("A -> %d\n", data->left);
	printf("S -> %d\n", data->back);
	printf("D -> %d\n", data->right);
	exit(0);
}

int	ft_close(t_data *data)
{
	ft_freexit(data, "");
	return (0);
}
