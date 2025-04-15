/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:47:20 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/15 17:53:10 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
}

int check_red(t_data *data, char *red)
{
	int redd;

	redd = ft_atoi(red);
	if (redd < 0 || redd > 255)
	{
		free_exit(data, "Error : floor red color");
		free(red);
	}
	free(red);
	return(redd);
}

int check_green(t_data *data, char *green)
{
	int greenn;

	greenn = ft_atoi(green);
	if (greenn < 0 || greenn > 255)
	{
		free_exit(data, "Error : floor green color");
		free(green);
	}
	free(green);
	return (greenn);
}

int check_blue(t_data *data, char *blue)
{
	int bluee;

	bluee = ft_atoi(blue);
	if (bluee < 0 || bluee > 255)
	{
		free(blue);
		free_exit(data, "Error : floor blue color");
	}
	free(blue);
	return (bluee);
}

void assign_colors(t_data *data, char **split)
{
	char *red;
	char *green;
	char *blue;
	int hex;

	red = ft_dup(split[0]);
	green = ft_dup(split[1]);
	blue = ft_dup(split[2]);
	free_tab(split);
	hex = rgb_to_hex(check_red(data, red), check_green(data, green), check_blue(data, blue));
	data->floor_color = hex;
}

void floor_color_arg(t_data *data, char *arg)
{
	int i;
	char *color;
	char **split_color;

	i = 0;
	while (ft_isdigit(arg[i]) == 0)
		i++;
	color = ft_sub(arg, i, ft_strlen(arg));
	if (!color)
		free_exit(data, "malloc error");
	split_color = ft_spliter(color, ',');
	if (!split_color)
	{
		free(color);
		free_exit(data, "malloc error");
	}
	free(color);
	while (split_color[i])
		i++;
	if (i != 3)
		free_exit(data, "Error : color : too much arguments");
	assign_colors(data, split_color);
}
