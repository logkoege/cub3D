/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:19:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/05/22 09:14:17 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(char **map)
{
	int i = 0;

	while(map[i])
	{
		printf("%s", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		return (1);
	init_var(&data);
	parsing(&data, argc, argv);
	// free_all(&data);
	free_map_exit(&data, NULL);
	return (0);
}
