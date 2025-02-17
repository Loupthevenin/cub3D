/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:04 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 14:03:51 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_dir(t_game *game, float mapx, float mapy)
{
	if (game->player.ray_dir_x < 0) //gauche
	{
		game->player.stepx = -1;
		game->player.side_dist_x = (game->player.pos_x - mapx)
			* game->player.delta_dist_x;
	}
	else //droite
	{
		game->player.stepx = 1;
		game->player.side_dist_x = (mapx + 1.0 - game->player.pos_x)
			* game->player.delta_dist_x;
	}
	if (game->player.ray_dir_y < 0) //haut
	{
		game->player.stepy = -1;
		game->player.side_dist_y = (game->player.pos_y - mapy)
			* game->player.delta_dist_y;
	}
	else //bas
	{
		game->player.stepy = 1;
		game->player.side_dist_y = (mapy + 1.0 - game->player.pos_y)
			* game->player.delta_dist_y;
	}
}

void	draw_line(t_mlx *mlx, float x0, float y0, float x1, float y1)
{
	float	dx;
	float	dy;
	int		sx;
	int		sy;
	float	err;
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

void	init_player(t_game *game, int x, float *mapx, float *mapy)
{
	*mapx = (int)floor(game->player.pos_x);
	*mapy = (int)floor(game->player.pos_y);
	game->player.camerax = 2 * x / (float)WIDTH - 1;
	game->player.side_dist_x = 0;
	game->player.side_dist_y = 0;
	game->player.ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->player.camerax;
	game->player.ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->player.camerax;
	if (game->player.ray_dir_x == 0)
		game->player.ray_dir_x = INFINITY;
	if (game->player.ray_dir_y == 0)
		game->player.ray_dir_y = INFINITY;
	game->player.delta_dist_x = fabs(1 / game->player.ray_dir_x);
	game->player.delta_dist_y = fabs(1 / game->player.ray_dir_y);
}

void	set_line(t_game *game, float mapx, float mapy)
{
	int	endX;
	int	endY;
	int	startX;
	int	startY;

	endX = (mapx * game->mlx.tileswidth + game->mlx.tileswidth / 2);
	endY = (mapy * game->mlx.tilesheight + game->mlx.tilesheight / 2);
	startX = (game->player.pos_x * game->mlx.tileswidth + game->mlx.tileswidth
			/ 2);
	startY = (game->player.pos_y * game->mlx.tilesheight + game->mlx.tilesheight
			/ 2);
	draw_line(&game->mlx, startX, startY, endX, endY);
}

int	get_side(t_game *game, float *mapx, float *mapy)
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

void	cast_ray(t_game *game)
{
	int		x;
	float	mapx;
	float	mapy;
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
			get_side(game, &mapx, &mapy);
			if (game->config->map[(int)mapy][(int)mapx]
				&& game->config->map[(int)mapy][(int)mapx] == '1')
				touch = 1;
		}
		set_line(game, mapx, mapy);
		(void)side;
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
