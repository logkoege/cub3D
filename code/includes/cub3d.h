/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:21:02 by logkoege          #+#    #+#             */
/*   Updated: 2025/07/15 18:49:11 by logkoege         ###   ########.fr       */
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

# define ESC		65307
# define W			119
# define A			97
# define S			115
# define D			100
# define G			103

# define NORTH		0
# define SOUTH		1
# define WEST 		2
# define EAST 		3

# define PI			3.14159265359
# define S_SQUARE	64

# define RIGHT		65363
# define LEFT		65361

# define WIDTH		1280
# define HEIGHT		720
# define DD_MOD		1

typedef struct s_tex
{
	void			*textures[4];
	int				tex_height;
	int				tex_width;
	void			*img;
	char			*addr[4];
	int				bpp;
	int				line_len;
	int				endian;
	int				y;
	int				tex_x;
	int				tex_y;
	int				color;
	double			step;
	double			tex_pos;
	int				wall_height;
}	t_tex;

typedef struct s_image
{
	void			*img;
	char			*addr;
	int				bit_pxl;
	int				line_len;
	int				endian;
}	t_image;

typedef struct s_player
{
	double			angle;
	double			pos_x;
	double			pos_y;
	double			cos_angle;
	double			sin_angle;
	double			angle_speed;
	int				speed;
	struct s_image	*img;
}	t_player;
typedef struct s_data
{
	int				minimap_w;
	int				minimap_h;
	int				start_y;
	int				end;
	double			distance;
	void			*mlx;
	void			*win;
	int				frame;
	bool			front;
	bool			back;
	bool			left;
	bool			right;
	bool			camera_left;
	bool			camera_right;
	char			**mapo;
	int				side;
	double			ray_dir_x;
	double			ray_dir_y;
	double			wall_x;
	double			wall_y;
	int				wall_dir;
	struct s_image	*img;
	struct s_player	*player;
	struct s_tex	*tex;
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
void	player_camera(t_data *data, t_player *player);
void	player_camera_2(t_data *data, t_player *player);

void	draw_player(int x, int y, t_data *data);
void	draw_player2(int x, int y, t_data *data);
void	draw_player3(int x, int y, t_data *data);
void	draw_player4(int x, int y, t_data *data);
int		draw_player_loop(t_data *data);

// utils2.c
int		press(int keycode, t_data *data);
int		release(int keycode, t_data *data);

// draw.c
int		draw_player_loop(t_data *data);
void	clear_img(t_data *data);
void	map(t_data *data);
void	draw_map(t_data *data);

// ray.c
bool	line_to_wall(double px, double py, t_data *data);
double	sqr(double a);
double	squirt(double x, double y, double x1, double x2);
void	ray(t_data *data, int i, int size);

// minimap.c
void	draw_ray(t_data *data, double start_x, int i);
void	draw_minimap(t_data *data);
void	draw_minimap_end(t_data *data, int x, int y);

// texture.c
int		get_wall_dir(double ray_dir_x, double ray_dir_y);
void	load_textures(t_tex *tex, t_data *data);

void	draw_textured_wall(t_data *d, int x, int wall_h);
void	draw_texture_column(t_data *data, int x, int start_y, int end_y, int wall_dir);
int		get_tex_color(t_tex *tex, int dir, int x, int y);

///////////////////////////////////_PARSING_///////////////////////////////////

#endif