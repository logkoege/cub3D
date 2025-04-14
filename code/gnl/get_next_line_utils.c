/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:46:28 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/09 14:41:10 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


char	*ft_split(char *src, char car)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (ft_strchr(src, car) == NULL)
		return (src);
	while (src[j] != car && src[j] != '\0')
		j++;
	str = malloc(sizeof(char) * (j + 2));
	if (!str)
		return (NULL);
	while (i < j + 1)
	{
		str[i] = src[i];
		i++;
	}
	free(src);
	str[i] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

char	*ft_strcpy(char *a, char *b)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (a[i] != '\0')
		i++;
	while (a[i] && b[j])
	{
		a[i] = b[j];
		i++;
	}
	return (a);
}

char	*ft_strncpy(char *s1, char *s2, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s2[i] && s2[i] != c)
	{
		i++;
	}
	if (ft_strlen(s2) == i)
		return (NULL);
	i++;
	while (s2[i])
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
