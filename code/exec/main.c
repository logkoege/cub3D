/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/29 21:23:27 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;
	t_image		img;
	t_tex		tex;

	data.tex = &tex;
	(void)argv;
	(void)argc;
	map(&data);
	init_var(&data, &img, &player);
	init_mlx(&data, &img);
	data.img = &img;
	data.player = &player;
	load_textures(&tex, &data);
	mlx_hook(data.win, 2, 1L << 0, press, &data);
	mlx_hook(data.win, 3, 1L << 1, release, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop_hook(data.mlx, draw_player_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
