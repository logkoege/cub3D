/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_parser2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 06:55:00 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/19 20:30:10 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_is_num(t_data *data, char *red, char *green, char *blue)
{
	int	i;

	i = 0;
	(void)data;
	while (red[i])
	{
		if (ft_isdigit(red[i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (green[i])
	{
		if (ft_isdigit(green[i]) == 0)
			return (-1);
		i++;
	}
	i = 0;
	while (blue[i])
	{
		if (ft_isdigit(blue[i]) == 0)
			return (-1);
		i++;
	}
	return (0);
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
	if (check_is_num(data, red, green, blue) == -1)
	{
		free_tab(split);
		free_rgb(data, red, green, blue);
	}
	free_tab(split);
	data->r = check_red(data, red);
	data->g = check_green(data, green);
	data->b = check_blue(data, blue);
	if (data->r == -1 || data->g == -1 || data->b == -1)
		free_rgb(data, red, green, blue);
	free(red);
	free(green);
	free(blue);
	hex = rgb_to_hex(data->r, data->g, data->b);
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
