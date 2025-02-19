/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:53:07 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/19 12:32:07 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			my_mlx_pixel_put(&game->mlx, x, y, BLACK_PIXEL);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img, 0, 0);
}

static void	draw_colors(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->mlx, x++, y,
					rgb_to_int(game->config->ceiling_color));
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_mlx_pixel_put(&game->mlx, x++, y,
					rgb_to_int(game->config->floor_color));
		y++;
	}
}

void	draw(t_game *game)
{
	draw_background(game);
	draw_colors(game);
	draw_map(game);
	cast_ray(game);
}
