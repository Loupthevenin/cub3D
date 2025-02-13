/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:45:04 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/13 13:02:33 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_tile(t_mlx *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	grid_color;

	start_x = (int)x * mlx->tileswidth;
	start_y = (int)y * mlx->tilesheight;
	end_x = (int)(x + 1) * mlx->tileswidth;
	end_y = (int)(y + 1) * mlx->tilesheight;
	grid_color = 0x808080;
	i = start_y;
	j = start_x;
	while (i < end_y)
	{
		j = start_x;
		while (j < end_x)
		{
			my_mlx_pixel_put(mlx, j, i, color);
			j++;
		}
		i++;
	}
	i = start_y; // Ligne verticale à droite
	while (i < end_y)
	{
		my_mlx_pixel_put(mlx, end_x - 1, i, grid_color);
		i++;
	}
	j = start_x;
	while (j < end_x)
	{ // Ligne horizontale en bas
		my_mlx_pixel_put(mlx, j, end_y - 1, grid_color);
		j++;
	}
	// mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
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
			if (game->config->map[y][x] == 'N' || game->config->map[y][x] == 'E'
				|| game->config->map[y][x] == 'W'
				|| game->config->map[y][x] == 'S')
			{
				draw_tile(&game->mlx, x, y, RED_PIXEL);
				game->player.pos_x = x;
				game->player.pos_y = y;
				game->player.ray_x = x;
				game->player.ray_y = y;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}
//draw_player()

// void	draw_ray(t_game *game)
// {

// }

void	draw(t_game *game)
{
	draw_map(game);
	// draw_ray(game);
}
