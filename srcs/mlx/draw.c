/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opdibia <opdibia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:53:07 by opdi-bia          #+#    #+#             */
/*   Updated: 2025/02/23 19:55:43 by opdibia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall(t_game *game, t_wall *wall, int side, int x)
{
	int			y;
	t_texture	*tex;
	int			tex_x;
	int			tex_y;
	double		wall_x;

	tex = get_texture(game, side);
	wall_x = get_wall_x(game, side, wall->perp_dist);
	tex_x = (int)(wall_x * (double)tex->width);
	if ((side == 0 && game->player.ray_dir_x > 0) || (side == 1
			&& game->player.ray_dir_y < 0))
		tex_x = tex->width - tex_x - 1;
	y = wall->draw_start;
	while (y <= wall->draw_end)
	{
		tex_y = (int)(((y - wall->draw_start)
					/ (double)(wall->draw_end - wall->draw_start))
				*tex->height);
		wall->color = *(int *)(tex->addr + (tex_y * tex->line_length + tex_x
					* (tex->bpp / 8)));
		my_mlx_pixel_put(&game->mlx, x, y, wall->color);
		y++;
	}
}

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
	// draw_map(game);
	cast_ray(game);
}
