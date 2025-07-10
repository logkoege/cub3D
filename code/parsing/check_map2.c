/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 06:56:19 by lloginov          #+#    #+#             */
/*   Updated: 2025/07/10 17:54:52 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_side(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j] == ' ' || data->map2[i][j] == '\t')
			j++;
		if (data->map2[i][j] != '1')
			free_map_exit(data, "Error : walls error");
		j = ft_strlen(data->map2[i]) - 1;
		while (j > 0 && (data->map2[i][j] == ' ' || data->map2[i][j] == '\t'
				|| data->map2[i][j] == '\n'))
			j--;
		if (data->map2[i][j] != '1')
			free_map_exit(data, "Error : walls error");
		i++;
	}
}

void	check_map_char(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2[i])
	{
		j = 0;
		while (data->map2[i][j])
		{
			if (is_map_char(data, i, j) == 1)
				free_map_exit(data, "Error : wrong char in map");
			j++;
		}
		i++;
	}
	check_player_count(data);
	check_walls(data);
	check_side(data);
}

void	get_len_max(t_data *data)
{
	int	i;

	i = 0;
	data->line_len = ft_strlen(data->map2[i]);
	while (data->map2[i])
	{
		if (data->line_len < ft_strlen(data->map2[i]))
			data->line_len = ft_strlen(data->map2[i]);
		i++;
	}
}

void	set_to_one(t_data *data, int i)
{
	int		j;
	char	*tmp;

	while (data->map2[++i])
	{
		tmp = malloc(sizeof(char) * (data->line_len + 2));
		if (!tmp)
			free_map_exit(data, "malloc error");
		j = -1;
		while (++j < ft_strlen(data->map2[i]) - 1)
		{
			if (is_replace_char(data, i, j))
				tmp[j] = '0';
			else
				tmp[j] = data->map2[i][j];
		}
		while (j < data->line_len)
			tmp[j++] = '0';
		tmp[j++] = '\n';
		tmp[j] = '\0';
		free(data->map2[i]);
		data->map2[i] = ft_dup(tmp);
		free(tmp);
	}
}

void	map_alloc(t_data *data)
{
	int	i;
	int	f;

	f = -1;
	i = 0;
	while (i != data->true_map_len)
	{
		data->map2[i] = ft_dup(data->truemap[i]);
		i++;
	}
	data->map2[i] = NULL;
	get_len_max(data);
	check_map_char(data);
	set_to_one(data, f);
	floodfill(data);
}
