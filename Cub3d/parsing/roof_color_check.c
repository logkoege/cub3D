/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roof_color_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:40:57 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/17 17:55:21 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	assign_colors2(t_data *data, char **split)
{
	char	*red;
	char	*green;
	char	*blue;
	int		hex;

	red = ft_dup(split[0]);
	green = ft_dup(split[1]);
	blue = ft_dup(split[2]);
	free_tab(split);
	check_is_num(data, red, green, blue);
	hex = rgb_to_hex(check_red(data, red), check_green(data, green), check_blue(data, blue));
	data->roof_color = hex;
}

void	roof_color_arg(t_data *data, char *arg)
{
	int		i;
	char	*color;
	char	**split_color;

	i = 0;
	while (arg[i] && ft_isdigit(arg[i]) == 0)
		i++;
	if (i == ft_strlen(arg))
		free_exit(data, "Error : roof color empty");
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
	assign_colors2(data, split_color);
}
