/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:28:26 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 14:57:19 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_exit(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	if(!str)
		return(0);
	while(str[i])
		i++;
	return(i);
}

void	init_var(t_data *data)
{
	data->map = NULL;
	data->file_east = NULL;
	data->file_north = NULL;
	data->file_south = NULL;
	data->file_west = NULL;
	return ;
}

char	*ft_dup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	if(!s1)
		return(NULL);
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
	int i;
	int j;

	j = 0;
	i = 0;
	i++;
	if(!s1 || !s2)
		return(1);
	while(s1[j])
	{
		if(s1[j] == s2[0] && s1[j + 1] == s2[1])
			return(0);
		j++;
	}
	return(1);
}

char	*ft_sub(char *s, int start, int len)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start || start == 0)
		return (ft_dup(""));
	int lev;
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
	j--;
	str[j] = '\0';
	return (str);
}

void	free_all(t_data *data)
{
	int i;

	i = 0;

	while(data->map[i])
	{
		if(data->map[i])
			free(data->map[i]);
		i++;
	}
	free(data->map);
	if(data->file_north)
		free(data->file_north);
	if(data->file_east)
		free(data->file_east);
	if(data->file_south)
		free(data->file_south);
	if(data->file_west)
		free(data->file_west);
}

void	free_exit(t_data *data, char *str)
{
	free_all(data);
	print_exit(str);
}


int	ft_is_ws(int i)
{
	if ((i >= 9 && i <= 13) || i == ' ')
		return (1);
	return (0);
}
