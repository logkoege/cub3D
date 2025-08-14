/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:44:20 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/11 16:26:03 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_exit(char *str)
{
	if (str)
		printf("%s\n", str);
	exit(1);
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

void	check_ext(t_data *data, char *file, char *msg)
{
	int	i;

	i = ft_strlen(file);
	if (i < 4)
		free_exit(data, msg);
	if (file[i - 1] != 'm' || file[i - 2] != 'p'
		|| file[i - 3] != 'x' || file[i - 4] != '.')
		free_exit(data, msg);
}

void	check_xpm(t_data *data)
{
	check_ext(data, data->file_north,
		"Error: north file not ending in .xpm");
	check_ext(data, data->file_south,
		"Error: south file not ending in .xpm");
	check_ext(data, data->file_west,
		"Error: west file not ending in .xpm");
	check_ext(data, data->file_east,
		"Error: east file not ending in .xpm");
}
