/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:47:20 by lloginov          #+#    #+#             */
/*   Updated: 2025/08/17 16:54:09 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF));
}

int	check_red(t_data *data, char *red)
{
	int	redd;

	redd = ft_atoi(red);
	if (redd < 0 || redd > 255)
	{
		free(red);
		free_exit(data, "Error : floor red color");
	}
	free(red);
	return (redd);
}

int	check_green(t_data *data, char *green)
{
	int	greenn;

	greenn = ft_atoi(green);
	if (greenn < 0 || greenn > 255)
	{
		free(green);
		free_exit(data, "Error : floor green color");
	}
	free(green);
	return (greenn);
}

int	check_blue(t_data *data, char *blue)
{
	int	bluee;

	bluee = ft_atoi(blue);
	if (bluee < 0 || bluee > 255)
	{
		free(blue);
		free_exit(data, "Error : floor blue color");
	}
	free(blue);
	return (bluee);
}

void	free_rgb(t_data *data, char *red, char *green, char *blue)
{
	free(red);
	free(green);
	free(blue);
	free_exit(data, "Error : colors should be written with numbers only");
}
