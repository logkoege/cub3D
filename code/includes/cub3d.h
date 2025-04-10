/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:21:02 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/11 00:14:45 by logkoege         ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

# define FLOOR			'0'
# define WALL			'1'
# define ITEM			'2'
# define NORTH_CAMERA	'N'
# define EAST_CAMERA	'E'
# define WEST_CAMERA	'W'
# define SOUTH_CAMERA	'S'
# define EASTER_EGG		'G'

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100

# define WIDTH		960
# define HEIGHT		540

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		front;
	int		back;
	int		left;
	int		right;
}	t_data;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bit_pxl;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	cam_plane_x;
	double	cam_plane_y;
	double	oldtime;
	double	time;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
}	t_player;

///////////////////////////////////__EXEC__////////////////////////////////////

// mlx_util.c

void	init_mlx(t_data *data, t_image *image);
void	mlx_pxl(t_image *img, int x, int y, int color);

// utils.c
void	init_var(t_data *data, t_image *image);
void	ft_freexit(t_data *data, char *msg);
int		ft_close(t_data *data);
int		player_intructs(int keycode, t_data *data);

///////////////////////////////////_PARSING_///////////////////////////////////

#endif