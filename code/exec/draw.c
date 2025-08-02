/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: logkoege <logkoege@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:33:36 by logkoege          #+#    #+#             */
/*   Updated: 2025/08/02 15:55:27 by logkoege         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	draw_player_loop(t_data *data)
// {
// 	double	fraction;
// 	double	start_x;
// 	int		i;

// 	i = 0;
// 	fraction = PI / 3 / WIDTH;
// 	start_x = data->player->angle - PI / 6;
// 	player_intructs(data, data->player);
// 	mlx_draw(0, 0, data->img);
// 	if (DD_MOD)
// 	{
// 		draw_player(data->player->pos_x, data->player->pos_y, data);
// 		draw_map(data);
// 	}
// 	while (i < WIDTH)
// 	{
// 		draw_ray(data, start_x, i);
// 		i++;
// 		start_x += fraction;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
// 	return (0);
// }

//bon
// int	draw_player_loop(t_data *data)
// {
// 	int		x;
// 	double	camera_x;
// 	double	ray_dir_x;
// 	double	ray_dir_y;
// 	double	half_fov = PI / 6.0; // fov/2 == PI/6

// 	player_intructs(data, data->player);
// 	mlx_draw(0, 0, data->img);
// 	if (DD_MOD)
// 	{
// 		draw_player(data->player->pos_x, data->player->pos_y, data);
// 		draw_map(data);
// 	}

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		// formule avec plan de caméra : camera_x de -1 à 1
// 		camera_x = 2.0 * x / (double)WIDTH - 1.0;
// 		// direction du rayon : dir + plane * camera_x
// 		ray_dir_x = data->player->cos_angle + (-data->player->sin_angle) * tan(half_fov) * camera_x;
// 		ray_dir_y = data->player->sin_angle + ( data->player->cos_angle) * tan(half_fov) * camera_x;

// 		// on appelle une variante de draw_ray qui prend directement dir
// 		draw_ray(data, ray_dir_x, ray_dir_y, x);
// 		x++;
// 	}
// 	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
// 	return (0);
// }


void	clear_img(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_pxl(data->img, i, j, 0);
			j++;
		}
		i++;
	}
}

void	map(t_data *data)
{
	int		i;
	char	**map1;

	i = 0;
	map1 = malloc(sizeof(char *) * 11);
	map1[0] = "111111111111111";
	map1[1] = "101000000000001";
	map1[2] = "100000001111111";
	map1[3] = "100000000000001";
	map1[4] = "100001000000001";
	map1[5] = "100000010000001";
	map1[6] = "100000000100001";
	map1[7] = "111000011110001";
	map1[8] = "100000000100001";
	map1[9] = "111111111111111";
	map1[10] = NULL;
	data->mapo = map1;
	data->map_pos_x = 6;
	data->map_pos_y = 6;
	while (data->mapo[i])
	{
		printf("map[%d] = %s\n", i, map1[i]);
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->mapo[i])
	{
		j = 0;
		while (data->mapo[i][j])
		{
			if (data->mapo[i][j] == '1')
				draw_player2(j * S_SQUARE, i
					* S_SQUARE, data);
			j++;
		}
		i++;
	}
}

// void	draw_ray(t_data *data, double start_x, int i)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	cos2;
// 	double	sin2;
// 	double	size;
// 	double	dist;

// 	cos2 = cos(start_x);
// 	sin2 = sin(start_x);
// 	ray_x = data->player->pos_x;
// 	ray_y = data->player->pos_y;
// 	while (!line_to_wall(ray_x, ray_y, data))
// 	{
// 		if (DD_MOD)
// 			mlx_pxl(data->img, ray_x, ray_y, 0xFF0000);
// 		ray_x += cos2;
// 		ray_y += sin2;
// 	}
	
// 	data->ray_dir_x = cos2;
// 	data->ray_dir_y = sin2;
// 	dist = squirt(ray_x, data->player->pos_x, ray_y, data->player->pos_y);
// 	/*printf("ray _y = %f\n", ray_y / S_SQUARE);
// 	printf("ray _x = %f\n", ray_x / S_SQUARE);*/

	
	
// 	data->distance = dist * cos(start_x - data->player->angle);
// 	data->wall_x = data->player->pos_y + data->distance * sin(start_x);
// 	/*if (get_wall_dir(data->ray_dir_x, data->ray_dir_y) > 2)
// 	else
// 		data->wall_x = data->player->pos_x + data->distance * cos(start_x);*/
// 	data->wall_x -= floor(data->wall_x);
// 	data->wall_dir = get_wall_dir(data->ray_dir_x, data->ray_dir_y);
// 	size = ((WIDTH / 2) * (128 / data->distance));
// 	if (!DD_MOD)
// 		ray(data, i, size, ray_x / 128, ray_y / 128);
// }

//2

// void	draw_ray(t_data *data, double start_x, int i)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	cos2;
// 	double	sin2;
// 	double	deltadist_x;
// 	double	deltadist_y;
// 	int		step_x;
// 	int		step_y;
// 	int		side;
// 	double	sidedist_x;
// 	double	sidedist_y;
// 	int		map_x;
// 	int		map_y;
// 	int		hit;
// 	double	walldist;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;
// 	int		tex_x;
	
// 	hit = 0;
// 	cos2 = cos(start_x);
// 	sin2 = sin(start_x);
// 	step_x = 0;
// 	step_y = 0;
// 	ray_x = data->player->pos_x;
// 	ray_y = data->player->pos_y;
// 	data->ray_dir_x = cos2;
// 	data->ray_dir_y = sin2;
// 	deltadist_x = fabs(1 / data->ray_dir_x);
// 	deltadist_y = fabs(1 / data->ray_dir_y);
// 	map_x = (int)ray_x;
// 	map_y = (int)ray_y;
// 	printf("map_y before = %f\n", ray_y);
// 	printf("map_x before = %f\n", ray_x);
// 	if (cos(start_x) < 0)
// 	{
// 		step_x = -1;
// 		sidedist_x = (ray_x - map_x) * deltadist_x;
// 	}
// 	else
// 	{
// 		step_x = 1;
// 		sidedist_x = (map_x + 1.0 - ray_x) * deltadist_x;
// 	}
// 	if (data->ray_dir_y < 0)
// 	{
// 		step_y = -1;
// 		sidedist_y = (ray_y - map_y) * deltadist_y;
// 	}
// 	else
// 	{
// 		step_x = 1;
// 		sidedist_y = (map_y + 1.0 - ray_y) * deltadist_y;
// 	}
// 	while (hit == 0)
// 	{
// 		if (sidedist_x < sidedist_y)
// 		{
// 			sidedist_x += sidedist_x;
// 			map_x += step_x;
// 			side = 0;
// 		}
// 		else
// 		{
// 			sidedist_y += sidedist_y;
// 			map_y += step_y;
// 			side = 1;
// 		}
// 		printf("step_y = %d\n", step_y);
// 		printf("step_x = %d\n", step_x);
// 		printf("sidedist_y = %f\n", sidedist_y);
// 		printf("sidedist_x = %f\n", sidedist_x);
// 		printf("map_y = %d\n", map_y);
// 		printf("map_x = %d\n", map_x);
// 		if (data->mapo[map_y][map_x] > 0)
// 			hit = 1;
// 	}
// 	if (side == 0)
// 		walldist = (map_x - ray_x + (1.0 - step_x) / 2) / data->ray_dir_x;
// 	else
// 		walldist = (map_y - ray_y + (1.0 - step_y) / 2) / data->ray_dir_y;
// 	line_height = (int)(HEIGHT / walldist);
// 	draw_start = -line_height / 2 + HEIGHT / 2;
// 	if (draw_start < 0)
// 	{
// 		draw_start = 0;
// 	}
// 	draw_end = line_height / 2 + HEIGHT / 2;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT -1;
// 	if (side == 0)
// 		data->wall_x = ray_y + walldist * data->ray_dir_y;
// 	else
// 		data->wall_x = ray_x + walldist * data->ray_dir_x;
// 	data->wall_x -= floor(data->wall_x);
// 	tex_x = (int)(data->wall_x * (double)(data->tex->tex_width));
// 	if (side == 0 && data->ray_dir_x > 0)
// 		tex_x = data->tex->tex_width - tex_x - 1;
// 	if (side == 1 && data->ray_dir_y < 0)
// 		tex_x = data->tex->tex_width - tex_x - 1;
// 	if (!DD_MOD)
// 		ray(data, i, line_height, ray_x, ray_y);
// }

// void	draw_ray(t_data *data, double start_x, int i)
// {
// 	double	ray_x;
// 	double	ray_y;
// 	double	cos2;
// 	double	sin2;
// 	double	deltadist_x;
// 	double	deltadist_y;
// 	double	sidedist_x;
// 	double	sidedist_y;
// 	int		map_x;
// 	int		map_y;
// 	int		hit;
// 	double	walldist;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;
// 	int		tex_x;
	
// 	hit = 0;
// 	cos2 = cos(start_x);
// 	sin2 = sin(start_x);
// 	ray_x = data->player->pos_x;
// 	ray_y = data->player->pos_y;
// 	data->ray_dir_x = cos2;
// 	data->ray_dir_y = sin2;
// 	map_x = (int)ray_x;
// 	map_y = (int)ray_y;
// 	if (data->ray_dir_x != 0)
// 		deltadist_x = fabs(1.0 / data->ray_dir_x);
// 	else
// 		deltadist_x = 0;
// 	if (data->ray_dir_y != 0)
// 		deltadist_y = fabs(1.0 / data->ray_dir_y);
// 	else
// 		deltadist_y = 0;
// 	if (data->ray_dir_x < 0)
// 	{
// 		data->step_x = -1;
// 		sidedist_x = (ray_x - map_x) * deltadist_x;
// 	}
// 	else
// 	{
// 		data->step_x = 1;
// 		sidedist_x = (map_x + 1.0 - ray_x) * deltadist_x;
// 	}
// 	if (data->ray_dir_y < 0)
// 	{
// 		data->step_y = -1;
// 		sidedist_y = (ray_y - map_y) * deltadist_y;
// 	}
// 	else
// 	{
// 		data->step_y = 1;
// 		sidedist_y = (map_y + 1.0 - ray_y) * deltadist_y;
// 	}
// 	while (hit == 0)
// 	{
// 		if (sidedist_x < sidedist_y)
// 		{
// 			sidedist_x += deltadist_x;
// 			map_x += data->step_x;
// 			data->side = 0;
// 		}
// 		else
// 		{
// 			sidedist_y += deltadist_y;
// 			map_y += data->step_y;
// 			data->side = 1;
// 		}
// 		if (data->mapo[map_y][map_x] == '1')
// 			hit = 1;
// 	}
// 	if (data->side == 0)
// 		walldist = (map_x - ray_x + (1.0 - data->step_x) / 2) / data->ray_dir_x;
// 	else
// 		walldist = (map_y - ray_y + (1.0 - data->step_y) / 2) / data->ray_dir_y;
// 	line_height = (int)(HEIGHT / walldist);
// 	draw_start = -line_height / 2 + HEIGHT / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + HEIGHT / 2;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT - 1;
// 	if (data->side == 0)
// 		data->wall_x = ray_y + walldist * data->ray_dir_y;
// 	else
// 		data->wall_x = ray_x + walldist * data->ray_dir_x;
// 	data->wall_x -= floor(data->wall_x);

// 	tex_x = (int)(data->wall_x * (double)data->tex->tex_width);
// 	if (data->side == 0 && data->ray_dir_x > 0)
// 		tex_x = data->tex->tex_width - tex_x - 1;
// 	if (data->side == 1 && data->ray_dir_y < 0)
// 		tex_x = data->tex->tex_width - tex_x - 1;
// 	if (!DD_MOD)
// 		ray(data, i, line_height, ray_x, ray_y);
// }

//bon
// void	draw_ray(t_data *data, double ray_dir_x, double ray_dir_y, int x)
// {
// 	double	pos_x;
// 	double	pos_y;
// 	int		map_x;
// 	int		map_y;
// 	double	delta_dist_x;
// 	double	delta_dist_y;
// 	int		step_x;
// 	int		step_y;
// 	double	side_dist_x;
// 	double	side_dist_y;
// 	int		hit;
// 	int		side;
// 	double	perpWallDist;
// 	int		line_height;
// 	int		draw_start;
// 	int		draw_end;

// 	pos_x = data->player->pos_x;
// 	pos_y = data->player->pos_y;
// 	map_x = (int)pos_x;
// 	map_y = (int)pos_y;
// 	hit = 0;

// 	if (ray_dir_x != 0)
// 		delta_dist_x = fabs(1.0 / ray_dir_x);
// 	else
// 		delta_dist_x = 1e30;
// 	if (ray_dir_y != 0)
// 		delta_dist_y = fabs(1.0 / ray_dir_y);
// 	else
// 		delta_dist_y = 1e30;

// 	if (ray_dir_x < 0)
// 	{
// 		step_x = -1;
// 		side_dist_x = (pos_x - map_x) * delta_dist_x;
// 	}
// 	else
// 	{
// 		step_x = 1;
// 		side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
// 	}
// 	if (ray_dir_y < 0)
// 	{
// 		step_y = -1;
// 		side_dist_y = (pos_y - map_y) * delta_dist_y;
// 	}
// 	else
// 	{
// 		step_y = 1;
// 		side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
// 	}

// 	while (hit == 0)
// 	{
// 		if (side_dist_x < side_dist_y)
// 		{
// 			side_dist_x += delta_dist_x;
// 			map_x += step_x;
// 			side = 0;
// 		}
// 		else
// 		{
// 			side_dist_y += delta_dist_y;
// 			map_y += step_y;
// 			side = 1;
// 		}
// 		if (map_y < 0 || !data->mapo[map_y] || map_x < 0
// 			|| map_x >= (int)strlen(data->mapo[map_y]))
// 			break;
// 		if (data->mapo[map_y][map_x] == '1')
// 			hit = 1;
// 	}

// 	if (side == 0)
// 		perpWallDist = (map_x - pos_x + (1 - step_x) / 2.0) / ray_dir_x;
// 	else
// 		perpWallDist = (map_y - pos_y + (1 - step_y) / 2.0) / ray_dir_y;

// 	data->ray_dir_x = ray_dir_x;
// 	data->ray_dir_y = ray_dir_y;
// 	data->side = side;
// 	data->step_x = step_x;
// 	data->step_y = step_y;
// 	data->distance = perpWallDist;

// 	if (side == 0)
// 		data->wall_x = pos_y + perpWallDist * ray_dir_y;
// 	else
// 		data->wall_x = pos_x + perpWallDist * ray_dir_x;
// 	data->wall_x -= floor(data->wall_x);

// 	data->wall_dir = get_wall_dir(data);

// 	line_height = (int)((double)HEIGHT / perpWallDist);
// 	draw_start = -line_height / 2 + HEIGHT / 2;
// 	if (draw_start < 0)
// 		draw_start = 0;
// 	draw_end = line_height / 2 + HEIGHT / 2;
// 	if (draw_end >= HEIGHT)
// 		draw_end = HEIGHT - 1;

// 	if (!DD_MOD)
// 		ray(data, x, line_height, pos_x, pos_y);
// }

#include "../includes/cub3d.h"

int	draw_player_loop(t_data *data)
{
	int		x;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	half_fov;
	double	plane_factor;

	x = 0;
	half_fov = PI / 6.0;
	player_intructs(data, data->player);
	mlx_draw(0, 0, data->img);
	if (DD_MOD)
	{
		draw_player(data->player->pos_x, data->player->pos_y, data);
		draw_map(data);
	}
	while (x < WIDTH)
	{
		camera_x = 2.0 * x / (double)WIDTH - 1.0;
		plane_factor = tan(half_fov);
		ray_dir_x = data->player->cos_angle + (-data->player->sin_angle) * plane_factor * camera_x;
		ray_dir_y = data->player->sin_angle + data->player->cos_angle * plane_factor * camera_x;

		draw_ray(data, ray_dir_x, ray_dir_y, x);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
	return (0);
}

void	draw_ray(t_data *data, double ray_dir_x, double ray_dir_y, int x)
{
	double	pos_x;
	double	pos_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	int		hit;
	int		side;
	double	perpWallDist;
	int		line_height;
	int		draw_start;
	int		draw_end;

	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	map_x = (int)pos_x;
	map_y = (int)pos_y;
	hit = 0;

	if (ray_dir_x != 0)
		delta_dist_x = fabs(1.0 / ray_dir_x);
	else
		delta_dist_x = 1e30;
	if (ray_dir_y != 0)
		delta_dist_y = fabs(1.0 / ray_dir_y);
	else
		delta_dist_y = 1e30;

	if (ray_dir_x < 0)
	{
		step_x = -1;
		side_dist_x = (pos_x - map_x) * delta_dist_x;
	}
	else
	{
		step_x = 1;
		side_dist_x = (map_x + 1.0 - pos_x) * delta_dist_x;
	}
	if (ray_dir_y < 0)
	{
		step_y = -1;
		side_dist_y = (pos_y - map_y) * delta_dist_y;
	}
	else
	{
		step_y = 1;
		side_dist_y = (map_y + 1.0 - pos_y) * delta_dist_y;
	}

	while (hit == 0)
	{
		if (side_dist_x < side_dist_y)
		{
			side_dist_x += delta_dist_x;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dist_y += delta_dist_y;
			map_y += step_y;
			side = 1;
		}
		if (map_y < 0 || !data->mapo[map_y] || map_x < 0
			|| map_x >= (int)strlen(data->mapo[map_y]))
			break;
		if (data->mapo[map_y][map_x] == '1')
			hit = 1;
	}

	if (side == 0)
		perpWallDist = (map_x - pos_x + (1 - step_x) / 2.0) / ray_dir_x;
	else
		perpWallDist = (map_y - pos_y + (1 - step_y) / 2.0) / ray_dir_y;

	data->ray_dir_x = ray_dir_x;
	data->ray_dir_y = ray_dir_y;
	data->side = side;
	data->step_x = step_x;
	data->step_y = step_y;
	data->distance = perpWallDist;

	if (side == 0)
		data->wall_x = pos_y + perpWallDist * ray_dir_y;
	else
		data->wall_x = pos_x + perpWallDist * ray_dir_x;
	data->wall_x -= floor(data->wall_x);

	data->wall_dir = get_wall_dir(data);

	line_height = (int)((double)HEIGHT / perpWallDist);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;

	if (!DD_MOD)
		ray(data, x, line_height, pos_x, pos_y);
}
