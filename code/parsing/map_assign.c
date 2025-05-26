/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 18:16:22 by lloginov          #+#    #+#             */
/*   Updated: 2025/05/22 09:15:22 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_color(t_data *data, int i)
{
	if (ft_strcmp_clor(data->map[i], "F") == 0)
		return (1);
	else if (ft_strcmp_clor(data->map[i], "C") == 0)
		return (1);
	return (0);
}

int	is_file(t_data *data, int i)
{
	if (ft_strcmp_pos(data->map[i], "SO") == 0)
		return (1);
	else if (ft_strcmp_pos(data->map[i], "NO") == 0)
		return (1);
	else if (ft_strcmp_pos(data->map[i], "WE") == 0)
		return (1);
	else if (ft_strcmp_pos(data->map[i], "EA") == 0)
		return (1);
	return (0);
}

void	true_map_dup(t_data *data, int i)
{
	int	j;
	int	k;

	j = 0;
	k = i;
	while (data->map[i])
		i++;
	data->truemap = malloc(sizeof(char *) * (i - k + 1));
	if (!data->truemap)
		free_exit(data, "Error : malloc error in assign map");
	while (k < i)
	{
		data->truemap[j] = data->map[k];
		if (!data->truemap[j])
			free_exit(data, "Error : Malloc error");
		j++;
		k++;
	}
	data->map2 = malloc(sizeof(char *) * (j + 1));
	if(!data->map2)
		print_exit("Error : malloc map2 error");
	data->truemap[j] = NULL;
	data->true_map_len = j;
	map_alloc(data);
}

int	is_map_char(t_data *data, int i, int j)
{
	if (data->truemap[i][j] != '1' && data->truemap[i][j] != '0'
		&& data->truemap[i][j] != 'N' && data->truemap[i][j] != 'S'
			&& data->truemap[i][j] != 'W' && data->truemap[i][j] != 'E'
				&& data->truemap[i][j] != '\n' && data->truemap[i][j] != ' ' &&  data->truemap[i][j] != '	')
		return (1);
	return (0);
}
void	assign_map(t_data *data)
{
	int i;

	i = 0;
	while(data->map[i])
	{
		if(is_file(data, i) == 1 || is_color(data, i) == 1)
			i++;
		else if(ft_strcmp_clor(data->map[i], "0") == 1 && ft_strcmp_clor(data->map[i], "1") == 1)
			i++;
		else
			break ;
	}
	true_map_dup(data, i);
}
