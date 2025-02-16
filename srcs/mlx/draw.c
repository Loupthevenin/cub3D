/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:04 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/16 20:42:00 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_grid(t_mlx *mlx, int i, int j)
{
	i = mlx->start_y;
	while (i < mlx->end_y)
	{
		my_mlx_pixel_put(mlx, mlx->end_x - 1, i, GRID_COLOR);
		i++;
	}
	j = mlx->start_x;
	while (j < mlx->end_x)
	{
		my_mlx_pixel_put(mlx, j, mlx->end_y - 1, GRID_COLOR);
		j++;
	}
}

void	draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;

	mlx->start_x = (int)x * mlx->tileswidth;
	mlx->start_y = (int)y * mlx->tilesheight;
	mlx->end_x = (int)(x + 1) * mlx->tileswidth;
	mlx->end_y = (int)(y + 1) * mlx->tilesheight;
	i = mlx->start_y;
	j = mlx->start_x;
	while (i < mlx->end_y)
	{
		j = mlx->start_x;
		while (j < mlx->end_x)
		{
			my_mlx_pixel_put(mlx, j, i, color);
			j++;
		}
		i++;
	}
	draw_grid(mlx, i, j);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->config->map[y])
	{
		x = 0;
		while (game->config->map[y][x])
		{
			if (game->config->map[y][x] == '1')
				draw_tile(&game->mlx, x, y, WHITE_PIXEL);
			if (game->config->map[y][x] == '0')
				draw_tile(&game->mlx, x, y, BLACK_PIXEL);
			if (game->config->map[y][x] == game->config->player_dir)
			{
				draw_tile(&game->mlx, x, y, RED_PIXEL);
				refresh_player(game, x, y);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}

void	check_dir(t_game *game, t_player *player, int mapx, int mapy)
{
	if(player->ray_dir_x < 0)
	{
		player->stepx = -1;
		player->side_dist_x = (player->pos_x - mapx ) * player->delta_dist_x;
	}
	else
	{
		player->stepx = 1;
		player->side_dist_x = (mapx + 1.0 - player->pos_x) * player->delta_dist_x;
	}
	if(player->ray_dir_y < 0)
	{
		player->stepy = -1;
		player->side_dist_y = (player->pos_y - mapy ) * player->delta_dist_y;
	}
	else
	{
		player->stepy = 1;
		player->side_dist_y = (mapy + 1.0 - player->pos_y) * player->delta_dist_y;
	}
	(void)game;
}

void	draw_line(t_mlx *mlx, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0), dy = abs(y1 - y0);
	int sx;
	if(x0 < x1)
		sx = 1;
	else 
		sx = -1;

    int sy;
	if (y0 < y1) 
		sy = 1;
	else
		sy = -1;
    int err = dx - dy;
	int e2;
    while (1)
    {
        my_mlx_pixel_put(mlx, x0, y0, GREEN_PIXEL);
        if (x0 == x1 && y0 == y1) 
			break;
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

void	cast_ray(t_game *game, t_player *player)
{
	int x;
	x = 0;
	while(x < WIDTH)
	{
		int mapx;
		int mapy;
		int touch = 0;
		mapx = (int)game->player.pos_x;
		mapy = (int)game->player.pos_y;
		player->camerax = 2 * x / game->mlx.tileswidth -1;
		player->side_dist_x = 0;
		player->side_dist_y = 0;
		game->player.ray_dir_x = player->dir_x + player->plane_x * player->camerax;
		game->player.ray_dir_y = player->dir_y + player->plane_y * player->camerax;
		if(player->ray_dir_x == 0)
			player->ray_dir_x = INFINITY;
		if(player->ray_dir_y == 0)
			player->ray_dir_y = INFINITY;
		player->delta_dist_x = fabs(1/player->ray_dir_x);
		player->delta_dist_y = fabs(1/player->ray_dir_y);
		check_dir(game, &game->player, mapx, mapy);
		while(touch == 0)
		{
			if(player->side_dist_x < player->side_dist_y)
			{
				player->side_dist_x += player->delta_dist_x;
				mapx += player->stepx;
			}
			else
			{
				player->side_dist_y += player->delta_dist_y;
				mapy += player->stepy;
			}
			if (game->config->map[mapy][mapx]) 
				if (game->config->map[mapy][mapx] == '1') 
					touch = 1;
		}
		int startX = (player->pos_x * game->mlx.tileswidth + game->mlx.tileswidth / 2);
		int startY = (player->pos_y * game->mlx.tilesheight + game->mlx.tilesheight / 2);
		int endX = (mapx * game->mlx.tileswidth) ;  
		int endY = (mapy * game->mlx.tilesheight);
		draw_line(&game->mlx, startX, startY, endX, endY);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	
}

void	draw(t_game *game)
{
	draw_map(game);
	cast_ray(game, &game->player);
	
}




