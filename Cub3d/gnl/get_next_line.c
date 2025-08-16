/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:46:18 by lloginov          #+#    #+#             */
/*   Updated: 2025/04/09 14:38:30 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	char	*i;

	i = (char *)s;
	while (n)
	{
		*i = 0;
		i++;
		n--;
	}
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	*ft_ligne(int fd, char *ligne, char *buffer)
{
	int	i;

	while (!ft_strchr(ligne, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		if (i == 0)
			break ;
		if (i < 0)
		{
			free(ligne);
			return (NULL);
		}
		ligne = ft_strjoin(ligne, buffer);
		if (!ligne)
		{
			free(ligne);
			return (NULL);
		}
	}
	return (ligne);
}

char	*get_next_line(int fd)
{
	char			*ligne;
	char			buffer[BUFFER_SIZE + 1];
	static char		gnl[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ligne = ft_strdup(gnl);
	ft_bzero(gnl, BUFFER_SIZE + 1);
	ligne = ft_ligne(fd, ligne, buffer);
	if (ligne == NULL)
	{
		free (ligne);
		return (NULL);
	}
	ft_strncpy(gnl, ligne, '\n');
	ligne = ft_split(ligne, '\n');
	if (ft_strlen(ligne) == 0)
	{
		free(ligne);
		return (NULL);
	}
	return (ligne);
}
