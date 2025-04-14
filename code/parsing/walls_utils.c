/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:59:44 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/14 15:01:50 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_arg(char *arg, char f, char s)
{
	int i;
	i = 0;
	if(!arg)
		return(0);
	while(arg[i])	
	{
		if(arg[i] == f && arg[i + 1] == s)
		{
			i += 2;
			while ((arg[i] >= 9 && arg[i] <= 13) || arg[i] == ' ')
			{
				i++;
			}
			return(i);
		}
		i++;
	}
	return(i);
}
int	check_ws(char *arg, int i)
{
	while(arg[i])
	{
		if(ft_is_ws(arg[i]) == 1)
			return(i);
		i++;
	}
	printf("noreturn\n");
	return(i);
}