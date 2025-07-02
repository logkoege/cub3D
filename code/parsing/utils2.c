/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:42:52 by lloginov          #+#    #+#             */
/*   Updated: 2025/07/02 13:18:06 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	if (data->file_north)
		free(data->file_north);
	if (data->file_east)
		free(data->file_east);
	if (data->file_south)
		free(data->file_south);
	if (data->file_west)
		free(data->file_west);
}

void	free_exit(t_data *data, char *str)
{
	free_all(data);
	print_exit(str);
}

void	free_map_exit(t_data *data, char *str)
{
	int i;

	i = 0;
	while (i != data->true_map_len + 1)
	{
		free(data->map2[i]);
		i++;
	}
	free(data->map2);
	free(data->truemap);
	free_exit(data, str);
}

int	ft_is_ws(int i)
{
	if ((i >= 9 && i <= 13) || i == ' ')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - 48);
		i++;
	}
	return (number * sign);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
