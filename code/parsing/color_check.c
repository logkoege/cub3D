/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:52:46 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/14 17:34:01 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int ft_strcmp_clor(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if(s1[i] == s2[0])
			return (0);
		i++;
	}
	return (1);
}

int	find_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == c)
			break;
		i++;
	}
	return(i);

}

void	assign_colors(char **split)
{
	char *red;
	char *green;
	char *blue;

	red = split[0];
	green = split[1];
	blue = split[2];
	//freesplit

	
}

void	floor_color_arg(t_data *data, char *arg)
{
	int i;
	char *color;
	char **split_color;
	// int counter;

	// int max;
	// int j;
	// j = 0;

	i = 0;
	while(ft_isdigit(arg[i]) == 0)
		i++;
	color = ft_sub(arg, i, ft_strlen(arg));
	if(!color)
		free_exit(data, "malloc error");
	split_color = ft_spliter(color, ',');
	if(!split_color)
		free_exit(data, "malloc error");
	while(split_color[i])
		i++;
	if(i != 3)
		free_exit(data, "Error : color : too much arguments");
	
	// red = ft_dup(split_color[j]);

}

void color_check(t_data *data)
{
	int i;
	
	i = 0;
	while (data->map[i])
	{
		if(ft_strcmp_clor(data->map[i], "F") == 0)
			floor_color_arg(data, data->map[i]);
		i++;
	}
	
}