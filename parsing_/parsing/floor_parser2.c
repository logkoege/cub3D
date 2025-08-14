/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 06:55:00 by lloginov          #+#    #+#             */
/*   Updated: 2025/07/10 14:35:56 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_is_num(t_data *data, char *red, char *green, char *blue)
{
	int	i;

	i = 0;
	while (red[i])
	{
		if (ft_isdigit(red[i]) == 0)
			free_rgb(data, red, green, blue);
		i++;
	}
	i = 0;
	while (green[i])
	{
		if (ft_isdigit(green[i]) == 0)
			free_rgb(data, red, green, blue);
		i++;
	}
	i = 0;
	while (blue[i])
	{
		if (ft_isdigit(blue[i]) == 0)
			free_rgb(data, red, green, blue);
		i++;
	}
}

void	assign_colors(t_data *data, char **split)
{
	char	*red;
	char	*green;
	char	*blue;
	int		hex;

	red = ft_dup(split[0]);
	green = ft_dup(split[1]);
	blue = ft_dup(split[2]);
	check_is_num(data, red, green, blue);
	free_tab(split);
	hex = rgb_to_hex(check_red(data, red),
			check_green(data, green), check_blue(data, blue));
	data->floor_color = hex;
}

void	free_colors(t_data *data, char **color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		free(color[i]);
		i++;
	}
	free(color);
	free_exit(data, "Error : color : wrong number of arguments");
}

void	floor_color_arg(t_data *data, char *arg)
{
	int		i;
	char	*color;
	char	**split_color;

	i = 0;
	while (arg[i] && ft_isdigit(arg[i]) == 0)
		i++;
	if (i == ft_strlen(arg))
		free_exit(data, "Error : floor color empty");
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
	i = 0;
	while (split_color[i])
		i++;
	if (i != 3)
		free_colors(data, split_color);
	assign_colors(data, split_color);
}
