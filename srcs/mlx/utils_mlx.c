/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdi-bia <opdi-bia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:33:14 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/21 10:31:08 by ltheveni         ###   ########.fr       */
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

t_texture	*get_texture(t_game *game, int side)
{
	if (side == 0)
	{
		if (game->player.stepx == -1)
			return (&game->mlx.textures[3]);
		else
			return (&game->mlx.textures[2]);
	}
	else
	{
		if (game->player.stepy == -1)
			return (&game->mlx.textures[0]);
		else
			return (&game->mlx.textures[1]);
	}
}

double	get_wall_x(t_game *game, int side, double perp_wall_dist)
{
	double	wall_x;

	if (side == 0)
		wall_x = game->player.pos_y + perp_wall_dist * game->player.ray_dir_y;
	else
		wall_x = game->player.pos_x + perp_wall_dist * game->player.ray_dir_x;
	return (wall_x - floor(wall_x));
}
