/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:14 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/20 18:57:37 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_tiles_size(t_game *game)
{
	game->mlx.tilesize = 0;
	game->mlx.tileswidth = (double)WIDTH / (double)game->config->map_width;
	game->mlx.tilesheight = (double)HEIGHT / (double)game->config->map_height;
	if (game->mlx.tileswidth < game->mlx.tilesheight)
		game->mlx.tilesize = game->mlx.tileswidth;
	else
		game->mlx.tilesize = game->mlx.tilesheight;
	game->mlx.mini_width = (double)MINI_W / (double)game->config->map_width;
	game->mlx.mini_height = (double)MINI_H / (double)game->config->map_height;
	// if (game->mlx.mini_width < game->mlx.mini_height)
	// 	game->mlx.tilesize = game->mlx.mini_width;
	// else
	// 	game->mlx.tilesize = game->mlx.mini_height;
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}
