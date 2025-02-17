/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:23:59 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 12:26:52 by opdi-bia         ###   ########.fr       */
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

void	refresh_player(t_game *game, int x, int y)
{
	game->player.pos_x = x;
	game->player.pos_y = y;
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
