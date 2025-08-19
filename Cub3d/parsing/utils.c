/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/19 20:45:50 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_var(t_data *data)
{
	data->map = NULL;
	data->file_east = NULL;
	data->file_north = NULL;
	data->file_south = NULL;
	data->file_west = NULL;
	data->truemap = NULL;
	data->true_map_len = 0;
	data->line_len = 0;
	data->south_fd = 0;
	data->east_fd = 0;
	data->north_fd = 0;
	data->west_fd = 0;
}

char	*ft_dup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1 && s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_strcmp_pos(char *s1, char *s2)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	i++;
	if (!s1 || !s2)
		return (1);
	while (s1[j])
	{
		if (s1[j] == s2[0] && s1[j + 1] == s2[1])
			return (0);
		j++;
	}
	return (1);
}

char	*ret_sub(char *str, int j)
{
	j--;
	str[j] = '\0';
	return (str);
}

char	*ft_sub(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;
	int		lev;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || start == 0)
		return (ft_dup(""));
	lev = len - start;
	str = malloc(sizeof(char) * (lev + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < lev)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	return (ret_sub(str, j));
}
