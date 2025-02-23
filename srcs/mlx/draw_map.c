/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:23:59 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/23 20:09:17 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	double	i;
	double	j;

	mlx->start_x = (int)x * mlx->mini_width;
	mlx->start_y = (int)y * mlx->mini_height;
	mlx->end_x = (int)(x + 1) *mlx->mini_width;
	mlx->end_y = (int)(y + 1) *mlx->mini_height;
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

void	draw_player(t_game *game)
{
	int		center_x;
	int		center_y;
	int		radius;
	int		x;
	int		y;

	radius = game->mlx.tilesize / 10;
	y = -radius;
	x = -radius;
	center_x = (int)(game->player.pos_x * game->mlx.mini_width);
	center_y = (int)(game->player.pos_y * game->mlx.mini_height);
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
			{
				my_mlx_pixel_put(&game->mlx, center_x + x,
					center_y + y, RED_PIXEL);
			}
			x++;
		}
		y++;
	}
}

void	draw_map(t_game *game)
{
	double	x;
	double	y;

	y = 0;
	while (game->config->map[(int)y])
	{
		x = 0;
		while (game->config->map[(int)y][(int)x])
		{
			if (game->config->map[(int)y][(int)x] == '1')
				draw_tile(&game->mlx, x, y, WHITE_PIXEL);
			if (game->config->map[(int)y][(int)x] == '0'
				|| game->config->map[(int)y][(int)x]
					== game->config->player_dir)
				draw_tile(&game->mlx, x, y, BLACK_PIXEL);
			x++;
		}
		y++;
	}
	draw_player(game);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
