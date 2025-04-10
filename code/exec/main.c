/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/10 23:08:12 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_image	img;

	(void)argv;
	(void)argc;
	init_var(&data, &img);
	init_mlx(&data, &img);
	mlx_hook(data.win, 2, 1L << 0, player_intructs, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop(data.mlx);
	return (0);
}
