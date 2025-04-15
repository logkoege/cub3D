/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:21:02 by logkoege          #+#    #+#             */
/*   Updated: 2025/04/15 19:21:30 by logkoege         ###   ########.fr       */
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
# define G			103

# define PI			3.14159265359
# define SQUARE		70

# define RIGHT		65363
# define LEFT		65361

# define WIDTH		1280
# define HEIGHT		720

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
	struct s_image *img;
}	t_player;
typedef struct s_data
{
	void	*mlx;
	void	*win;
	int frame;
	bool	front;
	bool	back;
	bool	left;
	bool	right;
	char	**map;
	struct s_image *img;
	struct s_player *player;
}	t_data;



///////////////////////////////////__EXEC__////////////////////////////////////

// mlx_util.c
void	init_mlx(t_data *data, t_image *image);
void	mlx_pxl(t_image *img, int x, int y, int color);
void	mlx_draw(int i, int j, t_image *img);

// utils.c
void	init_player(t_player *player);
void	init_var(t_data *data, t_image *image, t_player *player);
void	ft_freexit(t_data *data, char *msg);
int		ft_close(t_data *data);

// move.c
void	player_intructs(t_data *data, t_player *player);
void	easter_egg(void);

void	twod_map(t_data *data);
void	draw_player(int x, int y, int p_size, int color, t_data *data);
int		draw_player_loop(t_data *data);

// utils2.c
int		press(int keycode, t_data *data);
int		release(int keycode, t_data *data);

// draw.c
int		draw_player_loop(t_data *data);
void	clear_img(t_data *data);
void	map(t_data *data);
void	draw_map(t_data *data);

///////////////////////////////////_PARSING_///////////////////////////////////

#endif