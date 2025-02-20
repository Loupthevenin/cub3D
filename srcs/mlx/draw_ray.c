/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:04 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/20 19:10:43 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_dir(t_game *game, double mapx, double mapy)
{
	if (game->player.ray_dir_x < 0) // gauche
	{
		game->player.stepx = -1;
		game->player.side_dist_x = (game->player.pos_x - mapx)
			* game->player.delta_dist_x;
	}
	else // droite
	{
		game->player.stepx = 1;
		game->player.side_dist_x = (mapx + 1.0 - game->player.pos_x)
			* game->player.delta_dist_x;
	}
	if (game->player.ray_dir_y < 0) // haut
	{
		game->player.stepy = -1;
		game->player.side_dist_y = (game->player.pos_y - mapy)
			* game->player.delta_dist_y;
	}
	else // bas
	{
		game->player.stepy = 1;
		game->player.side_dist_y = (mapy + 1.0 - game->player.pos_y)
			* game->player.delta_dist_y;
	}
}

void	draw_line(t_mlx *mlx, double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;
	int		sx;
	int		sy;
	double	err;
	int		e2;

	dx = fabs(x1 - x0);
	dy = fabs(y1 - y0);
	if (x0 < x1)
		sx = 1;
	else
		sx = -1;
	if (y0 < y1)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	while (1)
	{
		my_mlx_pixel_put(mlx, x0, y0, GREEN_PIXEL);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	init_player(t_game *game, int x, double *mapx, double *mapy)
{
	*mapx = (game->player.pos_x);
	*mapy = (game->player.pos_y);
	game->player.camerax = 2 * x / (double)WIDTH - 1;
	game->player.side_dist_x = 0;
	game->player.side_dist_y = 0;
	game->player.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->player.camerax;
	game->player.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->player.camerax;
	if (game->player.ray_dir_x == 0)
		game->player.ray_dir_x = 0.001;
	if (game->player.ray_dir_y == 0)
		game->player.ray_dir_y = 0.001;
	game->player.delta_dist_x = fabs(1 / game->player.ray_dir_x);
	game->player.delta_dist_y = fabs(1 / game->player.ray_dir_y);

}

void set_line(t_game *game, double mapx, double mapy)
{
	int	endX;
	int	endY;
	int	startX;
	int	startY;
	endX = (mapx * game->mlx.mini_width + game->mlx.mini_width / 2);
	endY = (mapy * game->mlx.mini_height + game->mlx.mini_height / 2);
    startX = (game->player.pos_x * game->mlx.mini_width );
    startY = (game->player.pos_y * game->mlx.mini_height);

    draw_line(&game->mlx, startX, startY, endX, endY);
}



int	get_side(t_game *game, double *mapx, double *mapy)
{
	if (game->player.side_dist_x < game->player.side_dist_y)
	{
		game->player.side_dist_x += game->player.delta_dist_x;
		*mapx += game->player.stepx;
		return (0);
	}
	else
	{
		game->player.side_dist_y += game->player.delta_dist_y;
		*mapy += game->player.stepy;
		return (1);
	}
	return (0);
}

static void	draw_wall(t_game *game, int x, int side, double mapx, double mapy)
{
	double	perp_wall_dist;
	int		line_height;
	int		draw_start;
	int		draw_end;
	
	int		color;
	int		y;

	if (side == 0)
		perp_wall_dist = (mapx - game->player.pos_x + (1 - game->player.stepx) / 2) / game->player.ray_dir_x;
	else
		perp_wall_dist = (mapy - game->player.pos_y + (1 - game->player.stepy) / 2) / game->player.ray_dir_y;
	if(perp_wall_dist <= 0)
		perp_wall_dist = 0.01;
	line_height = (int)(HEIGHT / perp_wall_dist);
	draw_start = (-line_height / 2) + (HEIGHT / 2);
	draw_end = (line_height / 2) + (HEIGHT / 2);
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	color = RED_PIXEL;
	y = draw_start;
	while (y <= draw_end)
	{
		my_mlx_pixel_put(&game->mlx, x, y, color);
		y++;
	}
}

void	cast_ray(t_game *game)
{
	int		x;
	double	mapx;
	double	mapy;
	int		touch;
	int		side;

	x = 0;
	while (x < WIDTH)
	{
		touch = 0;
		side = 0;
		init_player(game, x, &mapx, &mapy);
		get_dir(game, mapx, mapy);
		while (touch == 0)
		{
			side = get_side(game, &mapx, &mapy);
			if (game->config->map[(int)mapy][(int)mapx]
				&& game->config->map[(int)mapy][(int)mapx] == '1')
				touch = 1;
		}
		set_line(game, mapx, mapy);
		draw_wall(game, x, side, mapx, mapy);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
