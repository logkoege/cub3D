/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 09:14:28 by lloginov          #+#    #+#             */
/*   Updated: 2025/06/24 23:23:12 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_replace_char(t_data *data, int i, int j)
{
	if(data->map2[i][j] != '1' && data->map2[i][j] != '0' && data->map2[i][j]
			!= '\0' && data->map2[i][j] != '\n' && data->map2[i][j] != 'N' &&
				data->map2[i][j] != 'S' && data->map2[i][j] != 'E' &&
					data->map2[i][j] != 'W')
						return (1);
	return (0);
}

void	check_player_count(t_data *data)
{
	int i;
	int j;
	int cmpt;

	cmpt = 0;
	i = 0;
	j = 0;

	while(data->map2[i])
	{
		j = 0;
		while(data->map2[i][j])
		{
			if(data->map2[i][j] == 'N' || data->map2[i][j] == 'S' || data->map2[i][j] == 'E'
					|| data->map2[i][j] == 'W')
						cmpt++;
			j++;
		}
		i++;
	}
	if(cmpt != 1)
		free_map_exit(data, "Error : player error");
}
void	check_empty_line(t_data *data)
{
	int	i;
	int	j;
	int	has_content;

	i = 0;
	while (data->map2[i])
	{
		j = 0;
		has_content = 0;
		while (data->map2[i][j])
		{
			if (data->map2[i][j] == '1' || data->map2[i][j] == '0'
				|| data->map2[i][j] == 'N' || data->map2[i][j] == 'S'
				|| data->map2[i][j] == 'E' || data->map2[i][j] == 'W')
				has_content = 1;
			j++;
		}
		if (has_content == 0)
			free_map_exit(data, "Error : empty line in map");
		i++;
	}
}


void	check_walls(t_data *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	
	while(data->map2[0][j])
	{
		if(data->map2[0][j] != '1' && data->map2[0][j] != '\n')
			free_map_exit(data, "Error : fisrt line not surounded ");
		j++;
	}

	j = 0;
	while(data->map2[i])
		i++;
	i--;
	if(ft_strlen(data->map2[i]) == 1)
		free_map_exit(data, "Error : last line not surrounded");		
	while(data->map2[i][j])
	{
		if(data->map2[i][j] != '1' && data->map2[i][j] != '\n')
			free_map_exit(data, "Error : last line not surounded ");
		j++;
	}
}

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
			free_map_exit(data, "Erreur : walls error");
		j = ft_strlen(data->map2[i]) - 1;
		while (j > 0 && (data->map2[i][j] == ' ' || data->map2[i][j] == '\t'
				|| data->map2[i][j] == '\n'))
			j--;
		if (data->map2[i][j] != '1')
			free_map_exit(data, "Erreur : walls error");
		i++;
	}
}



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
	check_player_count(data);
	check_walls(data);
	check_side(data);

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



void	set_to_one(t_data *data)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	printf("data->map : %d\n\n", data->true_map_len);

	while (data->map2[i])
	{
		tmp = malloc(sizeof (char) * (data->map_len + 2));
		if(!tmp)
			free_map_exit(data, "malloc error");
		j = 0;
		while(j != ft_strlen(data->map2[i]) - 1)
		{
			if(is_replace_char(data, i, j) == 1)
			{
				tmp[j] = '1';
			}
			else
				tmp[j] = data->map2[i][j];
			j++;
		}
		while(j != data->map_len)
		{
			tmp[j] = '1';
			j++;
		}
		tmp[j++] = '\n';
		tmp[j] = '\0';
		// printf("map = %s\n", tmp);
		free(data->map2[i]);
		data->map2[i] = ft_dup(tmp);
		free(tmp);
		i++;
	}
	print_map(data->map2);
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
