/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:04 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/13 19:01:29 by opdi-bia         ###   ########.fr       */
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

//draw_player()

void	check_dir(t_game *game, t_player *player)
{
	(void)game;

	if(player->ray_dir_x < 0)//si P regarde a droite
	{
		player->stepx = -1;
		player->side_dist_x = (player->pos_x - player->ray_x) * player->delta_dist_x;
	}
	else
	{
		player->stepx = 1;
		player->side_dist_x = (player->ray_x + 1 - player->pos_x) * player->delta_dist_x;
	}
	if(player->ray_dir_y < 0)//si P regarde en haut
	{
		player->stepy = -1;
		player->side_dist_y = (player->pos_y - player->ray_y) * player->delta_dist_y;
	}
	else
	{
		player->stepy = 1;
		player->side_dist_y = (player->ray_y + 1 - player->pos_y) * player->delta_dist_y;
	}
}

void	draw_line(t_game *game, t_player *player)
{
	int x0 = player->pos_x * game->mlx.tilesize;
	int y0 = player->pos_y * game->mlx.tilesize;
	int x1 = player->ray_x * game->mlx.tilesize;
	int y1 = player->ray_y * game->mlx.tilesize;
	int y = y0;

	int dx = x1 - x0;
	int dy = y1 - y0;
	int slope = 2 * dy;
	int error = -dx;
	int errorInc = -2 * dx;
	for (int x = x0 ; x <= x1; ++x)
	{
		my_mlx_pixel_put(&game->mlx, x, y, GREEN_PIXEL);
		error += slope;
		if (error >= 0)
		{
			y++;
			error += errorInc;
		}
	}
	// mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}


void	draw_ray(t_game *game, t_player *player)
{
	int touch;
	int side;

	touch = 0;
	player->side_dist_x = 0;
	player->side_dist_y = 0;
	side = 0;
	game->player.ray_x = game->player.pos_x;
	game->player.ray_y = game->player.pos_y;
	while(touch == 0)
	{
		check_dir(game, &game->player);
		if(player->side_dist_x < player->side_dist_y)
		{
			player->side_dist_x += player->delta_dist_x;
			player->ray_x += player->stepx;
			side = 0;
		}
		else
		{
			player->side_dist_y += player->delta_dist_y;
			player->ray_y += player->stepy;
			side = 1;
		}
		if(game->config->map[(int)floor(player->ray_y)][(int)floor(player->ray_x)])
			if(game->config->map[(int)floor(player->ray_y)][(int)floor(player->ray_x)] > 0)
				touch = 1;		
	}
	draw_line(game, &game->player);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
	(void)side;
}

void	draw(t_game *game)
{
	draw_map(game);
	draw_ray(game, &game->player);
	
}
