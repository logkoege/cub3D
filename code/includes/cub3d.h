/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloginov <lloginov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:21:02 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/14 17:01:21 by lloginov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
// # include "../../mlx_here/minilibx-linux/mlx.h"

# define FLOOR			'0'
# define WALL			'1'
# define ITEM			'2'
# define NORTH_CAMERA	'N'
# define EAST_CAMERA	'E'
# define WEST_CAMERA	'W'
# define SOUTH_CAMERA	'S'




# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_data
{
	char 	**map;
	int		floor_color;
	int		roof_color;
	char 	*file_north;
	char 	*file_south;
	char 	*file_east;
	char 	*file_west;
	int		file_size;
}	t_data;

typedef struct s_img
{
	
}	t_img;

//parsing

void	map_name(char *map);
int		parsing(t_data *data, int ac, char **av);


//utils
void	init_var(t_data *data);
void	print_exit(char *str);
int		ft_strlen(char *str);
char	*ft_dup(char *s1);
int		ft_strcmp_pos(char *s1, char *s2);
char	*ft_sub(char *s, int start, int len);
void	free_all(t_data *data);
void	free_exit(t_data *data, char *str);
int		ft_is_ws(int i);
char	**ft_spliter(char *s, char c);

//wals_utils
int	check_arg(char *arg, char f, char s);
int	check_ws(char *arg, int i);

//check_file
void	wall_files_check(t_data *data);

//color check
void color_check(t_data *data);

//gnl
char	*get_next_line(int fd);
void	ft_bzero(void *s, size_t n);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strncpy(char *s1, char *s2, char c);
char	*ft_strcpy(char *a, char *b);
char	*ft_strchr(const char *s, int c);
char	*ft_split(char *src, char car);
char	*ft_ligne(int fd, char *ligne, char *buffer);

#endif