/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:14 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/17 13:47:19 by opdi-bia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	get_tiles_size(t_game *game)
{
	game->mlx.tileswidth = (float)WIDTH / (float)game->config->map_width;
	game->mlx.tilesheight = (float)HEIGHT / (float)game->config->map_height;
	if (game->mlx.tileswidth < game->mlx.tilesheight)
		game->mlx.tilesize = game->mlx.tileswidth;
	else
		game->mlx.tilesize = game->mlx.tilesheight;
}
