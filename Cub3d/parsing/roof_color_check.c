/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roof_color_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:40:57 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/19 20:45:04 by logkoege         ###   ########.fr       */
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
	if (check_is_num(data, red, green, blue) == -1)
	{
		free_tab(split);
		free_rgb(data, red, green, blue);
	}
	free_tab(split);
	data->r2 = check_red(data, red);
	data->g2 = check_green(data, green);
	data->b2 = check_blue(data, blue);
	if (data->r2 == -1 || data->g2 == -1 || data->b2 == -1)
		free_rgb(data, red, green, blue);
	free(red);
	free(green);
	free(blue);
	printf("r%d\ng%d\nb%d\n", data->r2, data->g2, data->b2);
	hex = rgb_to_hex(data->r2, data->g2, data->b2);
	data->floor_color = hex;
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
