/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:28 by lloginov          #+#    #+#             */
/*   Updated: 2025/05/26 15:49:56 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_map_char(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(data->map2[i])
	{
		j = 0;
		while(data->map2[i][j])
		{
			if(is_map_char(data, i, j) == 1)
			{
				printf("at : %s\n", data->map2[i]);
				free_map_exit(data, "Error : wrong char in map");
			}
			j++;
		}
		i++;
	}
}

void	get_len_max(t_data *data)
{
	int i;

	i = 0;
	data->map_len = ft_strlen(data->map2[i]);
	while(data->map2[i])
	{
		if(data->map_len < ft_strlen(data->map2[i]))
			data->map_len = ft_strlen(data->map2[i]);
		i++;
	}
}

int	is_replace_char(t_data *data, int i, int j)
{
	if(data->map2[i][j] != '1' && data->map2[i][j] != '0' && data->map2[i][j]
			!= '\0' && data->map2[i][j] != '\n' && data->map[i][j] != 'N' &&
				data->map[i][j] != 'S' && data->map[i][j] != 'E' &&
					data->map[i][j] != 'W')
						return (1);
	return (0);
}

void	set_to_one(t_data *data)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	printf("data->map : %d\n\n", data->map_len);

	while(data->map2[i])
	{
		tmp = malloc(sizeof (char) * (data->map_len + 1));
		if(!tmp)
			free_map_exit(data, "malloc error");
		j = 0;
		while(data->map2[i][j])
		{
			if(is_replace_char(data, i, j) == 1)
			{
				tmp[j] = '1';
			}
			else
				tmp[j] = data->map2[i][j];
			j++;
		}0
		free(data->map2[i]);
		data->map2[i] = ft_dup(tmp);
		free(tmp);
		i++;
	}
}

void	map_alloc(t_data *data)
{
	int i;

	i = 0;
	while(i != data->true_map_len)
	{
		data->map2[i] = ft_dup(data->truemap[i]);
		i++;
	}
	data->map2[i] = NULL;
	get_len_max(data);
	check_map_char(data);
	set_to_one(data);
	// print_map(data->map2);
}
